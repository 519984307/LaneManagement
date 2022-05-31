//用于接入VZ的车牌识别设备（包括智能识别一体机和智能识别终端等）的应用程序接口
#ifndef _VZ_LPRC_PARK_SDK_H_
#define _VZ_LPRC_PARK_SDK_H_
#include <inc/VzLPRClientSDKDefine.h>
#include <inc/VzClientSDK_ParkDefine.h>

#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif


/**
*  @brief 全局初始化
*  @return 0表示成功，-1表示失败
*  @note 在所有接口调用之前调用
*  @ingroup group_global
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SetUp();

/**
*  @brief 全局释放
*  @note 在程序结束时调用，释放SDK的资源
*  @ingroup group_global
*/
VZ_LPRC_API void __STDCALL VzPGS_Sdk_CleanUp();


/**
*  @brief 打开一个设备
*  @param  [IN] pStrIP 设备的IP地址
*  @param  [IN] wPort 设备的端口号
*  @param  [IN] pStrUserName 访问设备所需用户名
*  @param  [IN] pStrPassword 访问设备所需密码
*  @return 返回设备的操作句柄，当打开失败时，返回0
*  @ingroup group_device
*/
VZ_LPRC_API VzLPRClientHandle  __STDCALL VzPGS_Sdk_Open(const char* pStrIP, unsigned int wPort, const char* pStrUserName, const char* pStrPassword);

/**
*  @brief 关闭一个设备
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @return 0表示成功，-1表示失败
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL  VzPGS_Sdk_Close(VzLPRClientHandle handle);


/**
*  @brief 设置串口参数
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] sp 串口参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SetSerialParam(VzLPRClientHandle handle, const VZ_SERIAL_PARAMETER * sp);

/**
*  @brief 获取串口参数
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] sp 串口参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_GetSerialParam(VzLPRClientHandle handle, VZ_SERIAL_PARAMETER * sp);

/**
*  @brief 发送串口数据
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] buffer 数据缓冲区
*  @param  [IN] bufferLen 数据缓冲区长度
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SendSerialData(VzLPRClientHandle handle, const char *buffer, unsigned int bufferLen);


/**
*  @brief 设置设备时间
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt 设备时间参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDeviceTime(VzLPRClientHandle handle, const VZ_DEVICE_TIME * dt);

/**
*  @brief 获取设备时间
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt 设备时间参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetDeviceTime(VzLPRClientHandle handle, VZ_DEVICE_TIME * dt);

/**
*  @brief 设置OSd配置
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt OSD参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetOsdCfg(VzLPRClientHandle handle, const VZ_OSD_CFG * osd);

/**
*  @brief 获取OSD配置
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt osd参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetOsdCfg(VzLPRClientHandle handle, VZ_OSD_CFG * osd);

/**
*  @brief 设置视频参数
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt 视频参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetVideoParam(VzLPRClientHandle handle, const VZ_VIDEO_PARAMETER * video_param);

/**
*  @brief 获取视频参数
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt 视频参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetVideoParam(VzLPRClientHandle handle, VZ_VIDEO_PARAMETER * video_param);

/**
*  @brief 设置http服务器参数
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt http参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetHttpParam(VzLPRClientHandle handle, const VZ_HTTP_SERVER_PARAMETER * http_param);

/**
*  @brief 获取http服务器参数
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt http参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetHttpParam(VzLPRClientHandle handle, VZ_HTTP_SERVER_PARAMETER * http_param);

/**
*  @brief  获取设备版本
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] dt 设备参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetDeviceVersion(VzLPRClientHandle handle, VZ_DEVICE_VERSION * version);

#if defined(WIN32) || defined(_WIN64)
/**
*  @brief 播放实时视频
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] hWnd 窗口的句柄
*  @return 返回播放的句柄，-1表示失败
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_StartRealPlay(VzLPRClientHandle handle, void *hWnd);

/**
*  @brief 停止播放指定的播放句柄
*  @param  [IN] nPlayHandle 播放的句柄
*  @return 0表示成功，-1表示失败
*  @note   可用来停止播放来自函数VzPGS_Sdk_StartRealPlay的播放句柄
*  @note   停止播放以后，该播放句柄就失效了
*  @ingroup group_device
*/
VZ_LPRC_API void __STDCALL VzPGS_Sdk_StopRealPlay(int playhandle);
#endif

