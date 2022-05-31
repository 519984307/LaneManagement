#ifndef _VZ_CLIENT_SDK_PARK_DEFINE_H_
#define _VZ_CLIENT_SDK_PARK_DEFINE_H_
#include <inc/VzClientSDK_LPDefine.h>


#define  HeartBeatPushCycleMin  30
#define  HeartBeatPushCycleMax  120

#define  UserNameBufferMaxLength 32


//错误列表
enum VZ_ERROR_LIST
{
	EL_UN_DEFINE_ERROR = -1,   // 未定义错误
	EL_SUCCESS,                //成功
	EL_UNSETUP,                //未全局初始化
	EL_HAVESETUP,              //已经全局初始化

	EL_OPEN_DEVICE_FAIL,       //打开设备失败
	EL_UN_OPEN_DEVICE,         //未打开设备
	EL_DEVICE_OFFLINE,         //设备断线
	EL_HAVE_OPEN_DEVICE,       //设备已经打开
	EL_DEVICE_NO_RESPONSE,     //设备无反应
	EL_CANNOT_CONNECT_DEVICE,  //无法连接设备
	EL_CANNOT_FIND_DEVICE,     //无法找到设备
	EL_PORT_ERROR,             //端口错误

	EL_IP_ADDR_CONFLICT,       //IP地址冲突
	EL_IP_ADDR_ERROR,          //IP地址错误
	EL_RECV_ERROR_NET_DATA,    //接收到错误网络数据
	EL_IMAGE_BUFFER_TOO_SHORT, //图片缓冲区太短
	EL_PARAMTER_ERROR,         //参数错误
	EL_NULL_DATA,              //空数据
	EL_BUFFER_TOO_SHORT,       //缓冲区太短
	EL_NET_ERROR,              //网络错误
	EL_MEMORY_LACK,            //内存申请失败

	EL_HWND_HAVE_PLAY,         //窗口已播放
	EL_CANNOT_FIND_PLAY,       //无法找到播放句柄
	EL_PLAY_NOT_FOUND,         //未找到视频流
	EL_PLAY_UNAUTHORIZED,      //视频认证失败
	EL_INTERAPT,               //视频流中断
	EL_DURATION,               //文件流的时长单位MS
};  

//设备状态
typedef enum {
	DS_FREE = 0,          //空闲
	DS_BUSY,              //占用
	DS_RESERVE,            //预留  暂时没用
	DS_ALARM,              //告警  暂时没用
} VZ_DEVICE_STATUS;


//设备指示灯颜色
typedef enum 
{
	LCT_Red,       //红色
	LCT_Green,     //绿色
	LCT_Blue,      //深蓝色
	LCT_White,     //白色
	LCT_Close,     //灭灯
	LCT_Yellow,    //黄色
	LCT_Perple,    //紫色
	LCT_LowBlue,   //浅蓝色
}VZ_LIGHT_COLOR_TYPE;

//tcp连接状态
typedef enum 
{
	TCS_UNCONNECT,          //未连接
	TCS_CONNECTING,         //连接中
}VZ_TCP_CONNECT_STATUS;

//设备控制模式枚举
typedef enum
{
	DCM_DEVICE,       //设备控制模式
	DCM_USER          //用户控制模式

}VZ_CONTROL_MODE;

//特殊场景显示枚举
typedef enum
{
	SSD_NORMAL,       //2m以上(默认状态)  
	SSD_0,            //0.5-1m           
	SSD_1,            //1-1.5m           
	SSD_2,            //1.5-2m             

}VZ_SPECIAL_SCENE_DISPLAY;

//小图截图模式
typedef enum
{
	SICP_HEAD,      //车头截图
	SICP_BODY       //车身截图
}VZ_SMALL_IMAGE_CAP_MODE;


//停车位状态
typedef enum 
{
	PS_NOHEAD_NOPLATE,        //无车头-无车牌
	PS_HEAD_NOPLATE,          //有车头-无车牌
	PS_NOHEAD_PLATE,          //无车头-有车牌
	PS_HEAD_PLATE             //有车头-有车牌
}VZ_PARK_STATUS;

//触发类型
typedef enum
{
	TT_Auto = 1,        //自动触发
	TT_Hand,            //手动触发
	TT_SOFTWARE,        //软件触发
	TT_VLOOP            //虚拟线圈触发
}VZ_TRIGGER_TYPE;

