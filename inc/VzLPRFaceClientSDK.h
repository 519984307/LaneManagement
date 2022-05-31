//用于接入VZ的人脸抓拍相机的应用程序接口
#ifndef _VZ_LPR_FACE_CLIENT_SDK_
#define _VZ_LPR_FACE_CLIENT_SDK_
#include <inc/VzLPRClientSDKDefine.h>

#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif

/**
*  @brief 人脸抓拍结果
*  @param [OUT] face_result 人脸结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_FACE_RESULT_CALLBACK)(VzLPRClientHandle handle, TH_FaceResult* face_result, void* pUserData);

/**
*  @brief 设置人脸抓拍结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceResultCallBack(VzLPRClientHandle handle, VZLPRC_FACE_RESULT_CALLBACK func, void* pUserData);


/**
*  @brief 人数统计结果
*  @param [OUT] area1_num 区域一人数
*  @param [OUT] area2_num 区域二人数
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_FACE_COUNT_STAT_CALLBACK)(VzLPRClientHandle handle, int area1_num, int area2_num, void* pUserData);

/**
*  @brief 设置人数统计结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceCountStatCallBack(VzLPRClientHandle handle, VZLPRC_FACE_COUNT_STAT_CALLBACK func, void* pUserData);


/**
*  @brief 获取人脸识别区域的规则
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] face_rule_area 人脸识别规则
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceRuleArea(VzLPRClientHandle handle, TH_FaceRuleArea* face_rule_area);

/**
*  @brief 设置人脸识别区域的规则
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] face_rule_area 人脸识别规则
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceRuleArea(VzLPRClientHandle handle, TH_FaceRuleArea* face_rule_area);

/**
*  @brief 获取人脸屏蔽区域的规则
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] face_rule_area 人脸屏蔽区域
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceShieldArea(VzLPRClientHandle handle, TH_FaceShieldArea* face_shield_area);

/**
*  @brief 设置人脸屏蔽区域的规则
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] face_rule_area 人脸屏蔽区域
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceShieldArea(VzLPRClientHandle handle, TH_FaceShieldArea* face_shield_area);

/**
*  @brief 设置人脸IRCUT的状态
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] ircut 视频参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceIrcutParams(VzLPRClientHandle handle, int ircut);

/**
*  @brief 获取人脸IRCUT的状态
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] ircut 视频参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceIrcutParams(VzLPRClientHandle handle, int* ircut);

/**
*  @brief 区域流动人员统计数据清空
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_FaceResetCounter(VzLPRClientHandle handle);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif


#endif
