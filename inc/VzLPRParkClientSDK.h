//���ڽ���VZ�ĳ���ʶ���豸����������ʶ��һ���������ʶ���ն˵ȣ���Ӧ�ó���ӿ�
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
*  @brief ȫ�ֳ�ʼ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note �����нӿڵ���֮ǰ����
*  @ingroup group_global
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SetUp();

/**
*  @brief ȫ���ͷ�
*  @note �ڳ������ʱ���ã��ͷ�SDK����Դ
*  @ingroup group_global
*/
VZ_LPRC_API void __STDCALL VzPGS_Sdk_CleanUp();


/**
*  @brief ��һ���豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] pStrUserName �����豸�����û���
*  @param  [IN] pStrPassword �����豸��������
*  @return �����豸�Ĳ������������ʧ��ʱ������0
*  @ingroup group_device
*/
VZ_LPRC_API VzLPRClientHandle  __STDCALL VzPGS_Sdk_Open(const char* pStrIP, unsigned int wPort, const char* pStrUserName, const char* pStrPassword);

/**
*  @brief �ر�һ���豸
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL  VzPGS_Sdk_Close(VzLPRClientHandle handle);


/**
*  @brief ���ô��ڲ���
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] sp ���ڲ���ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SetSerialParam(VzLPRClientHandle handle, const VZ_SERIAL_PARAMETER * sp);

/**
*  @brief ��ȡ���ڲ���
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] sp ���ڲ���ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_GetSerialParam(VzLPRClientHandle handle, VZ_SERIAL_PARAMETER * sp);

/**
*  @brief ���ʹ�������
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] buffer ���ݻ�����
*  @param  [IN] bufferLen ���ݻ���������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SendSerialData(VzLPRClientHandle handle, const char *buffer, unsigned int bufferLen);


/**
*  @brief �����豸ʱ��
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt �豸ʱ�����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDeviceTime(VzLPRClientHandle handle, const VZ_DEVICE_TIME * dt);

/**
*  @brief ��ȡ�豸ʱ��
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt �豸ʱ�����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetDeviceTime(VzLPRClientHandle handle, VZ_DEVICE_TIME * dt);

/**
*  @brief ����OSd����
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt OSD����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetOsdCfg(VzLPRClientHandle handle, const VZ_OSD_CFG * osd);

/**
*  @brief ��ȡOSD����
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt osd����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetOsdCfg(VzLPRClientHandle handle, VZ_OSD_CFG * osd);

/**
*  @brief ������Ƶ����
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt ��Ƶ����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetVideoParam(VzLPRClientHandle handle, const VZ_VIDEO_PARAMETER * video_param);

/**
*  @brief ��ȡ��Ƶ����
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt ��Ƶ����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetVideoParam(VzLPRClientHandle handle, VZ_VIDEO_PARAMETER * video_param);

/**
*  @brief ����http����������
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt http����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetHttpParam(VzLPRClientHandle handle, const VZ_HTTP_SERVER_PARAMETER * http_param);

/**
*  @brief ��ȡhttp����������
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt http����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetHttpParam(VzLPRClientHandle handle, VZ_HTTP_SERVER_PARAMETER * http_param);

/**
*  @brief  ��ȡ�豸�汾
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] dt �豸����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetDeviceVersion(VzLPRClientHandle handle, VZ_DEVICE_VERSION * version);

#if defined(WIN32) || defined(_WIN64)
/**
*  @brief ����ʵʱ��Ƶ
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return ���ز��ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_StartRealPlay(VzLPRClientHandle handle, void *hWnd);

/**
*  @brief ֹͣ����ָ���Ĳ��ž��
*  @param  [IN] nPlayHandle ���ŵľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ������ֹͣ�������Ժ���VzPGS_Sdk_StartRealPlay�Ĳ��ž��
*  @note   ֹͣ�����Ժ󣬸ò��ž����ʧЧ��
*  @ingroup group_device
*/
VZ_LPRC_API void __STDCALL VzPGS_Sdk_StopRealPlay(int playhandle);
#endif