//设备位置类型
typedef enum 
{
	DP_NONE_POS = 0, //未定义位置(默认位置)
	DP_LEFT_POS, //左转向设备
	DP_RIGTH_POS, //右转向设备
	DP_FRONT_POS //直行设备
} VZ_DEV_POSITION;

//日期格式
typedef enum  
{
	DF_YYYY_MM_DD,      //年月日
	DF_MM_DD_YYYY,      //月日年
	DF_DD_MM_YYYY,      //日月年
}VZ_DATA_FORMAT;

//时间格式
typedef enum  
{
	TF_12Hours,      //12小时
	TF_24Hours,      //24小时
}VZ_TIME_FORMAT;

//注册类型
typedef enum {
	HBT_NONE = 0, //无心跳
	HBT_NORMAL, //普通心跳
	HBT_COMET //Comet 轮询
} VZ_HEART_BEAT_TYPE;



#define  FILTER_BUFFER_MAX_SIZE  32

//设备搜索过滤参数
typedef struct
{
	char name[FILTER_BUFFER_MAX_SIZE];   //设备名字
	char ver[FILTER_BUFFER_MAX_SIZE];    //设备版本
	char sip[FILTER_BUFFER_MAX_SIZE];    //大于等于某个IP
	char eip[FILTER_BUFFER_MAX_SIZE];     //小于等于某个IP
	unsigned int  fnum ;   //停车位数目 2，3
	unsigned int ipfilt ;  //ip筛选规则 
}VZ_DEVICE_FILTER_CFG;


/*设备时间*/
typedef struct  
{
	//unsigned timezone;       //时区
	unsigned year;           //年
	unsigned mon;            //月
	unsigned day;            //日
	unsigned hour;           //小时
	unsigned min;            //分
	unsigned sec;            //秒
}VZ_DEVICE_TIME;

/*视频参数*/
typedef struct  
{
	unsigned brightness;   //亮度
	unsigned contrast;     //对比度
	unsigned saturation;   //饱和度
	unsigned hue;          //色调
	unsigned maxExposure;  //最大曝光
	unsigned maxGain;      //最大增益

}VZ_VIDEO_PARAMETER;

#define  VERSION_BUFF_MAX_SIZE  32

/*设备版本*/
typedef struct 
{
	char softWareVersion[VERSION_BUFF_MAX_SIZE];   //软件版本
	char ukarVerision[VERSION_BUFF_MAX_SIZE];      //ukar版本
	char algVersion[VERSION_BUFF_MAX_SIZE];        //算法版本
	char serialNo[VERSION_BUFF_MAX_SIZE];          //序列号
	char mac[VERSION_BUFF_MAX_SIZE];               //MAC地址
	char hardwareVersion[VERSION_BUFF_MAX_SIZE];   //硬件版本
}VZ_DEVICE_VERSION;




#define    PUSH_ADDR_BUFFER_MAX_SIZE 200
#define    SERVER_BUFFER_MAX_SIZE  32

/*HTTP服务器参数*/
typedef struct 
{
	char serverAddr[SERVER_BUFFER_MAX_SIZE];    //服务器地址
	unsigned port;                  //端口
	unsigned timeout;               //超时时间 ，范围1-3
	unsigned pushEnable;           //推送使能,0为不推送，1为推送
	unsigned bigImageEnable;        //推送大图片使能,0为不推送，1为推送
	unsigned smallImageEnable;      //推送小图片使能,0为不推送，1为推送
	char pushAddr[PUSH_ADDR_BUFFER_MAX_SIZE];   //推送接口地址
}VZ_HTTP_SERVER_PARAMETER;

/*OSD 常用配置*/
typedef struct  
{
	unsigned enable;        //使能,0:不可用，1:可用
	unsigned format;        //格式
	unsigned positionX;     //位置X 范围0-100
	unsigned positionY;     //位置Y 范围0-100
}Vz_OSD_COMMON_ELEMENT;


#define  OSD_TEXT_BUFF_SIZE  128
/*OSD文本配置*/
typedef struct 
{
	unsigned enable;        //文本使能0:不可用，1:可用
	unsigned positionX;     //文本位置X 范围0-100
	unsigned positionY;     //文本位置Y 范围0-100
	char textbuf[OSD_TEXT_BUFF_SIZE];        //文本缓冲区
}VZ_OSD_TEXT_ELEMENT;




/*OSD配置*/
typedef struct 
{
	Vz_OSD_COMMON_ELEMENT  date;    //日期
	Vz_OSD_COMMON_ELEMENT  time;   //时间
	VZ_OSD_TEXT_ELEMENT    text;   //文本
}VZ_OSD_CFG;

