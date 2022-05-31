#ifndef _VZ_CLIENT_SDK_LP_DEFINE_H_
#define _VZ_CLIENT_SDK_LP_DEFINE_H_
#include <inc/VzClientSDK_CommonDefine.h>

// 车牌识别相关参数
//---------------------------------------//
//车牌颜色
#define LC_UNKNOWN  0  //未知
#define LC_BLUE     1  //蓝色
#define LC_YELLOW   2  //黄色 
#define LC_WHITE    3  //白色
#define LC_BLACK    4  //黑色
#define LC_GREEN    5  //绿色

//车牌类型
#define LT_UNKNOWN  0   //未知车牌
#define LT_BLUE     1   //蓝牌小汽车
#define LT_BLACK    2   //黑牌小汽车
#define LT_YELLOW   3   //单排黄牌
#define LT_YELLOW2  4   //双排黄牌（大车尾牌，农用车）
#define LT_POLICE   5   //警车车牌
#define LT_ARMPOL   6   //武警车牌
#define LT_INDIVI   7   //个性化车牌
#define LT_ARMY     8   //单排军车牌
#define LT_ARMY2    9   //双排军车牌
#define LT_EMBASSY  10  //使馆车牌
#define LT_HONGKONG 11  //香港进出中国大陆车牌
#define LT_TRACTOR  12  //农用车牌
#define LT_COACH	13  //教练车牌
#define LT_MACAO	14  //澳门进出中国大陆车牌
#define LT_ARMPOL2   15 //双层武警车牌
#define LT_ARMPOL_ZONGDUI 16  // 武警总队车牌
#define LT_ARMPOL2_ZONGDUI 17 // 双层武警总队车牌
#define LI_AVIATION  18   //民航
#define LI_ENERGY    19   //新能源

//运动方向
#define DIRECTION_LEFT	1  //左
#define DIRECTION_RIGHT	2  //右
#define DIRECTION_UP	3  //上
#define DIRECTION_DOWN	4  //下

//图像格式（TH_SetImageFormat函数的cImageFormat参数）
#define ImageFormatRGB		0			//RGBRGBRGB...
#define ImageFormatBGR		1			//BGRBGRBGR...
#define ImageFormatYUV422	2			//YYYY...UU...VV..	(YV16)
#define ImageFormatYUV420COMPASS 3		//YYYY...UV...		(NV12)
#define ImageFormatYUV420	4			//YYYY...U...V...	(YU12)
#define ImageFormatUYVY	    5			//UYVYUYVYUYVY...	(UYVY)
#define ImageFormatNV21		6			//YYYY...VU...		(NV21)
#define ImageFormatYV12		7			//YYYY...V...U		(YV12)
#define ImageFormatYUYV	    8			//YUYVYUYVYUYV..	(YUYV)
#define ImageFormatJPG	    9			//YUYVYUYVYUYV..	(YUYV)

//车辆颜色
#define LGRAY_DARK	0	//深
#define LGRAY_LIGHT	1	//浅

#define LCOLOUR_WHITE	0	//白	
#define LCOLOUR_SILVER	1	//灰(银)
#define LCOLOUR_YELLOW	2	//黄
#define LCOLOUR_PINK	3	//粉
#define LCOLOUR_RED		4	//红
#define LCOLOUR_GREEN	5	//绿
#define LCOLOUR_BLUE	6	//蓝
#define LCOLOUR_BROWN	7	//棕 
#define LCOLOUR_BLACK	8	//黑

// 触发识别类型定义
typedef enum _TH_TRIGGER_TYPE
{
	TRIGGER_TYPE_AUTO		=	0,		//自动
	TRIGGER_TYPE_EXTERNAL	=	1,		//外部
	TRIGGER_TYPE_SOFTWARE	=	2,		//软件
	TRIGGER_TYPE_VLOOP					//虚拟地感线圈
}TH_TRIGGER_TYPE;

typedef enum
{
	TRIGGER_TYPE_AUTO_BIT		= 1,    //自动
	TRIGGER_TYPE_EXTERNAL_BIT	= 1<<1, //外部
	TRIGGER_TYPE_SOFTWARE_BIT	= 1<<2, //软件
	TRIGGER_TYPE_VLOOP_BIT		= 1<<3  //虚拟地感线圈
}TH_TRIGGER_TYPE_BIT;

/**矩形区域信息*/
typedef struct TH_RECT
{
	int left;	/**<左*/
	int top;	/**<上*/
	int right;	/**<右*/
	int bottom;	/**<下*/
}TH_RECT;