/**
*  @brief ������������ź�
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int   __STDCALL VzPGS_Sdk_ForceTrigger(VzLPRClientHandle handle);


/**
*  @brief ��ȡ��ͼ
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] buffer  ͼ�񻺳���
*  @param  [IN] buffLen  ��������С
*  @param  [IN] writeLen   д��ĳ���
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ��ȡ��ͼƬ������jpg�ļ�
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_GetSnapImage(VzLPRClientHandle handle, char *buffer, unsigned int buffLen, unsigned int *writeLen);

/**
*  @brief  �����豸��Ϣ�Ļص�
*  @param  [OUT] device   �豸��Ϣ
*  @param  [OUT] userdata �û�����
*  @return 
*  @note
*  @ingroup group_device
*/
typedef void(__STDCALL *VZPGS_SEARCH_DEVICE_CALLBACK)(VZ_DEVICE_RELATION * device, void * userdata);

/**
*  @brief  �����豸ͨ���ص�
*  @param  [IN] callback ��Ѱ�豸�Ļص�
*  @param  [IN] userdata �û�����
*  @param  [IN]  mSecWait �ȴ�����ʱ��,��λ,ms,����С��200ms
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API void __STDCALL    VzPGS_Sdk_SearchDevice(VZPGS_SEARCH_DEVICE_CALLBACK callback, void * userdata, unsigned int mSecWait);


/** 
*  @brief  ��ȡ����ʶ����
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [OUT] parkingInfo ���ƽ����Ϣ
*  @param  [IN] mSecWait   �ȴ�����ʱ�� 
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ��ȡʱ�����û��ʶ����Ϣ����ô�ͻ����
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_GetPlateResult(VzLPRClientHandle handle, VZ_PARKING_INFO * parkingInfo, unsigned int mSecWait);


/**
*  @brief  ��������ʶ����Ϣ�Ļص�
*  @param  [OUT] handle    ��VzPGS_Sdk_Open������õľ��
*  @param  [OUT] parkingInfo   ��ͣ��λ��Ϣ
*  @param  [OUT] userdata �û�����
*  @return 
*  @note
*  @ingroup group_device
*/
typedef void(__STDCALL *VZPGS_SEARCH_PALTE_CALLBACK)(VzLPRClientHandle handle,VZ_PARKING_INFO* parkingInfo,void * userdata);

/** 
*  @brief  ��������ʶ����
*  @param  [IN] handle     ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] callback   ��������ʶ����Ϣ�Ļص�
*  @param  [IN] mSecWait   �ȴ�����ʱ�� 
*  @param  [IN] userdata   �û�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   �������������ûص�,�ص���ɺ󷵻��ϲ�
*  @ingroup group_device
*/ 
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_SearchPlateResult(VzLPRClientHandle handle, VZPGS_SEARCH_PALTE_CALLBACK callback, unsigned int mSecWait,void * userdata);