/*停车位状态*/
typedef struct  
{
	unsigned total;       //设备总车位数
	unsigned free;        //设备空闲总数
	unsigned nTotal;      //设备未定义车位数
	unsigned nFree;       //设备未定义空闲数
	unsigned lTotal;      //左边设备总车位数
	unsigned lFree;       //左边设备空闲总数
	unsigned rTotal;      //右边设备总车位数
	unsigned rFree;       //右边设备空闲总数
	unsigned fTotal;      //前边设备总车位数
	unsigned fFree;       //前边设备空闲总数
}VZ_PARKING_STATUS;



#define  SUCCESS   0
#define  FAILURE   -1

//点
typedef struct
{
	int  x;    //
	int  y;    //
}VZ_PONT;

//矩形
typedef struct
{
	int left;    //左
	int  top;    //上
	int  right;   //右
	int  bottom;  //下
}VZ_RECT;

//时间值
typedef struct
{
	unsigned dyear;     //年
	unsigned dmon;      //月
	unsigned dday;      //天
	unsigned dhour;      //小时
	unsigned dmin;      //分钟
	unsigned dsec;      //秒

	unsigned  sec;      //秒，时间戳
	unsigned  usec;     //微妙，时间戳
}VZ_TimeVal;

#define    PAKRING_NAME_MAX_SIZE      128
#define    PARKING_LICENSE_MAX_SIZE   32



//单个停车位信息
typedef struct
{
	unsigned isenable;               //是否可用
	unsigned ischange;               //是否改变
	unsigned isparkingin;             //是否进场
	unsigned  triggertype;            //触发类型，详见结构VZ_TRIGGER_TYPE
	unsigned   occupysplitline;        //占线
	char parkingframename[PAKRING_NAME_MAX_SIZE];   //停车位名字 ,GBK编码

	unsigned   parkingstatus;         //停车状态，详见结构VZ_PARK_STATUS
	unsigned   bright;                //明亮
	unsigned   carBright;             //车辆亮度
	unsigned   carColor;              //车辆颜色
	unsigned   colorType;             //颜色类型
	unsigned   colorValue;            //颜色值
	unsigned   confidence;            //置信度
	unsigned   direction;             //方向
	char license[PARKING_LICENSE_MAX_SIZE];            //车牌号，GBK编码

	unsigned     type;                  //类型
	VZ_RECT     location;               //位置
	VZ_TimeVal   timestamp;             //时间戳s
	char*  image;              //图片数据
	unsigned     imageLen;              //图片长度
}VZ_SINGLE_PARKING_INFO;



#define PARKING_SPACE_SIZE 6

//总停车位信息
typedef struct  
{ 
	unsigned short      sysParkingNum;         //设备本身支持的停车位总数目
	VZ_SINGLE_PARKING_INFO  signalParkingInfo[PARKING_SPACE_SIZE];      //单个停车位信息
	char*        bigImage;                 //大图片
	unsigned              bigImageLen;              //大图片长度
}VZ_PARKING_INFO;



#define    IBC_UUID_MAX_SIZE  128

//蓝牙参数
typedef struct
{
	char uuid[IBC_UUID_MAX_SIZE];      //蓝牙uuid字符串
	unsigned short  major;                        //蓝牙major
	unsigned short  minor;                        //蓝牙minor

}VZ_IBC_PARAMETER;



#define  DEVICE_IP_MAX_SIZE            32
#define  DEVICE_NAME_MAX_SIZE          32 
#define  DEVICE_SN_MAX_SIZE            32 
#define  DEVICE_BEACON_MAX_SIZE        32 
#define  DEVICE_MAC_MAX_SIZE           32

//设备IP配置参数
typedef struct
{
	char mac[DEVICE_MAC_MAX_SIZE];           //设备MAC
	char  ip[DEVICE_IP_MAX_SIZE];            //设备IP
	char gateway[DEVICE_IP_MAX_SIZE];		  //网关
	char netmask[DEVICE_IP_MAX_SIZE];		  //字网掩码
}VZ_IP_CONFIG_PARAMTER;



//矩形点
typedef struct
{
	int  leftTopX;       //左上X,范围,0-256
	int  leftTopY;       //左上Y,范围,0-256

	int  leftBottomX;    //左下X,范围,0-256
	int  leftBottomY;    //左下Y,范围,0-256

	int  rightTopX;      //右上X,范围,0-256
	int  rightTopY;      //右上Y,范围,0-256

	int  rightBottomX;   //右下X,范围,0-256
	int  rightBottomY;   //右下Y,范围,0-256
}VZ_RECT_POINT;

