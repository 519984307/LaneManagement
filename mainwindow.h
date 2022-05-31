#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QComboBox>
#include <QLineEdit>
#include <QDebug>
#include <QSettings>
#include <QDir>
#include <QCloseEvent>
#include <QResizeEvent>
#include <QPointer>
#include <QTimer>
#include <QPalette>
#include <QScopedPointer>
#include <QBrush>
#include <QPixmap>
#include <QtConcurrent>

#include "inc/VzLPRClientSDK.h"
#include "LogController/logcontroller.h"
#include "logform.h"
#include "databaseform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    Ui::MainWindow *ui;
    static MainWindow* pThis;    
    QComboBox* comboBox;

    ///
    /// \brief ret 初始化状态
    ///
    int ret;

    ///
    /// \brief logFrom 日志页面
    ///
    LogForm logFrom;

    ///
    /// \brief pUserData 用户数据
    ///
    void *pUserData;

    ///
    /// \brief Log 日志类
    ///
    QPointer<LogController> pLog;

    ///
    /// \brief dataFrom 数据库页面
    ///
    QSharedPointer<DataBaseForm> dataFrom;

    ///
    /// \brief cameraPort 相机端口
    ///
    int cameraPort;

    QString addr1,addr2,addr3,addr4,addr5,addr6;
    QString user1,user2,user3,user4,user5,user6;
    QString poww1,poww2,poww3,poww4,poww5,poww6;

    QMap<int,QStringList> CameraParmenterMap;

    int handle1,handle2,handle3,handle4,handle5,handle6;
    int rHandle1,rHandle2,rHandle3,rHandle4,rHandle5,rHandle6;

    QMap<int,VzLPRClientHandle> handMap;
    QMap<int,VzLPRClientHandle> rHandMap;

    QMap<int,WId> winIDMap;

    ///
    /// \brief path 图片路径
    ///
    QString path;

    ///
    /// \brief initParmeter 初始化参数
    ///
    void initParmeter();

    ///
    /// \brief initializingCamera 初始化相机
    ///
    void initializingCamera();

private slots:

    void on_actionLog_triggered();
    void on_actionDataBase_triggered();
    void on_actionCapture_triggered();
    void on_actionLifting_triggered();
    void on_actionPlay_triggered();
    void on_actionLogin_triggered();
    void on_actionClose_triggered();
};
#endif // MAINWINDOW_H
