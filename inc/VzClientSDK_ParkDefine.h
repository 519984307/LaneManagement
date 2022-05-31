#ifndef _VZ_CLIENT_SDK_PARK_DEFINE_H_
#define _VZ_CLIENT_SDK_PARK_DEFINE_H_
#include <inc/VzClientSDK_LPDefine.h>


#define  HeartBeatPushCycleMin  30
#define  HeartBeatPushCycleMax  120

#define  UserNameBufferMaxLength 32


//�����б�
enum VZ_ERROR_LIST
{
	EL_UN_DEFINE_ERROR = -1,   // δ�������
	EL_SUCCESS,                //�ɹ�
	EL_UNSETUP,                //δȫ�ֳ�ʼ��
	EL_HAVESETUP,              //�Ѿ�ȫ�ֳ�ʼ��

	EL_OPEN_DEVICE_FAIL,       //���豸ʧ��
	EL_UN_OPEN_DEVICE,         //δ���豸
	EL_DEVICE_OFFLINE,         //�豸����
	EL_HAVE_OPEN_DEVICE,       //�豸�Ѿ���
	EL_DEVICE_NO_RESPONSE,     //�豸�޷�Ӧ
	EL_CANNOT_CONNECT_DEVICE,  //�޷������豸
	EL_CANNOT_FIND_DEVICE,     //�޷��ҵ��豸
	EL_PORT_ERROR,             //�˿ڴ���

	EL_IP_ADDR_CONFLICT,       //IP��ַ��ͻ
	EL_IP_ADDR_ERROR,          //IP��ַ����
	EL_RECV_ERROR_NET_DATA,    //���յ�������������
	EL_IMAGE_BUFFER_TOO_SHORT, //ͼƬ������̫��
	EL_PARAMTER_ERROR,         //��������
	EL_NULL_DATA,              //������
	EL_BUFFER_TOO_SHORT,       //������̫��
	EL_NET_ERROR,              //�������
	EL_MEMORY_LACK,            //�ڴ�����ʧ��

	EL_HWND_HAVE_PLAY,         //�����Ѳ���
	EL_CANNOT_FIND_PLAY,       //�޷��ҵ����ž��
	EL_PLAY_NOT_FOUND,         //δ�ҵ���Ƶ��
	EL_PLAY_UNAUTHORIZED,      //��Ƶ��֤ʧ��
	EL_INTERAPT,               //��Ƶ���ж�
	EL_DURATION,               //�ļ�����ʱ����λMS
};  

//�豸״̬
typedef enum {
	DS_FREE = 0,          //����
	DS_BUSY,              //ռ��
	DS_RESERVE,            //Ԥ��  ��ʱû��
	DS_ALARM,              //�澯  ��ʱû��
} VZ_DEVICE_STATUS;


//�豸ָʾ����ɫ
typedef enum 
{
	LCT_Red,       //��ɫ
	LCT_Green,     //��ɫ
	LCT_Blue,      //����ɫ
	LCT_White,     //��ɫ
	LCT_Close,     //���
	LCT_Yellow,    //��ɫ
	LCT_Perple,    //��ɫ
	LCT_LowBlue,   //ǳ��ɫ
}VZ_LIGHT_COLOR_TYPE;

//tcp����״̬
typedef enum 
{
	TCS_UNCONNECT,          //δ����
	TCS_CONNECTING,         //������
}VZ_TCP_CONNECT_STATUS;

//�豸����ģʽö��
typedef enum
{
	DCM_DEVICE,       //�豸����ģʽ
	DCM_USER          //�û�����ģʽ

}VZ_CONTROL_MODE;

//���ⳡ����ʾö��
typedef enum
{
	SSD_NORMAL,       //2m����(Ĭ��״̬)  
	SSD_0,            //0.5-1m           
	SSD_1,            //1-1.5m           
	SSD_2,            //1.5-2m             

}VZ_SPECIAL_SCENE_DISPLAY;

