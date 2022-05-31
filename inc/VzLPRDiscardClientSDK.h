//���û��ʱ��sdk���壬���Ƽ�ʹ��
#ifndef _VZ_LPR_DISCARD_CLIENT_SDK_
#define _VZ_LPR_DISCARD_CLIENT_SDK_
#include <inc/VzLPRClientSDKDefine.h>

/**
*  @brief ����
*  @brief ��ʼ���ͱ�����Ƶ�ļ�����Ƶ��Զ�̣���Ƶ�ļ�֧��PCM�����wav��ʽ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] strFileName ��Ƶ�ļ��ľ���·��
*  @return ����ֵ��������Ƶ���͵ľ������Ҫ������������������������Ƶ������صĲ���
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStartByWaveFile(VzLPRClientHandle handle, const char *strFileName);


/**
*  @brief ����
*  @brief ֹͣ���ͱ�����Ƶ
*  @param [IN] iTalkHandle VZC_TalkStart������VZC_TalkStartByWaveFile�������صı�����Ƶ���͵ľ��
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStop(int iTalkHandle);


typedef void(__STDCALL * VZLPRC_CallBackTalkData)(int iTalkHandle, const void *pDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser);

/**
*  @brief ����
*  @brief ��ʼ���ͱ��ػ�Ͳ����Ƶ��Զ��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] fTalkDataCallBack ������Ƶ���ݻص�������Ϊ��
*  @param [IN] dwUser ������Ƶ���ݻص���������
*  @return ����ֵ��������Ƶ���͵ľ������Ҫ������������������������Ƶ������صĲ���
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStart(VzLPRClientHandle handle, VZLPRC_CallBackTalkData fTalkDataCallBack, DWORD dwUser);



/**
*  @brief ����
*  @brief ���ղ�������Ƶ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵ����Ƶ���ž������Ҫ��������������������Ƶ����Ĳ���
*/
VZ_LPRC_API int __STDCALL VzLPRClient_OpenSound(VzLPRClientHandle handle);

/**
*  @brief ����
*  @brief ֹͣ���պͲ�����Ƶ
*  @param [IN] iAudioPlayHandle VZC_OpenSound�������ص���Ƶ���ž��
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CloseSound(int iAudioPlayHandle);


//���ռ���ȡ��Ƶ
/**
*  @brief ����
*  @brief ���ղ���ȡ��Ƶ����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] bNeedEncode ��ȡ�������Ƿ�ѹ����0ΪACM��1ΪG711
*  @param [IN] fAudioDataCallBack ��Ƶ���ݻص�����
*  @param [IN] dwUser �ص�������������
*  @return ����ֵ����Ƶ���ž������Ҫ��������������������Ƶ����Ĳ���
*/
VZ_LPRC_API int __STDCALL VzLPRClient_OpenSoundData(VzLPRClientHandle handle, int bNeedEncode,
													VZLPRC_CallBackTalkData fAudioDataCallBack, DWORD dwUser);
/**
*  @brief ����
*  @brief ֹͣ���պͻ�ȡ��Ƶ����
*  @param [IN] iSoundDataHandle VZC_OpenSoundData�������ص���Ƶ���ݾ��
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CloseSoundData(int iSoundDataHandle);

/**
*  @brief ����
*  @brief �����Ƿ�������Ƶ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] bEnable 0Ϊ������Ƶ���ź���Ƶ���ݻص���1Ϊ����
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_AudioEnable(VzLPRClientHandle handle, int bEnable);


/**** VzLPRClientSDK V2��չ�ӿ� ��Ҫ�ṩx64ƽ̨ʹ��(x86λƽ̨����ʹ���½ӿ� ����x64ƽ̨һ��Ҫʹ���½ӿ�)****/
/**
*  @brief ����
*  @brief ֹͣ���ͱ�����Ƶ
*  @param [IN] iTalkHandle VZC_TalkStart������VZC_TalkStartByWaveFile�������صı�����Ƶ���͵ľ��
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStop_V2(int iTalkHandle);


typedef void(__STDCALL * VZLPRC_CallBackTalkData_V2)(int iTalkHandle, const void *pDataBuffer, DWORD dwBufSize, BYTE byAudioFlag, void* pUser);

/**
*  @brief ����
*  @brief ��ʼ���ͱ��ػ�Ͳ����Ƶ��Զ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] fTalkDataCallBack ������Ƶ���ݻص�������Ϊ��
*  @param [IN] pUser ������Ƶ���ݻص���������
*  @return ����ֵ��������Ƶ���͵ľ������Ҫ������������������������Ƶ������صĲ���
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TalkStart_V2(VzLPRClientHandle handle, VZLPRC_CallBackTalkData_V2 fTalkDataCallBack, void* pUser);

/**
*  @brief ����
*  @brief ���ղ���ȡ��Ƶ����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] bNeedEncode ��ȡ�������Ƿ�ѹ����0ΪACM��1ΪG711
*  @param [IN] fAudioDataCallBack ��Ƶ���ݻص�����
*  @param [IN] pUser �ص�������������
*  @return ����ֵ����Ƶ���ž������Ҫ��������������������Ƶ����Ĳ���
*/
VZ_LPRC_API int __STDCALL VzLPRClient_OpenSoundData_V2(VzLPRClientHandle handle, int bNeedEncode,
													   VZLPRC_CallBackTalkData_V2 fAudioDataCallBack, void* pUser);
/**
*  @brief ����
*  @brief ֹͣ���պͻ�ȡ��Ƶ����
*  @param [IN] iSoundDataHandle VZC_OpenSoundData�������ص���Ƶ���ݾ��
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CloseSoundData_V2(int iSoundDataHandle);

/**
*  @brief ����
*  @brief ����������Ƶ����(�˽ӿ����ã�ʹ��VzLPRClient_GetCameraConfig���)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] video_daynight ��Ƶ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceVideoParam(VzLPRClientHandle handle, TH_FaceVideoDaynightParam* video_daynight);

/**
*  @brief ����
*  @brief ��ȡ������Ƶ����(�˽ӿ����ã�ʹ��VzLPRClient_SetCameraConfig���)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] video_daynight ��Ƶ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceVideoParam(VzLPRClientHandle handle, TH_FaceVideoDaynightParam* video_daynight);

/**
*  @brief ����
*  @brief ��ȡ�������SD��Ϣ(�˽ӿ����ã�ʹ��VzLPRClient_GetCameraConfig���)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] sd_info SD����Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceSDInfo(VzLPRClientHandle handle, TH_FaceSDInfo* sd_info);

/**
*  @brief ����
*  @brief ��ʽ���������SD��(ͳһʹ��VzLPRClient_SDFormat��ʽ���Ľӿ�)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_FaceFormatSd(VzLPRClientHandle handle);

#endif