typedef struct TH_TimeVal
{
	long    tv_sec;         /* 秒 */
	long    tv_usec;        /* 微秒 */
	long	tv_frameStamp;	/* 帧编号 */
}TH_TimeVal;

typedef struct
{
	unsigned uTVSec;
	unsigned uTVUSec;
}
VZ_TIMEVAL;

typedef struct CarBrand
{
	char brand;     // 品牌
	char type;      // 车型
	unsigned short year;      // 年份
} CarBrand;

#define TH_LP_LEN	16

/**车牌识别结果信息*/
typedef struct TH_PlateResult 
{
	char license[TH_LP_LEN];  	/**<车牌号码*/
	char color[8];      		/**<车牌颜色*/
	int nColor;					/**<车牌颜色序号，详见车牌颜色定义LC_X*/
	int nType;					/**<车牌类型，详见车牌类型定义LT_X*/
	int nConfidence;			/**<车牌可信度*/
	int nBright;				/**<亮度评价*/
	int nDirection;				/**<运动方向，详见运动方向定义 DIRECTION_X*/
	TH_RECT rcLocation; 		/**<车牌位置*/
	int nTime;          		/**<识别所用时间*/
	VZ_TIMEVAL tvPTS;			/**<识别时间点*/
	unsigned uBitsTrigType;		/**<强制触发结果的类型,见TH_TRIGGER_TYPE_BIT*/
	unsigned char nCarBright;	/**<车的亮度*/
	unsigned char nCarColor;	/**<车的颜色，详见车辆颜色定义LCOLOUR_X*/
	char reserved0[2]; 			/**<为了对齐*/
	unsigned uId; 				/**<记录的编号*/
	VzBDTime    struBDTime;     /**<分解时间*/
	unsigned char nIsEncrypt;          /**<车牌是否加密*/
	unsigned char nPlateTrueWidth;     /**<车牌的真实宽度，单位cm*/
	unsigned char nPlateDistance;      /**<车牌距离相机的位置，单位dm(分米)*/
	unsigned char nIsFakePlate;        /**是否是伪车牌*/
	TH_RECT     car_location;   /**<车辆位置*/
	CarBrand    car_brand;      /**<车辆品牌*/
	char featureCode[20];       /**<车辆特征码*/
	char reserved1[24];			/**<保留*/
}TH_PlateResult;

/**车牌识别结果在通过白名单验证的结果*/
typedef enum
{
    VZ_LPWL_UNHANDLE,       /**<未处理*/
    VZ_LPWL_VALID,          /**<在白名单中，且有效*/
    VZ_LPWL_INVALID,        /**<不在白名单中，或验证未通过*/
    VZ_LPWL_NO_LICENCE,     /**<无车牌*/
    VZ_LPWL_BLACK_LIST,     /**<黑名单*/
    VZ_LPWL_DISABLE,        /**<在白名单中，但记录无效*/
    VZ_LPWL_START_TIMEOUT,  /**<在白名单中，但记录还未到起始有效期*/
    VZ_LPWL_END_TIMEOUT,    /**<在白名单中，但记录超过结束有效期*/
    VZ_LPWL_SEG_TIMEOUT,    /**<在白名单中，但记录不在有效时间段内*/
    VZ_LPWL_RESULT_COUNT,
}
VZ_LPWL_RESULT;

/**车牌识别结果的白名单信息扩展*/
typedef struct
{
    VzBDTime struTimeOverdue;   /**<白名单对应记录过期时间*/
    char strComment[32];        /**<授权号*/
    char strCode[64];           /**<用户ID*/
    unsigned char ucWLResult;   /**<白名单检验状态，详见白名单验证结果定义*/
    unsigned char ucRes[3];
}
VZ_LPWL_INFO;

#define ENCRYPT_NAME_LENGTH 32

/**加密类型**/
typedef struct
{
	unsigned uId;						//加密ID
	char sName[ENCRYPT_NAME_LENGTH];	//加密名
}VZ_EMS_INFO;

#define ENCRYPT_LENGTH 16
#define SIGNATURE_LENGTH 32

/**当前识别结果加密类型**/
typedef struct
{
	unsigned uActiveID;						//当前加密类型ID
	VZ_EMS_INFO oEncrpty[ENCRYPT_LENGTH];	//系统加密类型
	unsigned uSize;							//系统加密类型长度
	char signature[SIGNATURE_LENGTH];		//SIGNATURE
}VZ_LPRC_ACTIVE_ENCRYPT;

/**********当前已连接设备信息**************/
#define IPADDR_LENGTH 16
#define OVZID_NAME_LEN 385
#define SN_LEN 32

