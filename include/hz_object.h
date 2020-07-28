

#ifndef  _hz_object_
#define  _hz_object_


#include "hz_objectTypedef.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ͨ������
//hz_getVersionInfo�汾��Ϣ��
//hz_setLicensePath����·������ȷ����1�����󷵻ش�����
extern "C" __declspec(dllexport) int     hz_getVersionInfo(char verInfo[256]);
extern "C" __declspec(dllexport) int     hz_setLicensePath(const char* licPath);
extern "C" __declspec(dllexport) int     hz_preLoadModel();



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//image base
extern "C" __declspec(dllexport)  void*  hz_objectI_init(hz_objectParameter_* hzParam);
extern "C" __declspec(dllexport)  int    hz_objectI_release(void* handle);

////////////////////
// ���ݳ��Ʒ���roi
extern "C" __declspec(dllexport)  int    hz_objectI_extractJPEG_Rect(const void* handle, char* pJpegBufCpu, int nJpegBuf, objectRect_ roi[HZ_MAX_ROI_NUM_], char* plateNme,
																hz_objectResult_  pResult[HZ_MAX_NUM_RESULT_], char pFeat[HZ_MAX_NUM_RESULT_][HZ_MAX_DIM_FEATURE_], int* nResult, int*  pWidth, int*  pHeight, char* pRectBuffJpeg[HZ_MAX_NUM_RESULT_], int nRectBuffJpeg[HZ_MAX_NUM_RESULT_]);
//extractJPEG
extern "C" __declspec(dllexport)  int    hz_objectI_extractJPEG(const void* handle, char* jpegBufCpu, int len, objectRect_ roi[HZ_MAX_ROI_NUM_], objectRect_ roe[HZ_MAX_ROE_NUM_], 
																hz_objectResult_  pResult[HZ_MAX_NUM_RESULT_], char pFeat[HZ_MAX_NUM_RESULT_][HZ_MAX_DIM_FEATURE_], int* nResult, int*  pWidth, int*  pHeight);
extern "C" __declspec(dllexport)  int    hz_objectI_extractJPEG_batch(const void* handle, char* jpegBufCpu[Max_Num_Batch_], int jpegBufLen[Max_Num_Batch_], int nBatch,
																hz_objectResult_  pResult[Max_Num_Batch_*HZ_MAX_NUM_RESULT_], char pFeat[Max_Num_Batch_*HZ_MAX_NUM_RESULT_][HZ_MAX_DIM_FEATURE_], int nResult[Max_Num_Batch_], int  pWidth[Max_Num_Batch_], int  pHeight[Max_Num_Batch_]);
////////////////////
//extractBGR
extern "C" __declspec(dllexport)  int    hz_objectI_extractBGR(const void* handle, char* bgrBufCpu, int width, int height, int widStep, objectRect_ roi[HZ_MAX_ROI_NUM_],objectRect_ roe[HZ_MAX_ROE_NUM_], 
																hz_objectResult_  pResult[HZ_MAX_NUM_RESULT_], char pFeat[HZ_MAX_NUM_RESULT_][HZ_MAX_DIM_FEATURE_], int* nResult);
extern "C" __declspec(dllexport)  int    hz_objectI_extractBGR_batch(const void* handle, char* bgrBufCpu[Max_Num_Batch_], int width[Max_Num_Batch_], int height[Max_Num_Batch_], int widStep[Max_Num_Batch_], int nBatch, 
																hz_objectResult_  pResult[Max_Num_Batch_*HZ_MAX_NUM_RESULT_], char pFeat[Max_Num_Batch_*HZ_MAX_NUM_RESULT_][HZ_MAX_DIM_FEATURE_], int nResult[Max_Num_Batch_]);