/**
*  @brief 发送软件触发信号
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int   __STDCALL VzPGS_Sdk_ForceTrigger(VzLPRClientHandle handle);


/**
*  @brief 获取截图
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] buffer  图像缓冲区
*  @param  [IN] buffLen  缓冲区大小
*  @param  [IN] writeLen   写入的长度
*  @return 0表示成功，-1表示失败
*  @note   获取的图片数据是jpg文件
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_GetSnapImage(VzLPRClientHandle handle, char *buffer, unsigned int buffLen, unsigned int *writeLen);

/**
*  @brief  搜索设备信息的回调
*  @param  [OUT] device   设备信息
*  @param  [OUT] userdata 用户数据
*  @return 
*  @note
*  @ingroup group_device
*/
typedef void(__STDCALL *VZPGS_SEARCH_DEVICE_CALLBACK)(VZ_DEVICE_RELATION * device, void * userdata);

/**
*  @brief  搜索设备通过回调
*  @param  [IN] callback 找寻设备的回调
*  @param  [IN] userdata 用户数据
*  @param  [IN]  mSecWait 等待搜索时间,单位,ms,不能小于200ms
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API void __STDCALL    VzPGS_Sdk_SearchDevice(VZPGS_SEARCH_DEVICE_CALLBACK callback, void * userdata, unsigned int mSecWait);


/** 
*  @brief  获取车牌识别结果
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [OUT] parkingInfo 车牌结果信息
*  @param  [IN] mSecWait   等待毫秒时间 
*  @return 0表示成功，-1表示失败
*  @note   获取时，如果没有识别信息，那么就会出错
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_GetPlateResult(VzLPRClientHandle handle, VZ_PARKING_INFO * parkingInfo, unsigned int mSecWait);


/**
*  @brief  搜索车牌识别信息的回调
*  @param  [OUT] handle    由VzPGS_Sdk_Open函数获得的句柄
*  @param  [OUT] parkingInfo   总停车位信息
*  @param  [OUT] userdata 用户数据
*  @return 
*  @note
*  @ingroup group_device
*/
typedef void(__STDCALL *VZPGS_SEARCH_PALTE_CALLBACK)(VzLPRClientHandle handle,VZ_PARKING_INFO* parkingInfo,void * userdata);

/** 
*  @brief  搜索车牌识别结果
*  @param  [IN] handle     由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] callback   搜索车牌识别信息的回调
*  @param  [IN] mSecWait   等待毫秒时间 
*  @param  [IN] userdata   用户数据
*  @return 0表示成功，-1表示失败
*  @note   搜索到结果则调用回调,回调完成后返回上层
*  @ingroup group_device
*/ 
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_SearchPlateResult(VzLPRClientHandle handle, VZPGS_SEARCH_PALTE_CALLBACK callback, unsigned int mSecWait,void * userdata);