typedef struct
{
	unsigned enable_group;				// 是否加入组网
	char ip_addr[IPADDR_LENGTH];		// 设备IP
	char name[OVZID_NAME_LEN];			// 组网的名称
	char original_name[OVZID_NAME_LEN];	// 未解密之前的名称
	char sn[SN_LEN];					// 设备序列号
	unsigned type;						// 0未组网，1进口设备, 2出口设备
}VZ_OVZID_INFO;

#define OVZID_COUNT 64
typedef struct
{
	VZ_OVZID_INFO info[OVZID_COUNT];
	unsigned uCount;
}VZ_OVZID_RESULT;


//组网设备信息
typedef struct
{
	char vzName[128];               //识别结果来源设备名称
	char vzIP[16];                  //识别结果来源设备IP
	char vzSN[24];                  //识别结果来源设备序列号
	char vzType;                    //组网识别结果设备类型，0 : 入口 1 ： 出口
} IVS_DG_DEVICE_INFO;

/**可过滤的车牌识别触发类型*/
#define VZ_LPRC_TRIG_ENABLE_STABLE      0x1     /**<允许触发稳定结果*/
#define VZ_LPRC_TRIG_ENABLE_VLOOP       0x2     /**<允许触发虚拟线圈结果*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN1      0x10    /**<允许外部IO_IN_1触发*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN2      0x20    /**<允许外部IO_IN_2触发*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN3      0x40    /**<允许外部IO_IN_3触发*/


#define   LPRC_CENTER_IPLEN  200
typedef struct      //中心服务器网络
{
	char centerServerIp[LPRC_CENTER_IPLEN];   //中心服务器地址
	WORD port;                         //中心服务器端口
	bool enableSsl;                    //是否使用ssl协议
	WORD sslPort;                      //ssl协议端口 
	WORD timeout;                      //超时时间设置错误, 范围【1~30】

}VZ_LPRC_CENTER_SERVER_NET;

#define  URLLENGTH 1000
typedef struct      //中心服务器网络设备注册
{
	BYTE type;                         //中心服务器设备注册类型
	char url[URLLENGTH];               //中心服务器设备注册地址
}VZ_LPRC_CENTER_SERVER_DEVICE_REG;

typedef struct       //中心服务器网络车牌
{
	char url[URLLENGTH];               //中心服务器车牌地址
	bool enable;                       //中心服务器车牌推送使能
	BYTE contentLevel;                 //中心服务器车牌内容详细等级
	bool sendLargeImage;               //中心服务器车牌是否发送大图片
	bool sendSmallImage;               //中心服务器车牌是否发送小图片
}VZ_LPRC_CENTER_SERVER_PLATE;

typedef struct						   //中心服务器网络设备端口触发
{
	bool enable;                       //中心服务器网络设备端口触发使能
	char url[URLLENGTH];               //中心服务器网络设备端口触发地址
}VZ_LPRC_CENTER_SERVER_GIONIN;

typedef struct      //中心服务器网络设备串口
{
	bool enable;                         //中心服务器网络设备串口使能
	char url[URLLENGTH];               //中心服务器网络设备串口地址
}VZ_LPRC_CENTER_SERVER_SERIAL;

typedef struct
{
	int default_stream;  /* 当前选择的码流 */
	int stream_id;       /* 码流类型 */
	int resolution;      /* 分辨率; */
	int frame_rate;      /* [0, 25]，帧率; */
	int encode_type;     /* h264; */
	int rate_type;       /* 码流类型，对应码流控制; */
	int data_rate;       /* 码流上限; */
	int video_quality;   /* 视频质量; */
}VZ_LPRC_R_ENCODE_PARAM;

#define  VZ_LPRC_MAX_RESOLUTION 12
#define  VZ_LPRC_MAX_RATE 5
#define  VZ_LPRC_MAX_VIDEO_QUALITY 12
#define  VZ_LPRC_MAX_ENCODE_TYPE 5
#define  VZ_LPRC_MAX_STREAM_TYPE 5
#define  VZ_LPRC_MAX_STREAM_COUNT 5

typedef struct
{
	int resolution_type;			/* 码流类型 */
	char resolution_content[32];    /* 码流类型 */

}VZ_LPRC_R_RESOLUTION;

typedef struct
{
	int rate_type_value;				
	char rate_type_content[32];

}VZ_LPRC_R_RATE_TYPE;

typedef struct
{
	int video_quality_type;
	char video_quality_content[32];
}VZ_LPRC_R_VIDEO_QUALITY;

