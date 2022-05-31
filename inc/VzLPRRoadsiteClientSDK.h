//用于接入路侧停车相机的应用程序接口
#ifndef _VZ_LPR_ROAD_SITE_CLIENT_SDK_
#define _VZ_LPR_ROAD_SITE_CLIENT_SDK_
#include <inc/VzLPRClientSDKDefine.h>

#define MAX_BERTH_COUNT  16

typedef struct{
	int berth_number;				// 泊位编号
	int berth_state;                // 泊位状态 （1.入场 2.出场 0.无）
	char license[TH_LP_LEN];  	    // 车牌号码
} TH_RoadSiteBerth;

/**车牌识别结果信息*/
typedef struct 
{
	TH_PlateResult plate_result;
	TH_RECT berth_location;					 // 泊位图位置
	int berth_state;						 // 泊位图状态（1.入场 2.出场 0.无）
	int berth_number;						 // 泊位编号
	char berth_name[32];					 // 泊位名称
	TH_ImgInfo full_img[3];					 // 全图(3个时刻的图片)
	TH_ImgInfo clip_img;					 // 车牌图片
	TH_RoadSiteBerth berth[MAX_BERTH_COUNT]; // 泊位信息
	int berth_count;			             // 泊位个数
	char reserved1[128];		             // 预留数据
}TH_RoadSiteResult;

#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif


/**
*  @brief 路侧停车识别结果
*  @param [OUT] face_result 人脸结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_ROAD_SITE_RESULT_CALLBACK)(VzLPRClientHandle handle, TH_RoadSiteResult* face_result, void* pUserData);

/**
*  @brief 设置路侧停车识别结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRoadSiteResultCallBack(VzLPRClientHandle handle, VZLPRC_ROAD_SITE_RESULT_CALLBACK func, void* pUserData);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif

#endif
