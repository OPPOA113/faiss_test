/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <cstdio>
#include <cstdlib>

#include <faiss/IndexFlat.h>
#include <faiss/IndexIVFPQ.h>

#include "fstream"
#include <unistd.h>
#include "stdio.h"
#include <sys/dir.h>
#include <sys/stat.h>
#include "vector"
#include "string.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;

int getData(std::string dpath, std::string lpath, char**pDat, std::vector<std::string>&nLabels);
float getMold(const vector<float>& vec);
void noramalVector(vector<float>& vec);

using idx_t = faiss::Index::idx_t;

#define FEAT_DIM 512
#define CMP_NUM 50

int main() {

    printf("\nprocessing with faiss.....\n");
    float* basePtr= nullptr;
    float* queryPtr= nullptr;
    int nb,nq;
    vector<string>vBid;
    vector<string>vQid;
    int float_dims = FEAT_DIM;
    {
        ifstream label("../featCaffe/5k.txt");
        ifstream ofsFeatCos("../featCaffe/5k_cos.dat", ios::in | ios::binary);    // 2048
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
        ifstream ofsFeatCos("../featCaffe/query.dat", ios::in | ios::binary); // 2048
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
    printf("loaded nb:%zd\t nq:%zd\n",nb,nq);


    int d = FEAT_DIM;                            // dimension

    float *xb = basePtr;
    float *xq = queryPtr;

    int nlist = 100;//
    int k = 4;
    int m = 8;                             // bytes per vector
    faiss::IndexFlatIP quantizer(d);       // the other index
    faiss::IndexIVFPQ index(&quantizer, d, nlist, m, 8, faiss::MetricType::METRIC_INNER_PRODUCT);
    
    index.train(nb, xb);
    index.add(nb, xb);

    double eclapse_time=0;
    {       // search xq
        idx_t *I = new idx_t[nq*k];   // 返回命中id数组
        float *D = new float[nq*k];   // 返回的距离数组
        double start_t = cvGetTickCount();
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