//停车位区域配置
typedef struct  
{
	char  name[PAKRING_NAME_MAX_SIZE];    //停车位名字
	unsigned   enable;                         //可用
	VZ_RECT_POINT  rect;                  //矩形 
}VZ_PARKING_AREA_CFG;


//父节点设备信息
typedef struct
{
	char  ip[DEVICE_IP_MAX_SIZE];      //设备IP
	unsigned short  pos;              //位置,详见结构VZ_DEV_POSITION

}VZ_DEVICE_DST_NODE;

#define    DEST_NODE_MAX_SIZE  4  

//设备参数
typedef struct
{
	char  ip[DEVICE_IP_MAX_SIZE];            //设备IP
	char name[DEVICE_NAME_MAX_SIZE];          //设备名字
	char sn[DEVICE_SN_MAX_SIZE];              //设备序列号
	char ibeacon[DEVICE_BEACON_MAX_SIZE];     //设备蓝牙ID
	char mac[DEVICE_MAC_MAX_SIZE];                    //设备MAC
	char uuid[IBC_UUID_MAX_SIZE];      //蓝牙uuid
	int  major;                        //蓝牙major
	int  minor;                        //蓝牙minor
}VZ_DEVICE_PARAMTER;

//设备关系
typedef struct 
{
	VZ_DEVICE_PARAMTER DeviceParam;    //设备参数
	VZ_DEVICE_DST_NODE  DstNodeList[DEST_NODE_MAX_SIZE]; //目的设备列表
}VZ_DEVICE_RELATION;


//停车位外控灯配置
typedef struct  
{
	unsigned short enble;           //启用外控标志,0,不启用，1,启用
	unsigned short freeLedColor;    //空闲灯颜色 ,对应枚举VZ_LIGHT_COLOR_TYPE
	unsigned short occupyLedColor;   //占用灯颜色 ,对应枚举VZ_LIGHT_COLOR_TYPE
}VZ_PARKING_COLOR_CFG;

//停车位外部设备控制配置
typedef struct
{
	unsigned short enble;             //启用标志,0,不可用，1,可用
	char  ip[DEVICE_IP_MAX_SIZE];            //设备IP
}VZ_PARKING_EXT_DEVICE_CFG;

//设备网络参数配置
typedef struct
{ 
	char  ip[DEVICE_IP_MAX_SIZE];                 //设备IP
	char  netmask[DEVICE_IP_MAX_SIZE];            //设备掩码
	char  gateway[DEVICE_IP_MAX_SIZE];            //设备网关
	char  dnsserver[DEVICE_IP_MAX_SIZE];          //设备DNS SERVER
}VZ_PARKING_DEVICE_NET_CFG;

//串口外部参数
typedef struct
{ 
	unsigned short protocl;       //协议号
	unsigned short fEnable;       //直行可用,1可用，0不可用
	unsigned short fAddrNum;       //直行屏地址号，范围:0-255
	unsigned short rEnable;       //右转可用,1可用，0不可用
	unsigned short rAddrNum;       //右转屏地址号，范围:0-255
	unsigned short lEnable;       //左转可用,1可用，0不可用
	unsigned short lAddrNum;       //左转屏地址号，范围:0-255
}VZ_SERIAL_EXT_PARAMETER;

//http车牌重发配置(重发最后一次车牌识别信息的配置)
typedef struct  
{
	short enable;           //启用标志,0,不启用，1,启用
	short repeatetime;     //重发时间,范围:60-600,单位:秒
}VZ_HTTP_PLATE_REPEAT_CFG;