/**
*  @brief  获取车位状态
*  @param  [IN] deviceip  设备IP
*  @param  [IN] dt 车位状态参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_RootGetParkingStatus(const char*deviceip, VZ_PARKING_STATUS * sp);


/**
*  @brief  设置服务器推送地址
*  @param  [IN] deviceip 需要配置的设备地址
*  @param  [IN] dt  推送的服务器信息
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_RootSetPushAddr(const char*deviceip, const VZ_HTTP_SERVER_PARAMETER * dt);

/**
*  @brief  设置设备目的推送地址
*  @param  [IN] deviceip 需要配置的设备地址
*  @param  [IN] DstNodeList 目的节点
*  @param  [IN][OUT] dstListLen  目的节点长度
*  @return 0表示成功，-1表示失败
*  @note  dstListLen最大4个
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_RootSetDeviceDstNode(const char* deviceip, const VZ_DEVICE_DST_NODE  *dstList, unsigned int dstListLen);

/**
*  @brief  获取设备目的推送地址
*  @param  [IN] deviceip 需要配置的设备地址
*  @param  [IN] DstNodeList 目的节点
*  @param  [IN] dstListLen  目的节点长度
*  @return 0表示成功，-1表示失败
*  @note   dstListLen最大4个
*  @ingroup group_device
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_RootGetDeviceDstNode(const char* deviceip, VZ_DEVICE_DST_NODE  *dstList, unsigned int dstListLen);

/**
*  @brief  批量配置设备IP地址
*  @param  [IN] ipp IP配置参数指针
*  @param  [IN] ipConfigListLen IP配置参数个数
*  @return 0表示成功，-1表示失败
*  @note   以MAC为基础批量配置设备IP
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_RootSetDeviceIp(VZ_IP_CONFIG_PARAMTER * ipConfigList, unsigned int ipConfigListLen);


/**
*  @brief  配置所有设备的灯
*  @param  [IN] lct  灯颜色
*  @param  [IN] remainTime  持续时间,单位:秒
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_RootOpenLight(int lct, unsigned short remainTime);

/**
*  @brief  设置设备名称
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] name  设备名称缓冲区
*  @param  [IN] len   设备名称缓冲区长度
*  @return 0表示成功，-1表示失败
*  @note   设备名称缓冲区字节最大为32个字节
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SetDeviceName(VzLPRClientHandle handle, const char * nameBuff, unsigned int nameBuffLen);

/**
*  @brief  获取设备名字
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] name  设备名称缓冲区
*  @param  [IN] len   设备名称缓冲区长度
*  @return 0表示成功，-1表示失败
*  @note   设备名称缓冲区字节最大为32个字节
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL  VzPGS_Sdk_GetDeviceName(VzLPRClientHandle handle, char * nameBuff, unsigned int nameBuffLen);

/**
*  @brief  设置停车位区域位置
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] cfg  停车位区域指针
*  @param  [IN] cfgLen    停车位区域结构体个数
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SetParkingAreaCfg(VzLPRClientHandle handle, const VZ_PARKING_AREA_CFG* cfg, unsigned short cfgNum);

/**
*  @brief  获取停车位区域位置
*  @param  [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] cfg  停车位区域指针
*  @param  [IN][OUT] cfgLen    停车位区域结构体个数
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_GetParkingAreaCfg(VzLPRClientHandle handle, VZ_PARKING_AREA_CFG* cfg, unsigned short *cfgNum);


/**
*  @brief  获取最后一次错误索引
*  @return 错误索引
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_GetLastError();

/**
*  @brief  设置最后一次错误索引
*  @param  [IN] lastErrorIndex 错误索引号
*  @return 0表示成功
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API void  __STDCALL VzPGS_Sdk_SetLastError(int lastErrorIndex);


/**
*  @brief 开始升级
*  @param [IN] deviceip 设备IP
*  @param [IN] file_path_name 升级文件路径
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_RootUpdate(const char* deviceip, char *file_path_name);

/**
*  @brief 重启
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_Reboot(VzLPRClientHandle handle);


/**
*  @brief 设置停车位灯颜色配置
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] cfg    停车位灯配置的指针
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetParkingColorCfg(VzLPRClientHandle handle, const VZ_PARKING_COLOR_CFG * cfg);

/**
*  @brief 获取停车位灯颜色配置
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] cfg    停车位灯配置的指针
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetParkingColorCfg(VzLPRClientHandle handle, VZ_PARKING_COLOR_CFG * cfg);

/**
*  @brief 设置外部设备控制配置
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] cfg    停车位外控配置的指针
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetParkingExtDeviceCfg(VzLPRClientHandle handle, const VZ_PARKING_EXT_DEVICE_CFG * cfg);

/**
*  @brief 获取外部设备控制配置
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] cfg    停车位外控配置的指针
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetParkingExtDeviceCfg(VzLPRClientHandle handle, VZ_PARKING_EXT_DEVICE_CFG * cfg);


/**
*  @brief 设置设备网络参数
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] cfg    停车位设备网络配置的指针
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDeviceNetCfg(VzLPRClientHandle handle, const VZ_PARKING_DEVICE_NET_CFG * cfg);

/**
*  @brief 设置设备网络参数
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] cfg    停车位设备网络配置的指针
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetDeviceNetCfg(VzLPRClientHandle handle, VZ_PARKING_DEVICE_NET_CFG *cfg);

/**
*  @brief 设置串口外部配置
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] cfg    串口外部配置的指针
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSerialExtCfg(VzLPRClientHandle handle, const VZ_SERIAL_EXT_PARAMETER * cfg);

/**
*  @brief 获取串口外部配置
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] cfg    串口外部配置的指针
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSerialExtCfg(VzLPRClientHandle handle, VZ_SERIAL_EXT_PARAMETER * cfg);

/**
*  @brief 获取停车位数目
*  @param [IN] handle 由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] parkingnum  停车位数目
*  @return 0表示成功，-1表示失败
*/

VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetParkingNum(VzLPRClientHandle handle,int *parkingnum);

/**
*  @brief  按照过滤设备规则搜索设备
*  @param  [IN] callback 找寻设备的回调
*  @param  [IN] userdata 用户数据
*  @param  [IN]  mSecWait 等待搜索时间  
*  @param  [IN] cfg     设备过滤原则配置
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL    VzPGS_Sdk_SearchFilterDevice(VZPGS_SEARCH_DEVICE_CALLBACK callback, void * userdata, unsigned int mSecWait,VZ_DEVICE_FILTER_CFG *cfg);


/**
*  @brief  按照过滤设备规则开启设备灯
*  @param  [IN] lct  灯颜色
*  @param  [IN] remainTime  持续时间,单位:秒
*  @param  [IN] cfg     设备过滤原则配置
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_FilterOpenLight( int lct ,unsigned short remainTime,VZ_DEVICE_FILTER_CFG *cfg);


/**
*  @brief 设置设备状态
*  @param [IN] deviceip 设备地址
*  @param [OUT] cfg     设备状态结果体 
*  @return 0表示成功，-1表示失败
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDeviceStatus(const char* deviceip, int status);


/**
*  @brief 设置HTTP车牌重发配置
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] cfg     HTTP车牌重发配置
*  @return 0表示成功，-1表示失败
*  @note  设置重发最后一次车牌识别信息的配置
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetHttpPlateRepeatCfg(VzLPRClientHandle handle, VZ_HTTP_PLATE_REPEAT_CFG *cfg);

/**
*  @brief 获取HTTP车牌重发配置
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] cfg     HTTP车牌重发配置
*  @return 0表示成功，-1表示失败
*  @note  获取重发最后一次车牌识别信息的配置
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetHttpPlateRepeatCfg(VzLPRClientHandle handle, VZ_HTTP_PLATE_REPEAT_CFG *cfg);

/**
*  @brief 设置串口协议配置
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] cfg     串口协议配置
*  @return 0表示成功，-1表示失败
*  @note   
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSerialProtocolCfg(VzLPRClientHandle handle, VZ_SERIAL_PROTOCOL_CFG * cfg);

/**
*  @brief 获取设置串口协议配置
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] cfg     串口协议配置
*  @return 0表示成功，-1表示失败
*  @note   
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSerialProtocolCfg(VzLPRClientHandle handle,VZ_SERIAL_PROTOCOL_CFG *cfg);


/**
*  @brief 中断/恢复原本设备控制的串口输出
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] value    原本设备控制类型,对应枚举VZ_ORIGIN_SERIAL_HALT_TYPE
*  @return 0表示成功，-1表示失败
*  @note   
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetHaltOrginSerialOutput(VzLPRClientHandle handle,int value);


/**
*  @brief 配置用户名密码
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] userOldName 旧的用户名，长度应小于32
*  @param [IN] userOldPassword 旧的密码，长度应小于32
*  @param [IN] userNewName 新的用户名，长度应小于32
*  @param [IN] userNewPassword 新的密码，长度应小于32
*  @return 0表示成功，-1表示失败
*  @note   
*/
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_SetUserNamePassword(VzLPRClientHandle handle,const char* userOldName,const char* userOldPassword,\
														 const char* userNewName,const char* userNewPassword );


