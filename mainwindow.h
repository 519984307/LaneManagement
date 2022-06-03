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

#include <QReadWriteLock>

#include "LogController/logcontroller.h"
#include "logform.h"
#include "databaseform.h"
#include "database.h"
#include "platecl.h"
#include "lockdialog.h"


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

private:

    Ui::MainWindow *ui;
    QComboBox* comboBox;

    ///
    /// \brief imgPath 图片路径
    ///
    QString imgPath;

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
    /// \brief winIDMap 视频播放句柄
    ///
    QMap<int,WId> winIDMap;

    ///
    /// \brief timerMap 定时恢复显示屏定时器组
    ///
    QMap<int,QTimer*> timerMap;

    ///
    /// \brief db 白名单数据库对象
    ///
    QSqlDatabase db;

    ///
    /// \brief locker
    ///
    QReadWriteLock locker;
              
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

private slots:

    void on_actionLog_triggered();
    void on_actionDataBase_triggered();
    void on_actionCapture_triggered();
    void on_actionLifting_triggered();
    void on_actionPlay_triggered();
    void on_actionLogin_triggered();
    void on_actionClose_triggered();
    void on_actionSetting_triggered();

    
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
    void on_actionLock_triggered();
};
#endif // MAINWINDOW_H
