#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow* MainWindow::pThis=nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::pThis=this;

    ret=-1;
    handle1=0;
    handle2=0;
    handle3=0;
    handle4=0;
    handle5=0;
    handle6=0;
    rHandle1=0;
    rHandle2=0;
    rHandle3=0;
    rHandle4=0;
    rHandle5=0;
    rHandle6=0;

    qRegisterMetaType<QtMsgType>("QtMsgType");

    pLog=QPointer<LogController>(new LogController("LaneManagement",this));
    connect(pLog.data(),SIGNAL(signal_newLogText(QtMsgType,QDateTime,QString)),&logFrom,SLOT(slotNewLogText(QtMsgType,QDateTime,QString)));

    initParmeter();
    QtConcurrent::run(this,&MainWindow::initializingCamera);
}

MainWindow::~MainWindow()
{   
    if(ret>0){
        if(0!=handle1){
            VzLPRClient_Close(handle1);
        }
        if(0!=handle2){
            VzLPRClient_Close(handle2);
        }
        if(0!=handle3){
            VzLPRClient_Close(handle3);
        }
        if(0!=handle4){
            VzLPRClient_Close(handle4);
        }
        if(0!=handle5){
            VzLPRClient_Close(handle5);
        }
        if(0!=handle6){
            VzLPRClient_Close(handle6);
        }

        VzLPRClient_Cleanup();
    }

    delete pLog;
    delete ui;
}

void MainWindow::CommonNotityCallBack(VzLPRClientHandle handle, void *pUserData, VZ_LPRC_COMMON_NOTIFY eNotify, const char *pStrDetail)
{
    Q_UNUSED(pUserData)
    Q_UNUSED(eNotify)
    Q_UNUSED(pStrDetail)
    Q_UNUSED(handle)
}

int MainWindow::PlateInfoCallBack(VzLPRClientHandle handle, void *pUserData, const TH_PlateResult *pResult, unsigned uNumPlates, VZ_LPRC_RESULT_TYPE eResultType, const VZ_LPRC_IMAGE_INFO *pImgFull, const VZ_LPRC_IMAGE_INFO *pImgPlateClip)
{
    Q_UNUSED(pUserData)
    Q_UNUSED(uNumPlates)
    Q_UNUSED(eResultType)
    Q_UNUSED(pImgPlateClip)

    if(eResultType==VZ_LPRC_RESULT_REALTIME){
        return 1;
    }

    qDebug().noquote()<<QString("License plate recognition results<%1-%2>").arg(QString::fromLocal8Bit(pResult->license),QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz"));

    QDateTime time= QDateTime::currentDateTime();
    QString y = time.toString("yyyy");
    QString m = time.toString("MM");
    QString d = time.toString("d");
    QDir dir(pThis->path);
    dir.mkdir(y);
    dir.cd(y);
    dir.mkdir(m);
    dir.cd(m);
    dir.mkdir(d);
    dir.cd(d);

    char *buf = new char[1280*960];
    VzLPRClient_ImageEncodeToJpeg(pImgFull,buf,1280*960,80);

    QPixmap pix;
    QByteArray arrImg(reinterpret_cast<const char*>(buf),1280*960);
    if(!arrImg.isEmpty()){
         pix.loadFromData(arrImg);
         pix.save(QString("%1/%2_%3.jpg").arg(dir.path(),time.toString("yyyyMMddhhmmss"),QString::fromLocal8Bit(pResult->license)),"JPEG");
    }

    QPalette palette;

    switch (pThis->handMap.key(handle)) {
    case 1:
        pThis->ui->lineEdit->setText(QString::fromLocal8Bit(pResult->license));
        if(pix.isNull()){
            return 0;
        }
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(pThis->ui->label->size(), Qt::IgnoreAspectRatio)));
        pThis->ui->label->setPalette(palette);
        break;
    case 2:
        pThis->ui->lineEdit_2->setText(QString::fromLocal8Bit(pResult->license));
        if(pix.isNull()){
            return 0;
        }
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(pThis->ui->label_2->size(), Qt::IgnoreAspectRatio)));
        pThis->ui->label_2->setPalette(palette);
        break;
    case 3:
        pThis->ui->lineEdit_3->setText(QString::fromLocal8Bit(pResult->license));
        if(pix.isNull()){
            return 0;
        }
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(pThis->ui->label_3->size(), Qt::IgnoreAspectRatio)));
        pThis->ui->label_3->setPalette(palette);
        break;
    case 4:
        pThis->ui->lineEdit_4->setText(QString::fromLocal8Bit(pResult->license));
        if(pix.isNull()){
            return 0;
        }
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(pThis->ui->label_4->size(), Qt::IgnoreAspectRatio)));
        pThis->ui->label_4->setPalette(palette);
        break;
    case 5:
        pThis->ui->lineEdit_5->setText(QString::fromLocal8Bit(pResult->license));
        if(pix.isNull()){
            return 0;
        }
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(pThis->ui->label_5->size(), Qt::IgnoreAspectRatio)));
        pThis->ui->label_5->setPalette(palette);
        break;
    case 6:
        pThis->ui->lineEdit_6->setText(QString::fromLocal8Bit(pResult->license));
        if(pix.isNull()){
            return 0;
        }
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(pThis->ui->label_6->size(), Qt::IgnoreAspectRatio)));
        pThis->ui->label_6->setPalette(palette);
        break;
    }

    delete [] buf;
    buf=nullptr;

    return 0;
}