//Сͼ��ͼģʽ
typedef enum
{
	SICP_HEAD,      //��ͷ��ͼ
	SICP_BODY       //�����ͼ
}VZ_SMALL_IMAGE_CAP_MODE;


//ͣ��λ״̬
typedef enum 
{
	PS_NOHEAD_NOPLATE,        //�޳�ͷ-�޳���
	PS_HEAD_NOPLATE,          //�г�ͷ-�޳���
	PS_NOHEAD_PLATE,          //�޳�ͷ-�г���
	PS_HEAD_PLATE             //�г�ͷ-�г���
}VZ_PARK_STATUS;

//��������
typedef enum
{
	TT_Auto = 1,        //�Զ�����
	TT_Hand,            //�ֶ�����
	TT_SOFTWARE,        //�������
	TT_VLOOP            //������Ȧ����
}VZ_TRIGGER_TYPE;

//�豸λ������
typedef enum 
{
	DP_NONE_POS = 0, //δ����λ��(Ĭ��λ��)
	DP_LEFT_POS, //��ת���豸
	DP_RIGTH_POS, //��ת���豸
	DP_FRONT_POS //ֱ���豸
} VZ_DEV_POSITION;

//���ڸ�ʽ
typedef enum  
{
	DF_YYYY_MM_DD,      //������
	DF_MM_DD_YYYY,      //������
	DF_DD_MM_YYYY,      //������
}VZ_DATA_FORMAT;

//ʱ���ʽ
typedef enum  
{
	TF_12Hours,      //12Сʱ
	TF_24Hours,      //24Сʱ
}VZ_TIME_FORMAT;

//ע������
typedef enum {
	HBT_NONE = 0, //������
	HBT_NORMAL, //��ͨ����
	HBT_COMET //Comet ��ѯ
} VZ_HEART_BEAT_TYPE;



#define  FILTER_BUFFER_MAX_SIZE  32

//�豸�������˲���
typedef struct
{
	char name[FILTER_BUFFER_MAX_SIZE];   //�豸����
	char ver[FILTER_BUFFER_MAX_SIZE];    //�豸�汾
	char sip[FILTER_BUFFER_MAX_SIZE];    //���ڵ���ĳ��IP
	char eip[FILTER_BUFFER_MAX_SIZE];     //С�ڵ���ĳ��IP
	unsigned int  fnum ;   //ͣ��λ��Ŀ 2��3
	unsigned int ipfilt ;  //ipɸѡ���� 
}VZ_DEVICE_FILTER_CFG;


/*�豸ʱ��*/
typedef struct  
{
	//unsigned timezone;       //ʱ��
	unsigned year;           //��
	unsigned mon;            //��
	unsigned day;            //��
	unsigned hour;           //Сʱ
	unsigned min;            //��
	unsigned sec;            //��
}VZ_DEVICE_TIME;

/*��Ƶ����*/
typedef struct  
{
	unsigned brightness;   //����
	unsigned contrast;     //�Աȶ�
	unsigned saturation;   //���Ͷ�
	unsigned hue;          //ɫ��
	unsigned maxExposure;  //����ع�
	unsigned maxGain;      //�������

}VZ_VIDEO_PARAMETER;

#define  VERSION_BUFF_MAX_SIZE  32

/*�豸�汾*/
typedef struct 
{
	char softWareVersion[VERSION_BUFF_MAX_SIZE];   //����汾
	char ukarVerision[VERSION_BUFF_MAX_SIZE];      //ukar�汾
	char algVersion[VERSION_BUFF_MAX_SIZE];        //�㷨�汾
	char serialNo[VERSION_BUFF_MAX_SIZE];          //���к�
	char mac[VERSION_BUFF_MAX_SIZE];               //MAC��ַ
	char hardwareVersion[VERSION_BUFF_MAX_SIZE];   //Ӳ���汾
}VZ_DEVICE_VERSION;




#define    PUSH_ADDR_BUFFER_MAX_SIZE 200
#define    SERVER_BUFFER_MAX_SIZE  32