//串口推送配置类型
typedef enum
{
	VZ_SERIAL_NOTYPE = 0,			
	VZ_SERIAL_LICENSEENABLE,	//有无车牌是否启用 0:不启用，1:启用（1 字节：0xAA为可识别，0xBB为不可识别）
	VZ_SERIAL_LICENSE,			//车牌号是否启用 0:不启用，1:启用（汉字编码参考文档，普通字符为ASCII）
	VZ_SERIAL_LICENSECOLOR,		//车牌颜色是否启用 0:不启用，1:启用（1 字节：00蓝色 01黄色 02黑色 03白色 04其他备用）
	VZ_SERIAL_CONFIDENCE,		//车牌可信度是否启用 0:不启用，1:启用（1 字节：车牌置信度，最多分数 100）
	VZ_SERIAL_LICENSETYPE,		//车牌类型是否启用 0:不启用，1:启用（1 字节：0:未知车牌,1:蓝牌小汽车,2:黑牌小汽车,详细参看文档）
	VZ_SERIAL_TRIGGER,			//触发类型是否启用 0:不启用，1:启用（1 字节：1:自动,2:手动触发）
	VZ_SERIAL_CARCOLOR,			//车辆颜色是否启用 0:不启用，1:启用（1 字节：00蓝色 01黄色 02黑色 03白色 04其他备用
	VZ_SERIAL_TIME,				//识别时间点是否启用 0:不启用，1:启用（4 字节：车牌识别发生的时间时间戳）
	VZ_SERIAL_FRAME_NAME,       //车位名称是否启用 0:不启用，1:启用（不支持汉字输出，普通字符为 ASCII）
	VZ_SERIAL_FRAME_STATUS,     //车位状态是否启用 0:不启用，1:启用（1 字节：0：无车头无车牌-1：有车头无车牌-2：无车头有车牌 -3：有车头有车牌）
	VZ_SERIAL_OCCUPY_LINE,      //占线状态是否启用 0:不启用，1:启用（1 字节：1 为占线，0 为不占线）
	VZ_SERIAL_HEAD_CONF,        //车头可信度是否启用 0:不启用，1:启用（1 字节：车头置信度，最多分数 100）
	VZ_SERIAL_FREE_NUM,         //空闲车位数是否启用 0:不启用，1:启用（4 字节：空闲车位数）
	VZ_SERIAL_FRAME_NUM,        //总车位数是否启用 0:不启用，1:启用（4 字节：总车位数）

	VZ_SERIAL_CHECKBEGIN,		//校验起始位
	VZ_SERIAL_CHECKEND,			//校验结束位
	VZ_SERIAL_CHECKSUM,			//校验位

	VZ_SERIAL_TYPELEN			//推送项长度

}VZ_SERIAL_PUSH_TYPE;

//串口协议配置项
typedef struct 
{ 
	int          item_type;     //串口推送类型,详见枚举VZ_SERIAL_PUSH_TYPE                          

	int           val;          //串口推送项的值，参照枚举VZ_SERIAL_PUSH_TYPE的解释                            

}VZ_SERIAL_PROTOCOL_ITEM;

#define  SERIAL_PUSH_TYPE_LEN 17
#define  SERIAL_PUSH_BUFFER_MAX_SIZE 64

//串口协议配置
typedef  struct
{ 
	VZ_SERIAL_PROTOCOL_ITEM              configItem[SERIAL_PUSH_TYPE_LEN];                                                             
	char                                 header[SERIAL_PUSH_BUFFER_MAX_SIZE];       //标志头                                                         
	char                                 end[SERIAL_PUSH_BUFFER_MAX_SIZE];          //标志尾                                                                                                                               
}VZ_SERIAL_PROTOCOL_CFG;

//中断/恢复原本设备控制的串口输出类型
typedef enum  
{
	VZ_ORIGIN_SERIAL_HALT_RESTORE,            //恢复设备串口输出
	VZ_ORIGIN_SERIAL_HALT_INTERRUPT           //中断设备串口输出
}VZ_ORIGIN_SERIAL_HALT_TYPE;

//重置配置等级类型
typedef enum 
{
	RCLT_ALL,          //所有配置恢复默认
	RCLT_PART          //部分恢复默认（除网络参数/用户名密码/设备名称外，都恢复默认）
}VZ_RESET_CONFIG_LEVEL_TYPE;


//HTTP心跳配置类型
typedef struct 
{
	int heartBeatType;  //心跳类型,详见VZ_HEART_BEAT_TYPE
	short pushCycle;    //推送周期（s），范围 30 - 120
	char pushAddr[PUSH_ADDR_BUFFER_MAX_SIZE];   //推送接口地址
}VZ_HTTP_HEART_BEAT_CFG;


#define  NET_ADDR_MAX_SIZE 128
//ntp服务器
typedef struct 
{
	char serverAddr[NET_ADDR_MAX_SIZE];   //ntp服务器地址
	int  enable;                   //是否可用
	int  interval;                //间隔   (1s-24小时)

}VZ_NTP_SERVER_CFG;

//tcp server 配置
typedef struct 
{
	int  enable;                   //是否可用  0:不可用，1:可用
	char ip[DEVICE_IP_MAX_SIZE];    //tcp server ip
	unsigned port;                  //服务器端口

}VZ_TCP_SERVER_CFG;
#endif