// v7.0�汾 face
extern "C" __declspec(dllexport)  void*  hz_faceI_init(hz_objectParameter_* hzParam);
extern "C" __declspec(dllexport)  int    hz_faceI_release(void* handle);
extern "C" __declspec(dllexport)  int    hz_faceI_extractJPEG(const void* handle, char* jpegBufCpu, int jpegBufLen, objectRect_ pObjectRoi[HZ_MAX_ROI_NUM_], hz_objectResult_  pResult[HZ_MAX_NUM_RESULT_], char pFaceFeat[HZ_MAX_NUM_RESULT_][HZ_MAX_DIM_FEATURE_F_], int *nResult, int *pWidth, int *pHeight, char* faceBufferCpu[HZ_MAX_NUM_RESULT_], int faceBufferLen[HZ_MAX_NUM_RESULT_]);
extern "C" __declspec(dllexport)  int    hz_faceI_extractBGR(const void* handle, char* bgrBufCpu, int width, int height, int widStep, objectRect_ pObjectRoi[HZ_MAX_ROI_NUM_], hz_objectResult_  pResult[HZ_MAX_NUM_RESULT_], char pFaceFeat[HZ_MAX_NUM_RESULT_][HZ_MAX_DIM_FEATURE_F_], int *nResult, char* faceBufferCpu[HZ_MAX_NUM_RESULT_], int faceBufferLen[HZ_MAX_NUM_RESULT_]);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ͼƬԤ���ܽӿ�
extern "C" __declspec(dllexport)  void*  hz_objectPretrial_init(hz_objectParameter_* hzParam);
extern "C" __declspec(dllexport)  int    hz_objectPretrial_release(void* handle);
extern "C" __declspec(dllexport)  int    hz_objectPretrial_extractBGR(const void* handle, char* bgrBufCpu, int width, int height, int widStep, hz_pretrialParameter *pInfoParam,
																	 hz_objectResult_ *outResult, int *nAccordResult, int *subAccordResult, float *pAccordResult);




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//video base
/////////////////////////////////////////////////////
//��������(new)
extern "C" __declspec(dllexport)  void*  hz_objectVD_init(hz_objectParameter_* hzParam, VideoCodec videoCodec);
extern "C" __declspec(dllexport)  int    hz_objectVD_reset(void* handle, VideoCodec videoCodec);
extern "C" __declspec(dllexport)  int    hz_objectVD_release(void* handle);
//extractAVPacket
//����10s�޷������ͼ���򷵻� -1
extern "C" __declspec(dllexport) int	 hz_objectVD_extractAVPacket(const void* handle, char* avPacketCpu, int Len, bool keyFrame, long long timeSt, objectRect_ roi[HZ_MAX_ROI_NUM_], objectRect_ roe[HZ_MAX_ROE_NUM_],
																	hz_objectResult_*  pResult, char pFeat[HZ_MAX_DIM_FEATURE_], char** pBgrBufCpu, int* pWidth, int* pHeight, int* pWidStep, int* nResult);
extern "C" __declspec(dllexport) int	 hz_objectVD_extractAVPacket_Rect(const void* handle, char* avPacketCpu, int Len, bool keyFrame, long long timeSt, objectRect_ roi[HZ_MAX_ROI_NUM_], objectRect_ roe[HZ_MAX_ROE_NUM_],
																	hz_objectResult_*  pResult, char pFeat[HZ_MAX_DIM_FEATURE_], int* nResult, char** pJpegBufCpu, int *nJpegBuf, int* pWidth, int* pHeight, int* pWidStep, char**pRectBuffJpeg, int *nRectBuffJpeg);


/////////////////////////////////////////////////////
//����������(old)
extern "C" __declspec(dllexport)  void*  hz_objectV_init(hz_objectParameter_* hzParam, int width, int height, int widStep);
extern "C" __declspec(dllexport)  int    hz_objectV_release(void* handle);
//extractBGR(cpu)
extern "C" __declspec(dllexport)  int    hz_objectV_extractBGR(const void* handle, char* bgrBufCpu, objectRect_ roi[HZ_MAX_ROI_NUM_], objectRect_ roe[HZ_MAX_ROE_NUM_],
															hz_objectResult_*  pResult, char pFeat[HZ_MAX_DIM_FEATURE_], char** pBgrBufCpu, int* nResult);
