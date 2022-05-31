//弃用或过时的sdk定义，不推荐使用
#ifndef _VZ_LPR_DISCARD_CLIENT_SDK_
#define _VZ_LPR_DISCARD_CLIENT_SDK_
#include <inc/VzLPRClientSDKDefine.h>

/**
*  @brief 弃用
*  @brief 开始发送本地音频文件的音频到远程，音频文件支持PCM编码的wav格式
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] strFileName 音频文件的绝对路径
*  @return 返回值：本地音频发送的句柄，需要保存起来，用于其他本地音频发送相关的操作
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStartByWaveFile(VzLPRClientHandle handle, const char *strFileName);


/**
*  @brief 弃用
*  @brief 停止发送本地音频
*  @param [IN] iTalkHandle VZC_TalkStart函数和VZC_TalkStartByWaveFile函数返回的本地音频发送的句柄
*  @return 返回值：返回值为0表示成功，返回其他值表示失败
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStop(int iTalkHandle);


typedef void(__STDCALL * VZLPRC_CallBackTalkData)(int iTalkHandle, const void *pDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser);

/**
*  @brief 弃用
*  @brief 开始发送本地话筒的音频到远程
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] fTalkDataCallBack 本地音频数据回调，可以为空
*  @param [IN] dwUser 本地音频数据回调的上下文
*  @return 返回值：本地音频发送的句柄，需要保存起来，用于其他本地音频发送相关的操作
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStart(VzLPRClientHandle handle, VZLPRC_CallBackTalkData fTalkDataCallBack, DWORD dwUser);



/**
*  @brief 弃用
*  @brief 接收并播放音频
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值：音频播放句柄，需要保存起来，用于其他音频输出的操作
*/
VZ_LPRC_API int __STDCALL VzLPRClient_OpenSound(VzLPRClientHandle handle);

/**
*  @brief 弃用
*  @brief 停止接收和播放音频
*  @param [IN] iAudioPlayHandle VZC_OpenSound函数返回的音频播放句柄
*  @return 返回值：返回值为0表示成功，返回其他值表示失败
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CloseSound(int iAudioPlayHandle);


//接收及获取音频
/**
*  @brief 弃用
*  @brief 接收并获取音频数据
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] bNeedEncode 获取的数据是否压缩，0为ACM，1为G711
*  @param [IN] fAudioDataCallBack 音频数据回调函数
*  @param [IN] dwUser 回调函数的上下文
*  @return 返回值：音频播放句柄，需要保存起来，用于其他音频输出的操作
*/
VZ_LPRC_API int __STDCALL VzLPRClient_OpenSoundData(VzLPRClientHandle handle, int bNeedEncode,
													VZLPRC_CallBackTalkData fAudioDataCallBack, DWORD dwUser);
/**
*  @brief 弃用
*  @brief 停止接收和获取音频数据
*  @param [IN] iSoundDataHandle VZC_OpenSoundData函数返回的音频数据句柄
*  @return 返回值：返回值为0表示成功，返回其他值表示失败
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CloseSoundData(int iSoundDataHandle);

/**
*  @brief 弃用
*  @brief 控制是否允许音频
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] bEnable 0为禁用音频播放和音频数据回调，1为允许
*  @return 返回值：返回值为0表示成功，返回其他值表示失败
*/
VZ_LPRC_API int __STDCALL VzLPRClient_AudioEnable(VzLPRClientHandle handle, int bEnable);


/**** VzLPRClientSDK V2扩展接口 主要提供x64平台使用(x86位平台可以使用新接口 但是x64平台一定要使用新接口)****/
/**
*  @brief 弃用
*  @brief 停止发送本地音频
*  @param [IN] iTalkHandle VZC_TalkStart函数和VZC_TalkStartByWaveFile函数返回的本地音频发送的句柄
*  @return 返回值：返回值为0表示成功，返回其他值表示失败
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStop_V2(int iTalkHandle);


typedef void(__STDCALL * VZLPRC_CallBackTalkData_V2)(int iTalkHandle, const void *pDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser);

/**
*  @brief 弃用
*  @brief 开始发送本地话筒的音频到远程
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] fTalkDataCallBack 本地音频数据回调，可以为空
*  @param [IN] pUser 本地音频数据回调的上下文
*  @return 返回值：本地音频发送的句柄，需要保存起来，用于其他本地音频发送相关的操作
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStart_V2(VzLPRClientHandle handle, VZLPRC_CallBackTalkData_V2 fTalkDataCallBack, void* pUser);

/**
*  @brief 弃用
*  @brief 接收并获取音频数据
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] bNeedEncode 获取的数据是否压缩，0为ACM，1为G711
*  @param [IN] fAudioDataCallBack 音频数据回调函数
*  @param [IN] pUser 回调函数的上下文
*  @return 返回值：音频播放句柄，需要保存起来，用于其他音频输出的操作
*/
VZ_LPRC_API int __STDCALL VzLPRClient_OpenSoundData_V2(VzLPRClientHandle handle, int bNeedEncode,
													   VZLPRC_CallBackTalkData_V2 fAudioDataCallBack, void* pUser);
/**
*  @brief 弃用
*  @brief 停止接收和获取音频数据
*  @param [IN] iSoundDataHandle VZC_OpenSoundData函数返回的音频数据句柄
*  @return 返回值：返回值为0表示成功，返回其他值表示失败
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CloseSoundData_V2(int iSoundDataHandle);

/**
*  @brief 弃用
*  @brief 设置人脸视频参数(此接口弃用，使用VzLPRClient_GetCameraConfig替代)
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] video_daynight 视频参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceVideoParam(VzLPRClientHandle handle, TH_FaceVideoDaynightParam* video_daynight);

/**
*  @brief 弃用
*  @brief 获取人脸视频参数(此接口弃用，使用VzLPRClient_SetCameraConfig替代)
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] video_daynight 视频参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceVideoParam(VzLPRClientHandle handle, TH_FaceVideoDaynightParam* video_daynight);

/**
*  @brief 弃用
*  @brief 获取人脸相机SD信息(此接口弃用，使用VzLPRClient_GetCameraConfig替代)
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] sd_info SD卡信息
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceSDInfo(VzLPRClientHandle handle, TH_FaceSDInfo* sd_info);

/**
*  @brief 弃用
*  @brief 格式化人脸相机SD卡(统一使用VzLPRClient_SDFormat格式化的接口)
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_LPRC_API int __STDCALL VzLPRClient_FaceFormatSd(VzLPRClientHandle handle);

#endif
