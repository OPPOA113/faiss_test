
#ifndef _hz_objectReTrival_
#define _hz_objectReTrival_

#include "hz_objectTypedef.h"



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//支持roi区域
// hzRtParam==NULL，默认参数，输出nNear==64
// pSearchFeat特征, dSearchFeat特征维度， object车辆坐标，local为局部坐标(例如车标)
//（object==NULL || local==NULL）时只做车辆搜索
//（object!=NULL && local!=NULL）在做车辆搜索的，同时考虑局部区域的特征
extern "C" __declspec(dllexport) void*   hz_objectRetrival_init(hz_objectRetrivalParameter_* hzRtParam, char pSrcFeat[HZ_MAX_DIM_FEATURE_], objectRect_* object, objectRect_ local[HZ_MAX_LOCAL_NUM_], int nLOcal);
extern "C" __declspec(dllexport) int     hz_objectRetrival_release(void* handle);
extern "C" __declspec(dllexport) int     hz_objectRetrival_compare(const void* handle, char pSrcFeat[HZ_MAX_DIM_FEATURE_], char pDstFeat[HZ_MAX_DIM_FEATURE_], float* pProb);

// 批量比对接口
// pBatchFeat输入车辆的特征，pBatchIdx车辆的id，nBatchFeat输入车辆的数量
// hz_objectRetrival_push支持叠加（多次调用）
// 建议批次导入nBatchFeat [1k  32k]
extern "C" __declspec(dllexport) int  hz_objectRetrival_pushBack(const void* handle, char* pBatchFeat, char* pBatchIdx, int nBatchFeat);
// pSortIdx，返回nSort个最相似的车辆idx和prob，nSort<=nNear
extern "C" __declspec(dllexport) int  hz_objectRetrival_getSort(const void* handle, char* pSortIdx, float* pSortProb, int* nSort);



////////////////////////////////////////////////
//不支持roi区域
//不需要初始化句柄，但是不支持局部区域搜索
//pSearchFeat搜索对象、pBaseFeat底库，pSimilarity相似度
extern "C" __declspec(dllexport) int  hz_objectRetrival_compare_11(char* pSearchFeat, char* pBaseFeat, int nFeatLen, float* pSimilarity);

//ppSearchFeat搜索对象列表、ppBaseFeat底库列表、threshold过滤阈值、nLimit返回前N类、pSimilarity[nSearchFeat*nLimit] pIndex[nSearchFeat*nLimit], pNumber[nSearchFeat]
extern "C" __declspec(dllexport) int  hz_objectRetrival_compare_mn(char** ppSearchFeat, int nSearchFeat, char** ppBaseFeat, int nBaseFeat, int nFeatLen, float threshold, int nLimit, float* pSimilarity, int* pIndex, int* pNumber);



#endif
