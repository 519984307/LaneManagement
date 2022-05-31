//���ڽ���·��ͣ�������Ӧ�ó���ӿ�
#ifndef _VZ_LPR_ROAD_SITE_CLIENT_SDK_
#define _VZ_LPR_ROAD_SITE_CLIENT_SDK_
#include <inc/VzLPRClientSDKDefine.h>

#define MAX_BERTH_COUNT  16

typedef struct{
	int berth_number;				// ��λ���
	int berth_state;                // ��λ״̬ ��1.�볡 2.���� 0.�ޣ�
	char license[TH_LP_LEN];  	    // ���ƺ���
} TH_RoadSiteBerth;

/**����ʶ������Ϣ*/
typedef struct 
{
	TH_PlateResult plate_result;
	TH_RECT berth_location;					 // ��λͼλ��
	int berth_state;						 // ��λͼ״̬��1.�볡 2.���� 0.�ޣ�
	int berth_number;						 // ��λ���
	char berth_name[32];					 // ��λ����
	TH_ImgInfo full_img[3];					 // ȫͼ(3��ʱ�̵�ͼƬ)
	TH_ImgInfo clip_img;					 // ����ͼƬ
	TH_RoadSiteBerth berth[MAX_BERTH_COUNT]; // ��λ��Ϣ
	int berth_count;			             // ��λ����
	char reserved1[128];		             // Ԥ������
}TH_RoadSiteResult;

#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif


/**
*  @brief ·��ͣ��ʶ����
*  @param [OUT] face_result �������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_ROAD_SITE_RESULT_CALLBACK)(VzLPRClientHandle handle, TH_RoadSiteResult* face_result, void* pUserData);

/**
*  @brief ����·��ͣ��ʶ�����ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRoadSiteResultCallBack(VzLPRClientHandle handle, VZLPRC_ROAD_SITE_RESULT_CALLBACK func, void* pUserData);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif

#endif