/*HTTP����������*/
typedef struct 
{
	char serverAddr[SERVER_BUFFER_MAX_SIZE];    //��������ַ
	unsigned port;                  //�˿�
	unsigned timeout;               //��ʱʱ�� ����Χ1-3
	unsigned pushEnable;           //����ʹ��,0Ϊ�����ͣ�1Ϊ����
	unsigned bigImageEnable;        //���ʹ�ͼƬʹ��,0Ϊ�����ͣ�1Ϊ����
	unsigned smallImageEnable;      //����СͼƬʹ��,0Ϊ�����ͣ�1Ϊ����
	char pushAddr[PUSH_ADDR_BUFFER_MAX_SIZE];   //���ͽӿڵ�ַ
}VZ_HTTP_SERVER_PARAMETER;

/*OSD ��������*/
typedef struct  
{
	unsigned enable;        //ʹ��,0:�����ã�1:����
	unsigned format;        //��ʽ
	unsigned positionX;     //λ��X ��Χ0-100
	unsigned positionY;     //λ��Y ��Χ0-100
}Vz_OSD_COMMON_ELEMENT;


#define  OSD_TEXT_BUFF_SIZE  128
/*OSD�ı�����*/
typedef struct 
{
	unsigned enable;        //�ı�ʹ��0:�����ã�1:����
	unsigned positionX;     //�ı�λ��X ��Χ0-100
	unsigned positionY;     //�ı�λ��Y ��Χ0-100
	char textbuf[OSD_TEXT_BUFF_SIZE];        //�ı�������
}VZ_OSD_TEXT_ELEMENT;




/*OSD����*/
typedef struct 
{
	Vz_OSD_COMMON_ELEMENT  date;    //����
	Vz_OSD_COMMON_ELEMENT  time;   //ʱ��
	VZ_OSD_TEXT_ELEMENT    text;   //�ı�
}VZ_OSD_CFG;

/*ͣ��λ״̬*/
typedef struct  
{
	unsigned total;       //�豸�ܳ�λ��
	unsigned free;        //�豸��������
	unsigned nTotal;      //�豸δ���峵λ��
	unsigned nFree;       //�豸δ���������
	unsigned lTotal;      //����豸�ܳ�λ��
	unsigned lFree;       //����豸��������
	unsigned rTotal;      //�ұ��豸�ܳ�λ��
	unsigned rFree;       //�ұ��豸��������
	unsigned fTotal;      //ǰ���豸�ܳ�λ��
	unsigned fFree;       //ǰ���豸��������
}VZ_PARKING_STATUS;



#define  SUCCESS   0
#define  FAILURE   -1

//��
typedef struct
{
	int  x;    //
	int  y;    //
}VZ_PONT;

//����
typedef struct
{
	int left;    //��
	int  top;    //��
	int  right;   //��
	int  bottom;  //��
}VZ_RECT;

//ʱ��ֵ
typedef struct
{
	unsigned dyear;     //��
	unsigned dmon;      //��
	unsigned dday;      //��
	unsigned dhour;      //Сʱ
	unsigned dmin;      //����
	unsigned dsec;      //��

	unsigned  sec;      //�룬ʱ���
	unsigned  usec;     //΢�ʱ���
}VZ_TimeVal;

#define    PAKRING_NAME_MAX_SIZE      128
#define    PARKING_LICENSE_MAX_SIZE   32