/**
*  @brief 获取用户名密码
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] userName 用户名
*  @param [OUT] userPassword 密码
*  @return 0表示成功，-1表示失败
*  @note   
*/
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_GetUserNamePassword(VzLPRClientHandle handle, char* userName,int namelen,  char* userPassword,int passwordLen);

/**
*  @brief 重置配置
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] level  重置等级，详见VZ_RESET_CONFIG_LEVEL_TYPE
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_ResetCfg(VzLPRClientHandle handle,int level);

/**
*  @brief 设置http心跳配置
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] cfg      http心跳配置
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_SetHttpHeartBeatCfg(VzLPRClientHandle handle,const VZ_HTTP_HEART_BEAT_CFG * cfg);

/**
*  @brief 获取http心跳配置
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] cfg      http心跳配置
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int  __STDCALL  VzPGS_Sdk_GetHttpHeartBeatCfg(VzLPRClientHandle handle,VZ_HTTP_HEART_BEAT_CFG *cfg);

/**
*  @brief 设置截图图片质量
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] quality   图片质量,值必须为10的倍数,区间[10,100],
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSnapImageQuality(VzLPRClientHandle handle,int quality);

/**
*  @brief 获取截图图片质量
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] quality      图片质量 
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSnapImageQuality(VzLPRClientHandle handle,int* quality);

/**
*  @brief 设置截图是否启用重叠开关
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] OsdEnable    抓图OSD显示开关 -- 1:显示  0:不显示
*  @param [IN] AreaEnable   抓图识别区域显示开关 -- 1:显示  0:不显示
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSnapImageOverlayEnable(VzLPRClientHandle handle,int OsdEnable,int AreaEnable);

/**
*  @brief 获取截图是否启用重叠开关
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] OsdEnable    抓图OSD显示开关  
*  @param [OUT] AreaEnable   抓图识别区域显示开关  
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSnapImageOverlayEnable(VzLPRClientHandle handle,int* OsdEnable,int* AreaEnable);

/**
*  @brief 设置是否启用占线检测开关
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] enable   车位占线检测开关 -- 1:启用  0:不启用 
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDetectOnLineEnable(VzLPRClientHandle handle,int enable);

/**
*  @brief 获取是否启用占线检测开关
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] enable   车位占线检测开关  
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetDetectOnLineEnable(VzLPRClientHandle handle,int* enable);


/**
*  @brief 设置设备控制模式
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] power   设备控制模式,详见枚举VZ_CONTROL_MODE
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetControlMode(VzLPRClientHandle handle,int mode);

/**
*  @brief 获取设备控制模式
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] power   设备控制模式,详见枚举VZ_CONTROL_MODE
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetControlMode(VzLPRClientHandle handle,int *mode);

/**
*  @brief 设置设备指示灯颜色
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] color   设备指示灯颜色,详见枚举VZ_LIGHT_COLOR_TYPE
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDeviceLightColor(VzLPRClientHandle handle,int color);

/**
*  @brief 设置特殊场景参数
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] mode   特殊显示场景,详见枚举VZ_SPECIAL_SCENE_DISPLAY
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSpecialSceneDisplay(VzLPRClientHandle handle,int mode);
/**
*  @brief 获取特殊场景参数
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] mode   特殊显示场景,详见枚举VZ_SPECIAL_SCENE_DISPLAY
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSpecialSceneDisplay(VzLPRClientHandle handle,int* mode);


/**
*  @brief 设置小图截图模式
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] mode   小图截图模式,详见枚举VZ_SMALL_IMAGE_CAP_MODE
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSmallImageCapMode(VzLPRClientHandle handle,int mode);

/**
*  @brief 获取小图截图模式
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] mode   小图截图模式,详见枚举VZ_SMALL_IMAGE_CAP_MODE
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSmallImageCapMode(VzLPRClientHandle handle,int* mode);

/**
*  @brief  单车位车牌回调
*  @param  [OUT] handle    由VzPGS_Sdk_Open函数获得的句柄
*  @param  [OUT] parkingInfo   总停车位信息
*  @param  [OUT] userdata 用户数据
*  @return 
*  @note
*  @ingroup group_device
*/
typedef void(__STDCALL *VZPGS_SINGLE_PARKING_PALTE_CALLBACK)(VzLPRClientHandle handle,VZ_SINGLE_PARKING_INFO* parkingInfo,void * userdata);

