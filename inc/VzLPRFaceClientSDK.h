//���ڽ���VZ������ץ�������Ӧ�ó���ӿ�
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
*  @brief ����ץ�Ľ��
*  @param [OUT] face_result �������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_FACE_RESULT_CALLBACK)(VzLPRClientHandle handle, TH_FaceResult* face_result, void* pUserData);

/**
*  @brief ��������ץ�Ľ���ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceResultCallBack(VzLPRClientHandle handle, VZLPRC_FACE_RESULT_CALLBACK func, void* pUserData);


/**
*  @brief ����ͳ�ƽ��
*  @param [OUT] area1_num ����һ����
*  @param [OUT] area2_num ���������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_FACE_COUNT_STAT_CALLBACK)(VzLPRClientHandle handle, int area1_num, int area2_num, void* pUserData);

/**
*  @brief ��������ͳ�ƽ���ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceCountStatCallBack(VzLPRClientHandle handle, VZLPRC_FACE_COUNT_STAT_CALLBACK func, void* pUserData);


/**
*  @brief ��ȡ����ʶ������Ĺ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] face_rule_area ����ʶ�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceRuleArea(VzLPRClientHandle handle, TH_FaceRuleArea* face_rule_area);

/**
*  @brief ��������ʶ������Ĺ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] face_rule_area ����ʶ�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceRuleArea(VzLPRClientHandle handle, TH_FaceRuleArea* face_rule_area);

/**
*  @brief ��ȡ������������Ĺ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] face_rule_area ������������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceShieldArea(VzLPRClientHandle handle, TH_FaceShieldArea* face_shield_area);

/**
*  @brief ����������������Ĺ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] face_rule_area ������������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceShieldArea(VzLPRClientHandle handle, TH_FaceShieldArea* face_shield_area);

/**
*  @brief ��������IRCUT��״̬
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] ircut ��Ƶ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFaceIrcutParams(VzLPRClientHandle handle, int ircut);

/**
*  @brief ��ȡ����IRCUT��״̬
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] ircut ��Ƶ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFaceIrcutParams(VzLPRClientHandle handle, int* ircut);

/**
*  @brief ����������Աͳ���������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_FaceResetCounter(VzLPRClientHandle handle);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif


#endif