void MainWindow::initializingCamera()
{
    cameraPort=80;

    ret=VzLPRClient_Setup();
    if(ret==0){
        qInfo().noquote()<<QString("Dynamic library initialization succeeded");
    }
    else {
        qCritical().noquote()<<QString("Dynamic library initialization failed");
        return;
    }

    if(0==VZLPRClient_SetCommonNotifyCallBack(MainWindow::CommonNotityCallBack, pUserData)){
        qInfo().noquote()<<QString("VZLPRClient_SetCommonNotifyCallBack set succeeded");
    }


    if(!addr1.isEmpty()){
        handle1 = VzLPRClient_OpenEx(addr1.toLatin1().data(),80,user1.toLatin1().data(),poww1.toLatin1().data(),0);
        if(0==handle1){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(addr1);
        }
        else {
            handMap.insert(1,handle1);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(addr1);
            if(0==VzLPRClient_SetPlateInfoCallBack(handle1,MainWindow::PlateInfoCallBack,pUserData,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(addr1);
            }
        }
    }
    if(!addr2.isEmpty()){
        handle2 = VzLPRClient_OpenEx(addr2.toLatin1().data(),80,user2.toLatin1().data(),poww2.toLatin1().data(),0);
        if(0==handle2){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(addr2);
        }
        else {
            handMap.insert(2,handle2);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(addr2);
            if(0==VzLPRClient_SetPlateInfoCallBack(handle2,MainWindow::PlateInfoCallBack,pUserData,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(addr2);
            }
        }
    }
    if(!addr3.isEmpty()){
        handle3 = VzLPRClient_OpenEx(addr3.toLatin1().data(),80,user3.toLatin1().data(),poww3.toLatin1().data(),0);
        if(0==handle3){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(addr3);
        }
        else {
            handMap.insert(3,handle3);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(addr3);
            if(0==VzLPRClient_SetPlateInfoCallBack(handle3,MainWindow::PlateInfoCallBack,pUserData,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(addr3);
            }
        }
    }
    if(!addr4.isEmpty()){
        handle4 = VzLPRClient_OpenEx(addr4.toLatin1().data(),80,user4.toLatin1().data(),poww4.toLatin1().data(),0);
        if(0==handle4){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(addr4);
        }
        else {
            handMap.insert(4,handle4);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(addr4);
            if(0==VzLPRClient_SetPlateInfoCallBack(handle4,MainWindow::PlateInfoCallBack,pUserData,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(addr4);
            }
        }
    }
    if(!addr5.isEmpty()){
        handle5 = VzLPRClient_OpenEx(addr5.toLatin1().data(),80,user5.toLatin1().data(),poww5.toLatin1().data(),0);
        if(0==handle5){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(addr5);
        }
        else {
            handMap.insert(5,handle5);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(addr5);
            if(0==VzLPRClient_SetPlateInfoCallBack(handle5,MainWindow::PlateInfoCallBack,pUserData,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(addr5);
            }
        }
    }
    if(!addr6.isEmpty()){
        handle6 = VzLPRClient_OpenEx(addr6.toLatin1().data(),80,user6.toLatin1().data(),poww6.toLatin1().data(),0);
        if(0==handle6){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(addr6);
        }
        else {
            handMap.insert(6,handle6);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(addr6);
            if(0==VzLPRClient_SetPlateInfoCallBack(handle6,MainWindow::PlateInfoCallBack,pUserData,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(addr6);
            }
        }
    }
}

void MainWindow::initParmeter()
{
    comboBox=new QComboBox(this);
    comboBox->setFixedSize(QSize(200,48));
    QFont font;
    font.setPixelSize(32);
    comboBox->setFont(font);

    QStringList IDS={"Camera1","Camera2","Camera3","Camera4","Camera5","Camera6"};
    comboBox->addItems(IDS);
    ui->toolBar->addWidget(comboBox);

    winIDMap.insert(1,ui->label->winId());
    winIDMap.insert(2,ui->label_2->winId());
    winIDMap.insert(3,ui->label_3->winId());
    winIDMap.insert(4,ui->label_4->winId());
    winIDMap.insert(5,ui->label_5->winId());
    winIDMap.insert(6,ui->label_6->winId());

    QSettings set(QDir::toNativeSeparators("Sys.ini"),QSettings::IniFormat);
    set.setIniCodec("UTF-8");

    set.beginGroup("Main");
    path = set.value("path","c:\\Images").toString();
    set.endGroup();

    set.beginGroup("Camera1");
    addr1 = set.value("addr1","192.168.1.101").toString();
    user1 = set.value("user1","admin").toString();
    poww1 = set.value("poww1","admin").toString();
    set.endGroup();

    set.beginGroup("Camera2");
    addr2 = set.value("addr2","192.168.1.102").toString();
    user2 = set.value("user2","admin").toString();
    poww2 = set.value("poww2","admin").toString();
    set.endGroup();

    set.beginGroup("Camera3");
    addr3 = set.value("addr3","192.168.1.103").toString();
    user3 = set.value("user3","admin").toString();
    poww3 = set.value("poww3","admin").toString();
    set.endGroup();

    set.beginGroup("Camera4");
    addr4 = set.value("addr4","192.168.1.104").toString();
    user4 = set.value("user4","admin").toString();
    poww4 = set.value("poww4","admin").toString();
    set.endGroup();

    set.beginGroup("Camera5");
    addr5 = set.value("addr5","192.168.1.105").toString();
    user5 = set.value("user5","admin").toString();
    poww5 = set.value("poww5","admin").toString();
    set.endGroup();

    set.beginGroup("Camera6");
    addr6 = set.value("addr6","192.168.1.106").toString();
    user6 = set.value("user6","admin").toString();
    poww6 = set.value("poww6","admin").toString();
    set.endGroup();

    set.beginGroup("Main");
    set.setValue("path",path);
    set.endGroup();

    set.beginGroup("Camera1");
    set.setValue("addr1",addr1);
    set.setValue("user1",user1);
    set.setValue("poww1",poww1);
    set.endGroup();

    set.beginGroup("Camera2");
    set.setValue("addr2",addr2);
    set.setValue("user2",user2);
    set.setValue("poww2",poww2);
    set.endGroup();

    set.beginGroup("Camera3");
    set.setValue("addr3",addr3);
    set.setValue("user3",user3);
    set.setValue("poww3",poww3);
    set.endGroup();

    set.beginGroup("Camera4");
    set.setValue("addr4",addr4);
    set.setValue("user4",user4);
    set.setValue("poww4",poww4);
    set.endGroup();

    set.beginGroup("Camera5");
    set.setValue("addr5",addr5);
    set.setValue("user5",user5);
    set.setValue("poww5",poww5);
    set.endGroup();

    set.beginGroup("Camera6");
    set.setValue("addr6",addr6);
    set.setValue("user6",user6);
    set.setValue("poww6",poww6);
    set.endGroup();

    CameraParmenterMap.insert(1,{addr1,user1,poww1});
    CameraParmenterMap.insert(2,{addr2,user2,poww2});
    CameraParmenterMap.insert(3,{addr3,user3,poww3});
    CameraParmenterMap.insert(4,{addr4,user4,poww4});
    CameraParmenterMap.insert(5,{addr5,user5,poww5});
    CameraParmenterMap.insert(6,{addr6,user6,poww6});
}


void MainWindow::on_actionLog_triggered()
{
    if(logFrom.isVisible()){
        logFrom.setVisible(false);
    }
    else {
        logFrom.setVisible(true);
    }
}

void MainWindow::on_actionDataBase_triggered()
{
    if(dataFrom && dataFrom->isVisible()){
        return;
    }
    dataFrom= QSharedPointer<DataBaseForm>(new DataBaseForm(nullptr));
    dataFrom.data()->show();
}

void MainWindow::on_actionCapture_triggered()
{
    QStringList par = CameraParmenterMap.value(this->comboBox->currentIndex()+1);
    int rt = VzLPRClient_ForceTriggerEx(handMap.value(this->comboBox->currentIndex()+1));
    if(-1!=rt){
        qInfo().noquote()<<QString("%1:ForceTrigger signal succeeded").arg(par.at(0));
    }
    else {
        qWarning().noquote()<<QString("%1:ForceTrigger signal failed errCode<%2>").arg(par.at(0),QString::number(VzLPRClient_GetLastError()));
    }
}

void MainWindow::on_actionLifting_triggered()
{
    QStringList par = CameraParmenterMap.value(this->comboBox->currentIndex()+1);
    int rt = VzLPRClient_SetIOOutputAuto(handMap.value(this->comboBox->currentIndex()+1),0,500);
    if(-1!=rt){
        qInfo().noquote()<<QString("%1:Lifting door succeeded").arg(par.at(0));
    }
    else {
        qWarning().noquote()<<QString("%1:Lifting door failed errCode<%2>").arg(par.at(0),QString::number(VzLPRClient_GetLastError()));
    }
}

void MainWindow::on_actionPlay_triggered()
{
    QStringList par = CameraParmenterMap.value(this->comboBox->currentIndex()+1);
    int rt = VzLPRClient_StartRealPlay(handMap.value(this->comboBox->currentIndex()+1),reinterpret_cast<HWND>(winIDMap.value(this->comboBox->currentIndex()+1)));
    if(-1!=rt){
        rHandMap[this->comboBox->currentIndex()+1]=rt;
        qInfo().noquote()<<QString("%1:Open video succeeded").arg(par.at(0));
    }
    else {
        qWarning().noquote()<<QString("%1:Open video failed errCode<%2>").arg(par.at(0),QString::number(VzLPRClient_GetLastError()));
    }
}

void MainWindow::on_actionLogin_triggered()
{
    QStringList par = CameraParmenterMap.value(this->comboBox->currentIndex()+1);
    if(0 == VzLPRClient_Close(handMap.value(this->comboBox->currentIndex()+1))){
        int rt = VzLPRClient_OpenEx(par.at(0).toLatin1().data(),80,par.at(1).toLatin1().data(),par.at(2).toLatin1().data(),0);
        if(rt!=0){
            handMap[this->comboBox->currentIndex()+1]=rt;
            qInfo().noquote()<<QString("%1:Camera login succeeded").arg(par.at(0));
        }
        else {
            qWarning().noquote()<<QString("%2:Camera login failed errCode<%2>").arg(par.at(0),QString::number(VzLPRClient_GetLastError()));
        }
    }
}

void MainWindow::on_actionClose_triggered()
{
    QStringList par = CameraParmenterMap.value(this->comboBox->currentIndex()+1);
    int rt = VzLPRClient_StopRealPlay(rHandMap.value(this->comboBox->currentIndex()+1));
    if(-1!=rt){
        rHandMap[this->comboBox->currentIndex()+1]=rt;
        qInfo().noquote()<<QString("%1:Close video succeeded").arg(par.at(0));
    }
    else {
        qWarning().noquote()<<QString("%1:Close video failed errCode<%2>").arg(par.at(0),QString::number(VzLPRClient_GetLastError()));
    }
}