/**
*  @brief  ��ȡ��λ״̬
*  @param  [IN] deviceip  �豸IP
*  @param  [IN] dt ��λ״̬����ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_RootGetParkingStatus(const char*deviceip, VZ_PARKING_STATUS * sp);


/**
*  @brief  ���÷��������͵�ַ
*  @param  [IN] deviceip ��Ҫ���õ��豸��ַ
*  @param  [IN] dt  ���͵ķ�������Ϣ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_RootSetPushAddr(const char*deviceip, const VZ_HTTP_SERVER_PARAMETER * dt);

/**
*  @brief  �����豸Ŀ�����͵�ַ
*  @param  [IN] deviceip ��Ҫ���õ��豸��ַ
*  @param  [IN] DstNodeList Ŀ�Ľڵ�
*  @param  [IN][OUT] dstListLen  Ŀ�Ľڵ㳤��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note  dstListLen���4��
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_RootSetDeviceDstNode(const char* deviceip, const VZ_DEVICE_DST_NODE  *dstList, unsigned int dstListLen);

/**
*  @brief  ��ȡ�豸Ŀ�����͵�ַ
*  @param  [IN] deviceip ��Ҫ���õ��豸��ַ
*  @param  [IN] DstNodeList Ŀ�Ľڵ�
*  @param  [IN] dstListLen  Ŀ�Ľڵ㳤��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   dstListLen���4��
*  @ingroup group_device
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_RootGetDeviceDstNode(const char* deviceip, VZ_DEVICE_DST_NODE  *dstList, unsigned int dstListLen);

/**
*  @brief  ���������豸IP��ַ
*  @param  [IN] ipp IP���ò���ָ��
*  @param  [IN] ipConfigListLen IP���ò�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ��MACΪ�������������豸IP
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_RootSetDeviceIp(VZ_IP_CONFIG_PARAMTER * ipConfigList, unsigned int ipConfigListLen);


/**
*  @brief  ���������豸�ĵ�
*  @param  [IN] lct  ����ɫ
*  @param  [IN] remainTime  ����ʱ��,��λ:��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_RootOpenLight(int lct, unsigned short remainTime);

/**
*  @brief  �����豸����
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] name  �豸���ƻ�����
*  @param  [IN] len   �豸���ƻ���������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   �豸���ƻ������ֽ����Ϊ32���ֽ�
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SetDeviceName(VzLPRClientHandle handle, const char * nameBuff, unsigned int nameBuffLen);

/**
*  @brief  ��ȡ�豸����
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] name  �豸���ƻ�����
*  @param  [IN] len   �豸���ƻ���������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   �豸���ƻ������ֽ����Ϊ32���ֽ�
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL  VzPGS_Sdk_GetDeviceName(VzLPRClientHandle handle, char * nameBuff, unsigned int nameBuffLen);

/**
*  @brief  ����ͣ��λ����λ��
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] cfg  ͣ��λ����ָ��
*  @param  [IN] cfgLen    ͣ��λ����ṹ�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_SetParkingAreaCfg(VzLPRClientHandle handle, const VZ_PARKING_AREA_CFG* cfg, unsigned short cfgNum);

/**
*  @brief  ��ȡͣ��λ����λ��
*  @param  [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] cfg  ͣ��λ����ָ��
*  @param  [IN][OUT] cfgLen    ͣ��λ����ṹ�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_GetParkingAreaCfg(VzLPRClientHandle handle, VZ_PARKING_AREA_CFG* cfg, unsigned short *cfgNum);


/**
*  @brief  ��ȡ���һ�δ�������
*  @return ��������
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_GetLastError();

/**
*  @brief  �������һ�δ�������
*  @param  [IN] lastErrorIndex ����������
*  @return 0��ʾ�ɹ�
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API void  __STDCALL VzPGS_Sdk_SetLastError(int lastErrorIndex);


/**
*  @brief ��ʼ����
*  @param [IN] deviceip �豸IP
*  @param [IN] file_path_name �����ļ�·��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_RootUpdate(const char* deviceip, char *file_path_name);

/**
*  @brief ����
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int  __STDCALL VzPGS_Sdk_Reboot(VzLPRClientHandle handle);


/**
*  @brief ����ͣ��λ����ɫ����
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [IN] cfg    ͣ��λ�����õ�ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetParkingColorCfg(VzLPRClientHandle handle, const VZ_PARKING_COLOR_CFG * cfg);

/**
*  @brief ��ȡͣ��λ����ɫ����
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] cfg    ͣ��λ�����õ�ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetParkingColorCfg(VzLPRClientHandle handle, VZ_PARKING_COLOR_CFG * cfg);

/**
*  @brief �����ⲿ�豸��������
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [IN] cfg    ͣ��λ������õ�ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetParkingExtDeviceCfg(VzLPRClientHandle handle, const VZ_PARKING_EXT_DEVICE_CFG * cfg);

/**
*  @brief ��ȡ�ⲿ�豸��������
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] cfg    ͣ��λ������õ�ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetParkingExtDeviceCfg(VzLPRClientHandle handle, VZ_PARKING_EXT_DEVICE_CFG * cfg);


/**
*  @brief �����豸�������
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [IN] cfg    ͣ��λ�豸�������õ�ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDeviceNetCfg(VzLPRClientHandle handle, const VZ_PARKING_DEVICE_NET_CFG * cfg);

/**
*  @brief �����豸�������
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] cfg    ͣ��λ�豸�������õ�ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetDeviceNetCfg(VzLPRClientHandle handle, VZ_PARKING_DEVICE_NET_CFG *cfg);

/**
*  @brief ���ô����ⲿ����
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] cfg    �����ⲿ���õ�ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSerialExtCfg(VzLPRClientHandle handle, const VZ_SERIAL_EXT_PARAMETER * cfg);

/**
*  @brief ��ȡ�����ⲿ����
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] cfg    �����ⲿ���õ�ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSerialExtCfg(VzLPRClientHandle handle, VZ_SERIAL_EXT_PARAMETER * cfg);

/**
*  @brief ��ȡͣ��λ��Ŀ
*  @param [IN] handle ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] parkingnum  ͣ��λ��Ŀ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/

VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetParkingNum(VzLPRClientHandle handle,int *parkingnum);

/**
*  @brief  ���չ����豸���������豸
*  @param  [IN] callback ��Ѱ�豸�Ļص�
*  @param  [IN] userdata �û�����
*  @param  [IN]  mSecWait �ȴ�����ʱ��  
*  @param  [IN] cfg     �豸����ԭ������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL    VzPGS_Sdk_SearchFilterDevice(VZPGS_SEARCH_DEVICE_CALLBACK callback, void * userdata, unsigned int mSecWait,VZ_DEVICE_FILTER_CFG *cfg);


/**
*  @brief  ���չ����豸�������豸��
*  @param  [IN] lct  ����ɫ
*  @param  [IN] remainTime  ����ʱ��,��λ:��
*  @param  [IN] cfg     �豸����ԭ������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_FilterOpenLight( int lct ,unsigned short remainTime,VZ_DEVICE_FILTER_CFG *cfg);


/**
*  @brief �����豸״̬
*  @param [IN] deviceip �豸��ַ
*  @param [OUT] cfg     �豸״̬����� 
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDeviceStatus(const char* deviceip, int status);


/**
*  @brief ����HTTP�����ط�����
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] cfg     HTTP�����ط�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note  �����ط����һ�γ���ʶ����Ϣ������
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetHttpPlateRepeatCfg(VzLPRClientHandle handle, VZ_HTTP_PLATE_REPEAT_CFG *cfg);

/**
*  @brief ��ȡHTTP�����ط�����
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] cfg     HTTP�����ط�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note  ��ȡ�ط����һ�γ���ʶ����Ϣ������
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetHttpPlateRepeatCfg(VzLPRClientHandle handle, VZ_HTTP_PLATE_REPEAT_CFG *cfg);

/**
*  @brief ���ô���Э������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] cfg     ����Э������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSerialProtocolCfg(VzLPRClientHandle handle, VZ_SERIAL_PROTOCOL_CFG * cfg);

/**
*  @brief ��ȡ���ô���Э������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] cfg     ����Э������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSerialProtocolCfg(VzLPRClientHandle handle,VZ_SERIAL_PROTOCOL_CFG *cfg);


/**
*  @brief �ж�/�ָ�ԭ���豸���ƵĴ������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] value    ԭ���豸��������,��Ӧö��VZ_ORIGIN_SERIAL_HALT_TYPE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetHaltOrginSerialOutput(VzLPRClientHandle handle,int value);


/**
*  @brief �����û�������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] userOldName �ɵ��û���������ӦС��32
*  @param [IN] userOldPassword �ɵ����룬����ӦС��32
*  @param [IN] userNewName �µ��û���������ӦС��32
*  @param [IN] userNewPassword �µ����룬����ӦС��32
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_SetUserNamePassword(VzLPRClientHandle handle,const char* userOldName,const char* userOldPassword,\
														 const char* userNewName,const char* userNewPassword );


/**
*  @brief ��ȡ�û�������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] userName �û���
*  @param [OUT] userPassword ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_GetUserNamePassword(VzLPRClientHandle handle, char* userName,int namelen,  char* userPassword,int passwordLen);

/**
*  @brief ��������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] level  ���õȼ������VZ_RESET_CONFIG_LEVEL_TYPE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_ResetCfg(VzLPRClientHandle handle,int level);

/**
*  @brief ����http��������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] cfg      http��������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_SetHttpHeartBeatCfg(VzLPRClientHandle handle,const VZ_HTTP_HEART_BEAT_CFG * cfg);

/**
*  @brief ��ȡhttp��������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] cfg      http��������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int  __STDCALL  VzPGS_Sdk_GetHttpHeartBeatCfg(VzLPRClientHandle handle,VZ_HTTP_HEART_BEAT_CFG *cfg);

/**
*  @brief ���ý�ͼͼƬ����
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] quality   ͼƬ����,ֵ����Ϊ10�ı���,����[10,100],
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSnapImageQuality(VzLPRClientHandle handle,int quality);

/**
*  @brief ��ȡ��ͼͼƬ����
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] quality      ͼƬ���� 
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSnapImageQuality(VzLPRClientHandle handle,int* quality);

/**
*  @brief ���ý�ͼ�Ƿ������ص�����
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] OsdEnable    ץͼOSD��ʾ���� -- 1:��ʾ  0:����ʾ
*  @param [IN] AreaEnable   ץͼʶ��������ʾ���� -- 1:��ʾ  0:����ʾ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSnapImageOverlayEnable(VzLPRClientHandle handle,int OsdEnable,int AreaEnable);

/**
*  @brief ��ȡ��ͼ�Ƿ������ص�����
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] OsdEnable    ץͼOSD��ʾ����  
*  @param [OUT] AreaEnable   ץͼʶ��������ʾ����  
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSnapImageOverlayEnable(VzLPRClientHandle handle,int* OsdEnable,int* AreaEnable);

/**
*  @brief �����Ƿ�����ռ�߼�⿪��
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] enable   ��λռ�߼�⿪�� -- 1:����  0:������ 
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDetectOnLineEnable(VzLPRClientHandle handle,int enable);

/**
*  @brief ��ȡ�Ƿ�����ռ�߼�⿪��
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] enable   ��λռ�߼�⿪��  
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetDetectOnLineEnable(VzLPRClientHandle handle,int* enable);


/**
*  @brief �����豸����ģʽ
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] power   �豸����ģʽ,���ö��VZ_CONTROL_MODE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetControlMode(VzLPRClientHandle handle,int mode);

/**
*  @brief ��ȡ�豸����ģʽ
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] power   �豸����ģʽ,���ö��VZ_CONTROL_MODE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetControlMode(VzLPRClientHandle handle,int *mode);

/**
*  @brief �����豸ָʾ����ɫ
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] color   �豸ָʾ����ɫ,���ö��VZ_LIGHT_COLOR_TYPE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetDeviceLightColor(VzLPRClientHandle handle,int color);

/**
*  @brief �������ⳡ������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] mode   ������ʾ����,���ö��VZ_SPECIAL_SCENE_DISPLAY
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSpecialSceneDisplay(VzLPRClientHandle handle,int mode);
/**
*  @brief ��ȡ���ⳡ������
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] mode   ������ʾ����,���ö��VZ_SPECIAL_SCENE_DISPLAY
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSpecialSceneDisplay(VzLPRClientHandle handle,int* mode);


/**
*  @brief ����Сͼ��ͼģʽ
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] mode   Сͼ��ͼģʽ,���ö��VZ_SMALL_IMAGE_CAP_MODE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetSmallImageCapMode(VzLPRClientHandle handle,int mode);

/**
*  @brief ��ȡСͼ��ͼģʽ
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] mode   Сͼ��ͼģʽ,���ö��VZ_SMALL_IMAGE_CAP_MODE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetSmallImageCapMode(VzLPRClientHandle handle,int* mode);

/**
*  @brief  ����λ���ƻص�
*  @param  [OUT] handle    ��VzPGS_Sdk_Open������õľ��
*  @param  [OUT] parkingInfo   ��ͣ��λ��Ϣ
*  @param  [OUT] userdata �û�����
*  @return 
*  @note
*  @ingroup group_device
*/
typedef void(__STDCALL *VZPGS_SINGLE_PARKING_PALTE_CALLBACK)(VzLPRClientHandle handle,VZ_SINGLE_PARKING_INFO* parkingInfo,void * userdata);