extern "C" __declspec(dllexport)  int    hz_objectV_extractBGR_Rect(const void* handle, char* bgrBufCpu, objectRect_ roi[HZ_MAX_ROI_NUM_], objectRect_ roe[HZ_MAX_ROE_NUM_],
															hz_objectResult_*  pResult, char pFeat[HZ_MAX_DIM_FEATURE_], int* nResult, char** pJpegBufCpu, int *nJpegBuf, char**pRectBuffJpeg, int *nRectBuffJpeg);
//��Ϊvcm���ýӿ�
extern "C" __declspec(dllexport)  int    hz_objectV_extractNV12Gpu(const void* handle, char* nv12BufGpu, long long timeSt, objectRect_ roi[HZ_MAX_ROI_NUM_], objectRect_ roe[HZ_MAX_ROE_NUM_],
																hz_objectResult_*  pResult, char pFeat[HZ_MAX_DIM_FEATURE_], char** pBgrBufCpu, int* nResult);
//��ʾdemo���ýӿ�
extern "C" __declspec(dllexport)  int    hz_objectV_getFrameResult(const void* handle, hz_objectResult_  pResult[HZ_MAX_NUM_RESULT_], long long chann[HZ_MAX_NUM_RESULT_], int* nResult);




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////
/*
//֧��roi����
// hzRtParam==NULL��Ĭ�ϲ��������nNear==64
// pSrcFeat������object�������꣬localΪ�ֲ�����(���糵��)
//��object==NULL || local==NULL��ʱֻ����������
//��object!=NULL && local!=NULL���������������ģ�ͬʱ���Ǿֲ����������
extern "C" __declspec(dllexport) void*   hz_objectRetrival_init2(hz_objectRetrivalParameter_* hzRtParam, char pSrcFeat[HZ_MAX_DIM_FEATURE_], objectRect_* object, objectRect_ local[HZ_MAX_LOCAL_NUM_], int nLOcal);
extern "C" __declspec(dllexport) int     hz_objectRetrival_release2(void* handle);
extern "C" __declspec(dllexport) int     hz_objectRetrival_compare2(const void* handle, char pDstFeat[HZ_MAX_DIM_FEATURE_], float* pProb);


// �����ȶԽӿ�
// pBatchFeat���복����������pBatchIdx������id��nBatchFeat���복��������
// hz_objectRetrival_push֧�ֵ��ӣ���ε��ã�
// �������ε���nBatchFeat [1k  32k]
extern "C" __declspec(dllexport) int     hz_objectRetrival_pushBack2(const void* handle, char* pBatchFeat, char* pBatchIdx, int nBatchFeat);
// pSortIdx������nSort�������Ƶĳ���idx��prob��nSort<=nNear
extern "C" __declspec(dllexport) int     hz_objectRetrival_getSort2(const void* handle, char* pSortIdx, float* pSortProb, int* nSort);


////////////////////////////////////////////////
//��֧��roi����
//����Ҫ��ʼ����������ǲ�֧�־ֲ���������
//pSearchFeat��������pBaseFeat�׿⣬pSimilarity���ƶ�
extern "C" __declspec(dllexport) int     hz_objectRetrival_compare2_11(char* pSearchFeat, char* pBaseFeat, int nFeatLen, float* pSimilarity);

//ppSearchFeat���������б�ppBaseFeat�׿��б�threshold������ֵ��nLimit����ǰN�ࡢpSimilarity[nSearchFeat*nLimit] pIndex[nSearchFeat*nLimit], pNumber[nSearchFeat]
extern "C" __declspec(dllexport) int     hz_objectRetrival_compare2_mn(char** ppSearchFeat, int nSearchFeat, char** ppBaseFeat, int nBaseFeat, int nFeatLen, float threshold, int nLimit, float* pSimilarity, int* pIndex, int* pNumber);
*/
#endif // !_hz_object_
