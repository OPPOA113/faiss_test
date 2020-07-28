#include <unistd.h>
#include "stdio.h"

#include "iostream"
#include <sys/dir.h>
#include <sys/stat.h>
#include "fstream"
#include "vector"
#include "string.h"
#include "assert.h"

#include "faiss/IndexFlat.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;

#include "hz_objectRetrival.h"

#define FEAT_DIM HZ_MAX_DIM_FEATURE_F_

int calRecall(int *nNum, int* nIdex, float* pProb, int nQuery, int nLimit, std::vector<std::string>&baseLabel, std::vector<std::string>&queryLabel, float*wrongRate, float*recall);
int getData(std::string dpath, std::string lpath, char**pDat, std::vector<std::string>&nLabels);
float getMold(const vector<float>& vec);
void noramalVector(vector<float>& vec);

using idx_t = faiss::Index::idx_t;

// E:\coding\faissTset\feat\Base.dat E:\coding\faissTset\feat\BaseLabel.txt E:\coding\faissTset\feat\Query.dat E:\coding\faissTset\feat\QueryLabel.txt

int main(int argc, char**argv)
{
	std::string basePath = argv[1];
	std::string baseLabelTxt = argv[2];
	std::string queryPath = argv[3];
	std::string queryLabelTxt = argv[4];

    std::vector<std::string>baseID;
	char* baseFeat=NULL;
	int status = getData(basePath, baseLabelTxt, &baseFeat, baseID);
	if (status < 0){ printf("can not load baseFeat\n"); return 0; }
	int nBase = baseID.size();

    std::vector<std::string>queryID;
	char* queryFeat = NULL;
	status = getData(queryPath, queryLabelTxt, &queryFeat, queryID);
	if (status < 0){ printf("can not load queryFeat\n"); return 0; }
	int nQuery = queryID.size();

	printf("load success :nBase:%d,nQuery:%d \n",nBase,nQuery);
	//
    std::vector<char*>vBaseFeat;
    std::vector<char*>vQueryFeat;
	for (int i = 0; i < nBase; i++)
	{
		vBaseFeat.push_back(baseFeat + i*HZ_MAX_DIM_FEATURE_F_);
	}
	for (int i = 0; i < nQuery; i++)
	{
		vQueryFeat.push_back(queryFeat + i*HZ_MAX_DIM_FEATURE_F_);
	}

	int nlimit = nBase;
	float thresh = 0.55;

	float* pProb = new float[nlimit*nQuery];
	int* nIdx = new int[nlimit*nQuery];
	int* nNum = new int[nQuery];
	int CMP_NUM = 50;
	double start_t = cvGetTickCount();
	for (int n = 0; n < CMP_NUM; n++)
	{
		hz_objectRetrival_compare_mn((char **)&vQueryFeat[0], nQuery, (char **)&vBaseFeat[0], nBase, HZ_MAX_DIM_FEATURE_F_, thresh, nlimit, pProb, nIdx, nNum);
	}
	double eclapse_time = cvGetTickCount() - start_t;

	float wrongRate;
	float recall;
	calRecall(nNum, nIdx, pProb, nQuery, nlimit, baseID, queryID, &wrongRate, &recall);
	
	printf("recall:%.4f\t wrongRate:%.4f\n", recall, wrongRate);
	printf("nBase:%d,nQuery:%d,CMP_NUM:%d, eclapse_time:%.4f ms\n", nBase, nQuery, CMP_NUM, float(eclapse_time / cvGetTickFrequency() / 1000) / CMP_NUM * 1.0);
	delete[] pProb;
	delete[] nIdx;
	delete[] nNum;

    /////////////////////////-faiss-/////////////////////////////////
    // ../feat/Base.dat ../feat/BaseLabel.txt ../feat/Query.dat ../feat/QueryLabel.txt
    printf("\nprocessing with faiss.....\n");
    float* basePtr= nullptr;
    float* queryPtr= nullptr;
    int nb,nq;
    vector<string>vBid;
    vector<string>vQid;
    int float_dims = HZ_MAX_DIM_FEATURE_F_ / 4;
    {
        ifstream label("../featCaffe/5k.txt");
        ifstream ofsFeatCos("../featCaffe/5k_cos256.dat", ios::in | ios::binary);    // 2048
//        ifstream label("../feat/BaseLabel.txt");
//        ifstream ofsFeatCos("../feat/Base.dat", ios::in | ios::binary);             // 1024
        int i = 0;
        string line;
        while (getline(label, line))
        {
            vBid.push_back(line);
            i++;
        }
        nb = i;
        basePtr = (float*)malloc(nb*float_dims*sizeof(float));
        float *pt=basePtr;
        for (int d = 0; d < nb;d++)
        {
            vector<float> featVector(float_dims);
            float vLenght;
            ofsFeatCos.read((char*)&vLenght, 1 * sizeof(float));
            ofsFeatCos.read((char*)featVector.data(), float_dims * sizeof(float));
            noramalVector(featVector);
            mempcpy((char*)pt,(char*)featVector.data(),float_dims*sizeof(float));
            pt += float_dims;
        }
        label.close();
        ofsFeatCos.close();
    }
    {
        ifstream label("../featCaffe/queryLabel.txt");
        ifstream ofsFeatCos("../featCaffe/query256.dat", ios::in | ios::binary); // 2048
//        ifstream label("../feat/QueryLabel.txt");
//        ifstream ofsFeatCos("../feat/Query.dat", ios::in | ios::binary);        // 1024
        int i = 0;
        string line;
        while (getline(label, line))
        {
            vQid.push_back(line);
            i++;
        }
        nq = i;
        queryPtr = (float*)malloc(nb*float_dims*sizeof(float));
        float *pt=queryPtr;
        for (int d = 0; d < nq;d++)		// 从底库读入特征和模长，以及汉明特征
        {
            vector<float> featVector(float_dims);
            ofsFeatCos.read((char*)featVector.data(), float_dims * sizeof(float));
            noramalVector(featVector);
            mempcpy((char*)pt,(char*)featVector.data(),float_dims*sizeof(float));
            pt += float_dims;
        }
        label.close();
        ofsFeatCos.close();
    }

    vector<pair<int,int>>query2Base;        // make query label in base
    for(int n=0;n<nq;n++)
    {
        string qName = vQid[n];
        for(int b=0;b<nb;b++)
        {
            string bName = vBid[b];
            if ( (strstr(bName.c_str(), qName.c_str()) != NULL) && (b > 9520))
            {
                query2Base.push_back(make_pair(n,b));
                break;
            }
        }
    }
    assert(query2Base.size()==nq);

    faiss::IndexFlatIP index(float_dims);           // call constructor
    printf("is_trained = %s\n", index.is_trained ? "true" : "false");
    index.add(nb, basePtr);                     // add vectors to the index
    printf("ntotal = %zd\n", index.ntotal);

    int k = 64;//nb;  //10;// 每个查询返回个数 nlimit
    {       // search xq
        idx_t *I = new idx_t[nq*k];   // 返回命中id数组
        float *D = new float[nq*k];   // 返回的距离数组
        start_t = cvGetTickCount();
        for (int m = 0; m < CMP_NUM; ++m) {
            index.search(nq, queryPtr, k, D, I);
        }
        eclapse_time = cvGetTickCount() - start_t;

        int rights = 0;
        int wrongs = 0;
        for (int l = 0; l < nq; ++l)
        {
            for (int j = 0; j < /* 1 */ k; j++)
            {
                int reid = I[l * k + j];
                float prob = D[l * k + j];
                if(query2Base[l].second == reid && prob > 0.35)    // recognise true
                {
                    rights++;
                }
                else if(prob > 0.35)
                    wrongs++;
            }
        }
        printf("faiss=nq:%zd,rights:%zd,wrong:%zd,recall:%7g,xujing:%7g \n",nq,rights,wrongs,1.0*rights/nq,1.0*wrongs/nq);

        delete [] I;
        delete [] D;
    }
    printf("eclapse_time:%7g \n",float(eclapse_time / cvGetTickFrequency() / 1000) / CMP_NUM * 1.0);

    /////////////////////////////////////////////////////////////////
	if (baseFeat)
	{
        std::free(baseFeat);
	}
	if (queryFeat)
	{
        std::free(queryFeat);
	}
    if (basePtr)
    {
        std::free(basePtr);
    }
    if (queryPtr)
    {
        std::free(queryPtr);
    }
	//getchar();
	return 0;
}

