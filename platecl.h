#ifndef PLATECL_H
#define PLATECL_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QtConcurrent>

#include "inc/VzLPRClientSDK.h"
#include "inc/VzLPRClientSDK_WhiteListDefine.h"
#include "inc/VzLPRClientSDK_WhiteList.h"

class PlateCL:public QObject
{
    Q_OBJECT

public:
    PlateCL(QMap<int,QStringList> cameraPar,QString imgPath);
    ~PlateCL();
        
    ///
    /// \brief CommonNotityCallBack 通用回调函数
    /// \param handle
    /// \param pUserData
    /// \param eNotify
    /// \param pStrDetail
    ///
    static void CommonNotityCallBack(VzLPRClientHandle handle, void *pUserData, VZ_LPRC_COMMON_NOTIFY eNotify, const char *pStrDetail);

    ///
    /// \brief PlateInfoCallBack 车牌结果回调函数
    /// \param handle
    /// \param pUserData
    /// \param pResult
    /// \param uNumPlates
    /// \param eResultType
    /// \param pImgFull
    /// \param pImgPlateClip
    /// \return
    ///
    static int PlateInfoCallBack(VzLPRClientHandle handle, void *pUserData, const TH_PlateResult *pResult, unsigned  uNumPlates, VZ_LPRC_RESULT_TYPE  eResultType, const VZ_LPRC_IMAGE_INFO  *pImgFull, const VZ_LPRC_IMAGE_INFO  *pImgPlateClip);
      

private:
    
    static PlateCL* pThis;   
        
    ///
    /// \brief imgPath 图片路径
    ///
    QString imgPath;
    
    ///
    /// \brief cameraPar 相机参数
    ///
    QMap<int,QStringList> cameraPar;
    
    ///
    /// \brief cameraPort 相机端口
    ///
    int cameraPort;
    
    ///
    /// \brief ret 初始化状态
    ///
    int ret;
    
    /*****************************
    * @brief:登录句柄
    ******************************/
    int handle1,handle2,handle3,handle4,handle5,handle6;
    
    /*****************************
    * @brief:播放句柄
    ******************************/
    int rHandle1,rHandle2,rHandle3,rHandle4,rHandle5,rHandle6;

    ///
    /// \brief handMap 登录句柄MAP
    ///
    QMap<int,VzLPRClientHandle> handMap;
    
    ///
    /// \brief rHandMap 播放句柄MAP
    ///
    QMap<int,VzLPRClientHandle> rHandMap;

private:    
    
    ///
    /// \brief initializingCamera 初始化相机
    ///
    void initializingCamera();    
    
    ///
    /// \brief resumeShows 恢复显示屏默认显示
    ///
    void resumeShows();
    
    /*****************************
    * @brief:字符串转换16进制
    ******************************/
    QByteArray hexStringtoByteArray(QString hex);
    void formatString(QString &org, int n, const QChar &ch);
    
public slots:
    
    ///
    /// \brief slotUpWhiteList 上传白名单
    ///
    void slotUpWhiteList(QMap<int,QMap<QString,QString>> wlst);

    ///
    /// \brief slotUgWhiteList 更新白名单
    ///
    void slotUgWhiteList(QMap<int,QMap<QString,QString>> wlst);      

    ///
    /// \brief signalDeWhiteList 删除白名单
    ///
    void slotDeWhiteList(QMap<int,QMap<QString,QString>> wlst);
    
    ///
    /// \brief slotPushShow 推送车牌显示
    /// \param msg
    ///
    void slotPushShow(int channel , QByteArray arr, int type);

    ///
    /// \brief slotDoSomething 操作相机指令
    /// \param channel
    ///
    void slotDoSomething(int channel, int type, quintptr Wid);
    
signals:
    
    ///
    /// \brief signalPlateResult 车牌结果
    /// \param channel
    /// \param plate
    /// \param color
    ///
    void signalPlateResult(int channel, QString plate, int color, QByteArray imgArr);
    
};

#endif // PLATECL_H