//����ͣ��λ��Ϣ
typedef struct
{
	unsigned isenable;               //�Ƿ����
	unsigned ischange;               //�Ƿ�ı�
	unsigned isparkingin;             //�Ƿ����
	unsigned  triggertype;            //�������ͣ�����ṹVZ_TRIGGER_TYPE
	unsigned   occupysplitline;        //ռ��
	char parkingframename[PAKRING_NAME_MAX_SIZE];   //ͣ��λ���� ,GBK����

	unsigned   parkingstatus;         //ͣ��״̬������ṹVZ_PARK_STATUS
	unsigned   bright;                //����
	unsigned   carBright;             //��������
	unsigned   carColor;              //������ɫ
	unsigned   colorType;             //��ɫ����
	unsigned   colorValue;            //��ɫֵ
	unsigned   confidence;            //���Ŷ�
	unsigned   direction;             //����
	char license[PARKING_LICENSE_MAX_SIZE];            //���ƺţ�GBK����

	unsigned     type;                  //����
	VZ_RECT     location;               //λ��
	VZ_TimeVal   timestamp;             //ʱ���s
	char*  image;              //ͼƬ����
	unsigned     imageLen;              //ͼƬ����
}VZ_SINGLE_PARKING_INFO;



#define PARKING_SPACE_SIZE 6

//��ͣ��λ��Ϣ
typedef struct  
{ 
	unsigned short      sysParkingNum;         //�豸����֧�ֵ�ͣ��λ����Ŀ
	VZ_SINGLE_PARKING_INFO  signalParkingInfo[PARKING_SPACE_SIZE];      //����ͣ��λ��Ϣ
	char*        bigImage;                 //��ͼƬ
	unsigned              bigImageLen;              //��ͼƬ����
}VZ_PARKING_INFO;



#define    IBC_UUID_MAX_SIZE  128

//��������
typedef struct
{
	char uuid[IBC_UUID_MAX_SIZE];      //����uuid�ַ���
	unsigned short  major;                        //����major
	unsigned short  minor;                        //����minor

}VZ_IBC_PARAMETER;



#define  DEVICE_IP_MAX_SIZE            32
#define  DEVICE_NAME_MAX_SIZE          32 
#define  DEVICE_SN_MAX_SIZE            32 
#define  DEVICE_BEACON_MAX_SIZE        32 
#define  DEVICE_MAC_MAX_SIZE           32

//�豸IP���ò���
typedef struct
{
	char mac[DEVICE_MAC_MAX_SIZE];           //�豸MAC
	char  ip[DEVICE_IP_MAX_SIZE];            //�豸IP
	char gateway[DEVICE_IP_MAX_SIZE];		  //����
	char netmask[DEVICE_IP_MAX_SIZE];		  //��������
}VZ_IP_CONFIG_PARAMTER;



//���ε�
typedef struct
{
	int  leftTopX;       //����X,��Χ,0-256
	int  leftTopY;       //����Y,��Χ,0-256

	int  leftBottomX;    //����X,��Χ,0-256
	int  leftBottomY;    //����Y,��Χ,0-256

	int  rightTopX;      //����X,��Χ,0-256
	int  rightTopY;      //����Y,��Χ,0-256

	int  rightBottomX;   //����X,��Χ,0-256
	int  rightBottomY;   //����Y,��Χ,0-256
}VZ_RECT_POINT;

//ͣ��λ��������
typedef struct  
{
	char  name[PAKRING_NAME_MAX_SIZE];    //ͣ��λ����
	unsigned   enable;                         //����
	VZ_RECT_POINT  rect;                  //���� 
}VZ_PARKING_AREA_CFG;


//���ڵ��豸��Ϣ
typedef struct
{
	char  ip[DEVICE_IP_MAX_SIZE];      //�豸IP
	unsigned short  pos;              //λ��,����ṹVZ_DEV_POSITION

}VZ_DEVICE_DST_NODE;

#define    DEST_NODE_MAX_SIZE  4  

//�豸����
typedef struct
{
	char  ip[DEVICE_IP_MAX_SIZE];            //�豸IP
	char name[DEVICE_NAME_MAX_SIZE];          //�豸����
	char sn[DEVICE_SN_MAX_SIZE];              //�豸���к�
	char ibeacon[DEVICE_BEACON_MAX_SIZE];     //�豸����ID
	char mac[DEVICE_MAC_MAX_SIZE];                    //�豸MAC
	char uuid[IBC_UUID_MAX_SIZE];      //����uuid
	int  major;                        //����major
	int  minor;                        //����minor
}VZ_DEVICE_PARAMTER;