int calRecall(int *nNum,int* nIdex,float* pProb,int nQuery,int nLimit,std::vector<std::string>&baseLabel,std::vector<std::string>&queryLabel,float*wrongRate,float*recall)
{
	int re_right = 0;	//
	int re_wrong = 0;
	for (int i = 0; i < nQuery; i++)
	{

		bool isRING = false;
		if (nNum[i]>0)
		{
			for (int n = 0; n < 1/*pNum[i]*/; n++)
			{
				int idx = nIdex[nLimit*i + n];		//
                std::string sName = queryLabel[i];
                std::string bName = baseLabel[idx];
				if (strstr(bName.c_str(), sName.c_str()) != NULL)	//
				//if (strcmp(bName.c_str(), sName.c_str()) == 0)	//
				{
					isRING = true;
				}
			}

			if (isRING)
			{
				re_wrong += (nNum[i] - 1);
			}
			else
			{
				re_wrong += nNum[i];
			}
			//re_wrong += (pNum[i] - 1);
		}
		if (isRING)re_right++;

	}
	*recall = 100.0 * re_right / nQuery;
	*wrongRate = 100.0 * re_wrong / nQuery;

	return 0;
}


int getData(std::string dpath,std::string lpath,char**pDat,std::vector<std::string>&nLabels)
{
	if (access(dpath.c_str(), 0) != 0 && access(lpath.c_str(), 0) != 0)
	{
		printf("not exit path:%s,%s\n", dpath.c_str(), lpath.c_str());
		return -1;
	}

    std::ifstream label(lpath.c_str());
	int i = 0;
    std::string line;
	while (getline(label, line))
	{
		nLabels.push_back(line);
		i++;
	}
	int numBase = i;

	FILE *fp = fopen(dpath.c_str(), "rb");
	fseek(fp, 0, SEEK_END);
	int feaSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	assert(numBase == (feaSize / FEAT_DIM));

	char* baseFeat = new char[numBase*FEAT_DIM];
	fread(baseFeat, 1, feaSize, fp);
	fclose(fp);

	*pDat = baseFeat;

	return 0;
}
float getMold(const vector<float>& vec)
{
    int n = vec.size();
    float sum = 0.0;
    for (int i = 0; i < n; ++i)
        sum += vec[i] * vec[i];
    return sqrt(sum);
}
void noramalVector(vector<float>& vec)
{
    float lenght = getMold(vec);
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = vec[i] / lenght;
    }
}