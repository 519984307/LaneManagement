#ifndef DATABASEFORM_H
#define DATABASEFORM_H

#include <QWidget>
#include <QPointer>
#include <QSqlTableModel>
#include <QScopedPointer>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QTextEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QBuffer>
#include <QFile>
#include <QThread>
#include <QLabel>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QMessageBox>

#include "filterdialog.h"
#include "database.h"
#include "showdialog.h"
#include "adddialog.h"

namespace Ui {
class DataBaseForm;
}

class DataBaseForm : public QWidget
{
    Q_OBJECT

public:
    explicit DataBaseForm(QWidget *parent = nullptr, const QString &imgPath="C:/images");
    ~DataBaseForm();

private slots:
    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:

    Ui::DataBaseForm *ui;

    ///
    /// \brief model 白名单数据模型对象
    ///
    QSharedPointer<QSqlTableModel> model;

    ///
    /// \brief db 白名单数据库对象
    ///
    QSqlDatabase db;

    ///
    /// \brief whiteState 白名单动作状态，过滤显示图片功能
    ///
    bool whiteState;

    ///
    /// \brief path 图片路径
    ///
    QString path;

    ///
    /// \brief pDataBase
    ///
    DataBase* pDataBase;

    enum{
        ID=0,
        Timer=1,
        Channel=2,
        Type=3,
        Plate=4,
        Color=5,
        ImgPlate=6,
        TimerAfter=7,
        ImgAfterPlate=8,
        Department=9,
        Aging=10
    };

    ///
    /// \brief index 选中项
    ///
    QModelIndex index;

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
    /// \brief signalSendResult 发送识别结果
    /// \param rst
    ///
    void signalSendResult(int channel_number, const QByteArray &data);

    ///
    /// \brief signalShowPic 显示图片
    /// \param path
    ///
    void signalShowPic(QString path);

    ///
    /// \brief signalUpWhiteList 上传白名单
    ///
    void signalUpWhiteList(QMap<int,QMap<QString,QString>>);

    ///
    /// \brief signalUpWhiteList 更新名单
    ///
    void signalUgWhiteList(QMap<int,QMap<QString,QString>>);

    ///
    /// \brief signalDeWhiteList 删除白名单
    ///
    void signalDeWhiteList(QMap<int,QMap<QString,QString>>);

public slots:

    /*****************************
    * @brief:数据库读取
    ******************************/

    ///
    /// \brief slot_returnModel 返回数据模型
    /// \param model 数据模型
    ///
    void slot_returnModel(QSqlTableModel *ml);

    ///
    /// \brief slotAddItem 添加数据
    /// \param item
    ///
    void slotAddItem(QMap<QString, QString> item);

    ///
    /// \brief slot_statisticalData
    /// \param total 总计
    /// \param correct 正确
    /// \param error 错误
    /// \param statistical 统计
    ///
    void slot_statisticalData(int total,double correct,double error,double statistical);
};

#endif // DATABASEFORM_H