/**
*  @brief  串口信息数据回调
*  @param  [OUT] handle    由VzPGS_Sdk_Open函数获得的句柄
*  @param  [OUT] parkingInfo   总停车位信息
*  @param  [OUT] userdata 用户数据
*  @return 
*  @note
*  @ingroup group_device
*/
typedef void(__STDCALL *VZPGS_SERIAL_DATA_CALLBACK)(VzLPRClientHandle handle,const unsigned char *pRecvData, unsigned uRecvSize,void * userdata);

/**
*  @brief  设置tcp server 配置
*  @param  [IN] handle    由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] cfg   tcp server 配置
*  @return 
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetTcpServerCfg(VzLPRClientHandle handle,const VZ_TCP_SERVER_CFG *cfg );

/**
*  @brief  获取tcp server 配置
*  @param  [IN] handle    由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] cfg   tcp server 配置
*  @return 
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetTcpServerCfg(VzLPRClientHandle handle, VZ_TCP_SERVER_CFG *cfg);

/**
*  @brief  获取tcp server 状态
*  @param  [IN] handle    由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] cfg   tcp server 配置
*  @return 
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetTcpServerConnectStatus(VzLPRClientHandle handle, int *status );

/**
*  @brief  设置蓝牙参数
*  @param  [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] ip 蓝牙参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_SetIbcParamter(VzLPRClientHandle handle, const VZ_IBC_PARAMETER * ip);

/**
*  @brief  获取蓝牙参数
*  @param  [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param  [IN] ip 蓝牙参数指针
*  @return 0表示成功，-1表示失败
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetIbcParamter(VzLPRClientHandle handle, VZ_IBC_PARAMETER * ip);


/**
*  @brief 设置广播周期
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] time   广播周期,范围100 200 330 500 1000,单位ms
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetIbcBroper(VzLPRClientHandle handle,int time);

/**
*  @brief 获取广播周期
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] time   广播周期,范围100 200 330 500 1000,单位ms
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetIbcBroper(VzLPRClientHandle handle,int * time);

/**
*  @brief 设置蓝牙发射功率
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] power   蓝牙发射功率,范围，不带功放(-23，-6，0，4) 带2591功放(-5, 12, 15, 18)
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetIbcLaunchPower(VzLPRClientHandle handle,int power);
/**
*  @brief 获取蓝牙发射功率
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] power   蓝牙发射功率,范围，不带功放(-23，-6，0，4) 带2591功放(-5, 12, 15, 18)
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetIbcLaunchPower(VzLPRClientHandle handle,int *power);

/**
*  @brief 设置蓝牙测试功率
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [IN] power   蓝牙测试功率,范围，-20~-90
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetIbcTestPower(VzLPRClientHandle handle,int power);

/**
*  @brief 获取蓝牙测试功率
*  @param [IN] handle   由VzPGS_Sdk_Open函数获得的句柄
*  @param [OUT] power   蓝牙测试功率,范围，-20~-90
*  @return 0表示成功，-1表示失败
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetIbcTestPower(VzLPRClientHandle handle,int *power);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif

#endif