//�豸��ϵ
typedef struct 
{
	VZ_DEVICE_PARAMTER DeviceParam;    //�豸����
	VZ_DEVICE_DST_NODE  DstNodeList[DEST_NODE_MAX_SIZE]; //Ŀ���豸�б�
}VZ_DEVICE_RELATION;


//ͣ��λ��ص�����
typedef struct  
{
	unsigned short enble;           //������ر�־,0,�����ã�1,����
	unsigned short freeLedColor;    //���е���ɫ ,��Ӧö��VZ_LIGHT_COLOR_TYPE
	unsigned short occupyLedColor;   //ռ�õ���ɫ ,��Ӧö��VZ_LIGHT_COLOR_TYPE
}VZ_PARKING_COLOR_CFG;

//ͣ��λ�ⲿ�豸��������
typedef struct
{
	unsigned short enble;             //���ñ�־,0,�����ã�1,����
	char  ip[DEVICE_IP_MAX_SIZE];            //�豸IP
}VZ_PARKING_EXT_DEVICE_CFG;

//�豸�����������
typedef struct
{ 
	char  ip[DEVICE_IP_MAX_SIZE];                 //�豸IP
	char  netmask[DEVICE_IP_MAX_SIZE];            //�豸����
	char  gateway[DEVICE_IP_MAX_SIZE];            //�豸����
	char  dnsserver[DEVICE_IP_MAX_SIZE];          //�豸DNS SERVER
}VZ_PARKING_DEVICE_NET_CFG;

//�����ⲿ����
typedef struct
{ 
	unsigned short protocl;       //Э���
	unsigned short fEnable;       //ֱ�п���,1���ã�0������
	unsigned short fAddrNum;       //ֱ������ַ�ţ���Χ:0-255
	unsigned short rEnable;       //��ת����,1���ã�0������
	unsigned short rAddrNum;       //��ת����ַ�ţ���Χ:0-255
	unsigned short lEnable;       //��ת����,1���ã�0������
	unsigned short lAddrNum;       //��ת����ַ�ţ���Χ:0-255
}VZ_SERIAL_EXT_PARAMETER;

//http�����ط�����(�ط����һ�γ���ʶ����Ϣ������)
typedef struct  
{
	short enable;           //���ñ�־,0,�����ã�1,����
	short repeatetime;     //�ط�ʱ��,��Χ:60-600,��λ:��
}VZ_HTTP_PLATE_REPEAT_CFG;


//����������������
typedef enum
{
	VZ_SERIAL_NOTYPE = 0,			
	VZ_SERIAL_LICENSEENABLE,	//���޳����Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ�0xAAΪ��ʶ��0xBBΪ����ʶ��
	VZ_SERIAL_LICENSE,			//���ƺ��Ƿ����� 0:�����ã�1:���ã����ֱ���ο��ĵ�����ͨ�ַ�ΪASCII��
	VZ_SERIAL_LICENSECOLOR,		//������ɫ�Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ�00��ɫ 01��ɫ 02��ɫ 03��ɫ 04�������ã�
	VZ_SERIAL_CONFIDENCE,		//���ƿ��Ŷ��Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ��������Ŷȣ������� 100��
	VZ_SERIAL_LICENSETYPE,		//���������Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ�0:δ֪����,1:����С����,2:����С����,��ϸ�ο��ĵ���
	VZ_SERIAL_TRIGGER,			//���������Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ�1:�Զ�,2:�ֶ�������
	VZ_SERIAL_CARCOLOR,			//������ɫ�Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ�00��ɫ 01��ɫ 02��ɫ 03��ɫ 04��������
	VZ_SERIAL_TIME,				//ʶ��ʱ����Ƿ����� 0:�����ã�1:���ã�4 �ֽڣ�����ʶ������ʱ��ʱ�����
	VZ_SERIAL_FRAME_NAME,       //��λ�����Ƿ����� 0:�����ã�1:���ã���֧�ֺ����������ͨ�ַ�Ϊ ASCII��
	VZ_SERIAL_FRAME_STATUS,     //��λ״̬�Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ�0���޳�ͷ�޳���-1���г�ͷ�޳���-2���޳�ͷ�г��� -3���г�ͷ�г��ƣ�
	VZ_SERIAL_OCCUPY_LINE,      //ռ��״̬�Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ�1 Ϊռ�ߣ�0 Ϊ��ռ�ߣ�
	VZ_SERIAL_HEAD_CONF,        //��ͷ���Ŷ��Ƿ����� 0:�����ã�1:���ã�1 �ֽڣ���ͷ���Ŷȣ������� 100��
	VZ_SERIAL_FREE_NUM,         //���г�λ���Ƿ����� 0:�����ã�1:���ã�4 �ֽڣ����г�λ����
	VZ_SERIAL_FRAME_NUM,        //�ܳ�λ���Ƿ����� 0:�����ã�1:���ã�4 �ֽڣ��ܳ�λ����

	VZ_SERIAL_CHECKBEGIN,		//У����ʼλ
	VZ_SERIAL_CHECKEND,			//У�����λ
	VZ_SERIAL_CHECKSUM,			//У��λ

	VZ_SERIAL_TYPELEN			//�������

}VZ_SERIAL_PUSH_TYPE;