typedef struct
{
	int encode_stream;												/* 当前选择的码流 */
	int resolution_cur;				/* 分辨率   */
	VZ_LPRC_R_RESOLUTION resolution[VZ_LPRC_MAX_RESOLUTION];		/* 分辨率	*/			
	int frame_rate_cur;												/* 当前帧率; */
	int frame_rate_min;												/* 最小帧率; */
	int frame_rate_max;												/* 最大帧率; */
	int rate_type_cur;							/* 码率控制 */
	VZ_LPRC_R_RATE_TYPE rate_type[VZ_LPRC_MAX_RATE];
	int data_rate_cur;												/* 码流上限; */
	int data_rate_min;							
	int data_rate_max;
	int video_quality_cur;						/* 视频质量; */
	VZ_LPRC_R_VIDEO_QUALITY video_quality[VZ_LPRC_MAX_VIDEO_QUALITY];

}VZ_LPRC_R_ENCODE_PARAM_PROPERTY;

typedef struct
{
	int encode_type;
	char content[32];
}VZ_LPRC_ENCODE_TYPE;

typedef struct
{
	int encode_stream;												/* 当前选择的码流 */
	int resolution_cur;												/* 分辨率   */
	VZ_LPRC_R_RESOLUTION resolution[VZ_LPRC_MAX_RESOLUTION];		/* 分辨率	*/			
	int frame_rate_cur;												/* 当前帧率; */
	int frame_rate_min;												/* 最小帧率; */
	int frame_rate_max;												/* 最大帧率; */
	int rate_type_cur;												/* 码率控制 */
	VZ_LPRC_R_RATE_TYPE rate_type[VZ_LPRC_MAX_RATE];
	int data_rate_cur;												/* 码流上限; */
	int data_rate_min;							
	int data_rate_max;
	int video_quality_cur;											/* 视频质量; */
	VZ_LPRC_R_VIDEO_QUALITY video_quality[VZ_LPRC_MAX_VIDEO_QUALITY];
	int encode_type_cur;
	VZ_LPRC_ENCODE_TYPE encode_type[VZ_LPRC_MAX_ENCODE_TYPE];
}VZ_LPRC_ENCODE_STREAM;

typedef struct
{
	int stream_type;
	char content[32];
}VZ_LPRC_STREAM_TYPE;

typedef struct
{
	int stream_cur;
	VZ_LPRC_STREAM_TYPE stream_type[VZ_LPRC_MAX_STREAM_TYPE];
	VZ_LPRC_ENCODE_STREAM encode_stream[VZ_LPRC_MAX_STREAM_COUNT];
}VZ_LPRC_ENCODE_PROP;

typedef struct
{
	int brightness; 
	int contrast;  
	int saturation;
	int sharpness; 
	int hue;     
	int exposure;
	int max_exposure;
	int gain;
	int max_gain; 
	int denoise;
	int flip;
	int frquency;
	int night_mode;
}VZ_LPRC_R_VIDEO_PARAM;

#define  VZ_LPRC_MAX_TIME_CTRL 3
#define  VZ_LPRC_MAX_TIME_LEN  16
#define  VZ_LPRC_MAX_LED_LEVEL 10
#define  VZ_LPRC_MAX_LED_MODE  5

typedef struct
{
	int id; 
	char time_begin[VZ_LPRC_MAX_TIME_LEN];
	char time_end[VZ_LPRC_MAX_TIME_LEN];
	int  led_level;
	int timectrl_enable;

}VZ_LPRC_TIME_CTRL_PARAM;


typedef struct
{
	int led_mode; 
	int led_level;
	VZ_LPRC_TIME_CTRL_PARAM time_ctrl[VZ_LPRC_MAX_TIME_CTRL];
}VZ_LPRC_CTRL_PARAM;

typedef struct
{
	int type; 
	char content[32];
}VZ_LPRC_LED_LEVEL_ITEM;

typedef struct
{
	int type; 
	char content[32];
}VZ_LPRC_LED_MODE_ITEM;

typedef struct
{
	VZ_LPRC_LED_LEVEL_ITEM level_items[VZ_LPRC_MAX_LED_LEVEL];
	VZ_LPRC_LED_MODE_ITEM mode_items[VZ_LPRC_MAX_LED_MODE];
}VZ_LPRC_LED_PROP;

typedef struct tagTH_ImgInfo
{
	char imt_type[12];		// 图像类型 如：bmp,jpg,jpeg
	unsigned char* img_buf; // 图像buf
	unsigned int img_len;	// 图像长度
}TH_ImgInfo;

#endif
