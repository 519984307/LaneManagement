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
#include <QCloseEvent>
#include <QResizeEvent>
#include <QReadWriteLock>
//#include <QtTextToSpeech/QTextToSpeech>

#include "LogController/logcontroller.h"
#include "logform.h"
#include "databaseform.h"
#include "database.h"
#include "platecl.h"
#include "lockdialog.h"
#include "postdata.h"
#include "tcpserver.h"
#include "audioserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent* event)Q_DECL_OVERRIDE;

private:

    Ui::MainWindow *ui;
    QComboBox* comboBox;

    //QTextToSpeech *tts;

    ///
    /// \brief pTcpServer 接收集装箱通道数据
    ///
    TcpServer* pTcpServer;

    ///
    /// \brief pAudio 音频类
    ///
    QMap<int ,AudioServer*> audioMap;

    ///
    /// \brief postDa 数据请求
    ///
    PostData* postDa;

    ///
    /// \brief plateList 拉取白名单列表
    ///
    QStringList plateList;

    ///
    /// \brief localWhilte 白名单状态
    ///
    bool localWhilte;

    ///
    /// \brief allOut 出闸校验状态
    ///
    bool allOut;

    ///
    /// \brief allIn 进闸校验状态
    ///
    bool allIn;
    
    ///
    /// \brief yellowPlatePass 黄牌车是否处理
    ///
    bool yellowPlatePass;

    ///
    /// \brief administrativeChannel 行政车辆
    ///
    bool administrativeChannel;

    ///
    /// \brief imgPath 图片路径
    ///
    QString imgPath;

    ///
    /// \brief httpAddr 数据接口地址
    ///
    QString httpAddr;

    ///
    /// \brief PL 车牌处理类
    ///
    QSharedPointer<PlateCL> plateC;

    ///
    /// \brief logFrom 日志页面
    ///
    LogForm logFrom;

    ///
    /// \brief pDataBase 数据库处理类
    ///
    DataBase* pDataBase;

    ///
    /// \brief Log 日志类
    ///
    QPointer<LogController> pLog;

    ///
    /// \brief dataFrom 数据库页面
    ///
    QSharedPointer<DataBaseForm> dataFrom;

    ///
    /// \brief cameraPar 相机参数
    ///
    QMap<int,QStringList> cameraPar;

    ///
    /// \brief audioPar 音频参数
    ///
    QMap<int,QStringList> audioPar;
    
    ///
    /// \brief winIDMap 视频播放句柄
    ///
    QMap<int,WId> winIDMap;

    ///
    /// \brief timerMap 定时恢复显示屏定时器组
    ///
    QMap<int,QTimer*> timerMap;

    ///
    /// \brief plateLiftMap 判断已抬杆的车牌
    ///
    QMap<int,QString> plateLiftMap;

    ///
    /// \brief db 白名单数据库对象
    ///
    QSqlDatabase db;

    ///
    /// \brief locker
    ///
    QReadWriteLock locker;

    ///
    /// \brief imgArrMap 图片列表，供重绘使用
    ///
    QMap<int,QByteArray> imgArrMap;

    ///
    /// \brief TimerForWhite 轮询获取白名单
    ///
    QTimer* timerForWhite;
              
    ///
    /// \brief initParmeter 初始化参数
    ///
    void initParmeter();

    ///
    /// \brief send485Data 485透明传输
    /// \param msg
    ///
    void sendRs485Data(QString plate, int channel);

    /*****************************
    * @brief:字符串转换16进制
    ******************************/
    void formatString(QString &org, int n, const QChar &ch);
    QByteArray hexStringtoByteArray(QString hex);
    QByteArray strToHex(QString str);
    QByteArray bgkToHex(QString str);

signals:

    ///
    /// \brief signalInitDataBase 初始化数据库.如果不存在,就创建.
    /// \param connectName 链接名称
    /// \param user 用户名
    /// \param pass密码
    /// \param ip 地址
    /// \param dataBaseType 数据库类型
    ///
    void signalInitDataBase(const QString &connectName,const QString &user,const QString &pass,const QString &ip,const int &dataBaseType);

    ///
    /// \brief signalInsertDataBase 插入数据库
    /// \param data
    ///
    void signalInsertDataBase(QMap<QString, QString> data);
    
    ///
    /// \brief signalPushShow 推送车牌显示
    /// \param msg
    ///
    void signalPushShow(int hand ,QByteArray arr,int type);

    ///
    /// \brief signalDoSomething 操作相机指令
    /// \param channel
    ///
    void signalDoSomething(int channel,int type, quintptr Wid);

    ///
    /// \brief signalPostData 请求数据
    /// \param data
    ///
    void signalPostData(QByteArray data);

    ///
    /// \brief signalSendAudio 发送车牌数据
    /// \param data
    ///
    void signalSendAudio(int channel,QByteArray data);

    ///
    /// \brief toSendDataSignal 发送音频数据
    /// \param channel_number
    /// \param data
    ///
    void toSendDataSignal(int channel_number,const QString &data);

private slots:

    void on_actionLog_triggered();
    void on_actionDataBase_triggered();
    void on_actionCapture_triggered();
    void on_actionLifting_triggered();
    void on_actionPlay_triggered();
    void on_actionLogin_triggered();
    void on_actionClose_triggered();
    void on_actionSetting_triggered();
    void on_actionLock_triggered();
    
    ///
    /// \brief slotPlateResult 车牌结果
    /// \param channel
    /// \param plate
    /// \param color
    ///
    void slotPlateResult(int channel, QString plate, int color, QByteArray imgArr);

    ///
    /// \brief slotResumeShows 定时恢复默认显示
    ///
    void slotResumeShows();

    ///
    /// \brief slotTimerWhite 轮询获取白名单
    ///
    void slotTimerWhite();

    ///
    /// \brief slotPlateWhite 拉取的白名单写入数据库
    /// \param plateList
    ///
    void slotPlateWhite(QStringList plateList);

    ///
    /// \brief slotContainerData 箱号软件推送的数据
    /// \param data
    ///
    void slotContainerData(QString data);
};
#endif // MAINWINDOW_H