/**
*  @brief  ������Ϣ���ݻص�
*  @param  [OUT] handle    ��VzPGS_Sdk_Open������õľ��
*  @param  [OUT] parkingInfo   ��ͣ��λ��Ϣ
*  @param  [OUT] userdata �û�����
*  @return 
*  @note
*  @ingroup group_device
*/
typedef void(__STDCALL *VZPGS_SERIAL_DATA_CALLBACK)(VzLPRClientHandle handle,const unsigned char *pRecvData, unsigned uRecvSize,void * userdata);

/**
*  @brief  ����tcp server ����
*  @param  [IN] handle    ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] cfg   tcp server ����
*  @return 
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetTcpServerCfg(VzLPRClientHandle handle,const VZ_TCP_SERVER_CFG *cfg );

/**
*  @brief  ��ȡtcp server ����
*  @param  [IN] handle    ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] cfg   tcp server ����
*  @return 
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetTcpServerCfg(VzLPRClientHandle handle, VZ_TCP_SERVER_CFG *cfg);

/**
*  @brief  ��ȡtcp server ״̬
*  @param  [IN] handle    ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] cfg   tcp server ����
*  @return 
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetTcpServerConnectStatus(VzLPRClientHandle handle, int *status );

/**
*  @brief  ������������
*  @param  [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] ip ��������ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL  VzPGS_Sdk_SetIbcParamter(VzLPRClientHandle handle, const VZ_IBC_PARAMETER * ip);

/**
*  @brief  ��ȡ��������
*  @param  [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param  [IN] ip ��������ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetIbcParamter(VzLPRClientHandle handle, VZ_IBC_PARAMETER * ip);


/**
*  @brief ���ù㲥����
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] time   �㲥����,��Χ100 200 330 500 1000,��λms
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetIbcBroper(VzLPRClientHandle handle,int time);

/**
*  @brief ��ȡ�㲥����
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] time   �㲥����,��Χ100 200 330 500 1000,��λms
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetIbcBroper(VzLPRClientHandle handle,int * time);

/**
*  @brief �����������书��
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] power   �������书��,��Χ����������(-23��-6��0��4) ��2591����(-5, 12, 15, 18)
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetIbcLaunchPower(VzLPRClientHandle handle,int power);
/**
*  @brief ��ȡ�������书��
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] power   �������书��,��Χ����������(-23��-6��0��4) ��2591����(-5, 12, 15, 18)
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetIbcLaunchPower(VzLPRClientHandle handle,int *power);

/**
*  @brief �����������Թ���
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [IN] power   �������Թ���,��Χ��-20~-90
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_SetIbcTestPower(VzLPRClientHandle handle,int power);

/**
*  @brief ��ȡ�������Թ���
*  @param [IN] handle   ��VzPGS_Sdk_Open������õľ��
*  @param [OUT] power   �������Թ���,��Χ��-20~-90
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   
*/ 
VZ_LPRC_API int __STDCALL VzPGS_Sdk_GetIbcTestPower(VzLPRClientHandle handle,int *power);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif

#endif