//����Э��������
typedef struct 
{ 
	int          item_type;     //������������,���ö��VZ_SERIAL_PUSH_TYPE                          

	int           val;          //�����������ֵ������ö��VZ_SERIAL_PUSH_TYPE�Ľ���                            

}VZ_SERIAL_PROTOCOL_ITEM;

#define  SERIAL_PUSH_TYPE_LEN 17
#define  SERIAL_PUSH_BUFFER_MAX_SIZE 64

//����Э������
typedef  struct
{ 
	VZ_SERIAL_PROTOCOL_ITEM              configItem[SERIAL_PUSH_TYPE_LEN];                                                             
	char                                 header[SERIAL_PUSH_BUFFER_MAX_SIZE];       //��־ͷ                                                         
	char                                 end[SERIAL_PUSH_BUFFER_MAX_SIZE];          //��־β                                                                                                                               
}VZ_SERIAL_PROTOCOL_CFG;

//�ж�/�ָ�ԭ���豸���ƵĴ����������
typedef enum  
{
	VZ_ORIGIN_SERIAL_HALT_RESTORE,            //�ָ��豸�������
	VZ_ORIGIN_SERIAL_HALT_INTERRUPT           //�ж��豸�������
}VZ_ORIGIN_SERIAL_HALT_TYPE;

//�������õȼ�����
typedef enum 
{
	RCLT_ALL,          //�������ûָ�Ĭ��
	RCLT_PART          //���ָֻ�Ĭ�ϣ����������/�û�������/�豸�����⣬���ָ�Ĭ�ϣ�
}VZ_RESET_CONFIG_LEVEL_TYPE;


//HTTP������������
typedef struct 
{
	int heartBeatType;  //��������,���VZ_HEART_BEAT_TYPE
	short pushCycle;    //�������ڣ�s������Χ 30 - 120
	char pushAddr[PUSH_ADDR_BUFFER_MAX_SIZE];   //���ͽӿڵ�ַ
}VZ_HTTP_HEART_BEAT_CFG;


#define  NET_ADDR_MAX_SIZE 128
//ntp������
typedef struct 
{
	char serverAddr[NET_ADDR_MAX_SIZE];   //ntp��������ַ
	int  enable;                   //�Ƿ����
	int  interval;                //���   (1s-24Сʱ)

}VZ_NTP_SERVER_CFG;

//tcp server ����
typedef struct 
{
	int  enable;                   //�Ƿ����  0:�����ã�1:����
	char ip[DEVICE_IP_MAX_SIZE];    //tcp server ip
	unsigned port;                  //�������˿�

}VZ_TCP_SERVER_CFG;
#endif
