
#ifndef _hz_objectReTrival_
#define _hz_objectReTrival_

#include "hz_objectTypedef.h"



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//֧��roi����
// hzRtParam==NULL��Ĭ�ϲ��������nNear==64
// pSearchFeat����, dSearchFeat����ά�ȣ� object�������꣬localΪ�ֲ�����(���糵��)
//��object==NULL || local==NULL��ʱֻ����������
//��object!=NULL && local!=NULL���������������ģ�ͬʱ���Ǿֲ����������
extern "C" __declspec(dllexport) void*   hz_objectRetrival_init(hz_objectRetrivalParameter_* hzRtParam, char pSrcFeat[HZ_MAX_DIM_FEATURE_], objectRect_* object, objectRect_ local[HZ_MAX_LOCAL_NUM_], int nLOcal);
extern "C" __declspec(dllexport) int     hz_objectRetrival_release(void* handle);
extern "C" __declspec(dllexport) int     hz_objectRetrival_compare(const void* handle, char pSrcFeat[HZ_MAX_DIM_FEATURE_], char pDstFeat[HZ_MAX_DIM_FEATURE_], float* pProb);

// �����ȶԽӿ�
// pBatchFeat���복����������pBatchIdx������id��nBatchFeat���복��������
// hz_objectRetrival_push֧�ֵ��ӣ���ε��ã�
// �������ε���nBatchFeat [1k  32k]
extern "C" __declspec(dllexport) int  hz_objectRetrival_pushBack(const void* handle, char* pBatchFeat, char* pBatchIdx, int nBatchFeat);
// pSortIdx������nSort�������Ƶĳ���idx��prob��nSort<=nNear
extern "C" __declspec(dllexport) int  hz_objectRetrival_getSort(const void* handle, char* pSortIdx, float* pSortProb, int* nSort);



////////////////////////////////////////////////
//��֧��roi����
//����Ҫ��ʼ����������ǲ�֧�־ֲ���������
//pSearchFeat��������pBaseFeat�׿⣬pSimilarity���ƶ�
extern "C" __declspec(dllexport) int  hz_objectRetrival_compare_11(char* pSearchFeat, char* pBaseFeat, int nFeatLen, float* pSimilarity);

//ppSearchFeat���������б�ppBaseFeat�׿��б�threshold������ֵ��nLimit����ǰN�ࡢpSimilarity[nSearchFeat*nLimit] pIndex[nSearchFeat*nLimit], pNumber[nSearchFeat]
extern "C" __declspec(dllexport) int  hz_objectRetrival_compare_mn(char** ppSearchFeat, int nSearchFeat, char** ppBaseFeat, int nBaseFeat, int nFeatLen, float threshold, int nLimit, float* pSimilarity, int* pIndex, int* pNumber);



#endif
