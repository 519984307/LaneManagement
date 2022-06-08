#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<QtMsgType>("QtMsgType");
    qRegisterMetaType<QMap<int,QStringList>>("QMap<int,QStringList>");
    qRegisterMetaType<QMap<QString,QString>>("QMap<QString,QString>");

    pLog=QPointer<LogController>(new LogController("LaneManagement",this));
    connect(pLog.data(),SIGNAL(signal_newLogText(QtMsgType,QDateTime,QString)),&logFrom,SLOT(slotNewLogText(QtMsgType,QDateTime,QString)));

    pDataBase=new DataBase(this);
    connect(this,&MainWindow::signalInitDataBase,pDataBase,&DataBase::initDataBaseSlot);
    connect(this,&MainWindow::signalInsertDataBase,pDataBase,&DataBase::insertDataBaseSlot);

    initParmeter();
    emit signalInitDataBase("ZBYCS","sjzgjlg","sjzgjlg123","127.0.0.1",0);

    plateC=QSharedPointer<PlateCL>(new PlateCL(cameraPar,imgPath));
    connect(plateC.data(),&PlateCL::signalPlateResult,this,&MainWindow::slotPlateResult);
    connect(this,&MainWindow::signalPushShow,plateC.data(),&PlateCL::slotPushShow);
    connect(this,&MainWindow::signalDoSomething,plateC.data(),&PlateCL::slotDoSomething);


    postDa=new PostData(this);
    connect(this,&MainWindow::signalPostData,postDa,&PostData::slotPostData);
    //audioS=new AudioServer(this);
}

MainWindow::~MainWindow()
{   
    delete pLog;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSharedPointer<LockDialog> lockDlg=QSharedPointer<LockDialog>(new LockDialog(this));
    if(lockDlg->exec()){
        event->accept();
    }
    else {
        event->ignore();
    }
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    foreach(auto key,imgArrMap.keys()){
        QPixmap pix;
        if(!imgArrMap.value(key).isEmpty()){
             pix.loadFromData(imgArrMap.value(key));
        }
        QPalette palette;

        switch (key) {
        case 1:
            palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label->size(), Qt::IgnoreAspectRatio)));
            ui->label->setPalette(palette);
            break;
        case 2:
            palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_2->size(), Qt::IgnoreAspectRatio)));
            ui->label_2->setPalette(palette);
            break;
        case 3:
            palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_3->size(), Qt::IgnoreAspectRatio)));
            ui->label_3->setPalette(palette);
            break;
        case 4:
            palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_4->size(), Qt::IgnoreAspectRatio)));
            ui->label_4->setPalette(palette);
            break;
        case 5:
            palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_5->size(), Qt::IgnoreAspectRatio)));
            ui->label_5->setPalette(palette);
            break;
        case 6:
            palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_6->size(), Qt::IgnoreAspectRatio)));
            ui->label_6->setPalette(palette);
            break;
        }

    }
}

void MainWindow::initParmeter()
{
    QString name;
    name = db.connectionName();
    db=QSqlDatabase();
    db.removeDatabase(name);

    QDir dir(QCoreApplication::applicationDirPath());
    const QString pluginPath="Data";
    dir.cd(pluginPath);

    db=QSqlDatabase::addDatabase("QSQLITE","White_R");
    db.setDatabaseName(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg("WhiteList")));
    if(!db.isOpen()){
        if(db.open()){
            qDebug()<<QString("The whitelist database is opened successfully. Procedure");
        }
    }

    /*****************************
    * @brief:初始化显示屏恢复定时器
    ******************************/
    for (int i=1;i<=6;i++) {
        QTimer* TT=new QTimer(this);
        TT->setSingleShot(true);
        connect(TT,&QTimer::timeout,this,&MainWindow::slotResumeShows);
        timerMap.insert(i,TT);
    }

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
    imgPath = set.value("path","c:\\Images").toString();
    set.endGroup();

    set.beginGroup("Camera1");
    QString addr1 = set.value("addr1","192.168.1.101").toString();
    QString user1 = set.value("user1","admin").toString();
    QString poww1 = set.value("poww1","admin").toString();
    set.endGroup();

    set.beginGroup("Camera2");
    QString addr2 = set.value("addr2","192.168.1.102").toString();
    QString user2 = set.value("user2","admin").toString();
    QString poww2 = set.value("poww2","admin").toString();
    set.endGroup();

    set.beginGroup("Camera3");
    QString addr3 = set.value("addr3","192.168.1.103").toString();
    QString user3 = set.value("user3","admin").toString();
    QString poww3 = set.value("poww3","admin").toString();
    set.endGroup();

    set.beginGroup("Camera4");
    QString addr4 = set.value("addr4","192.168.1.104").toString();
    QString user4 = set.value("user4","admin").toString();
    QString poww4 = set.value("poww4","admin").toString();
    set.endGroup();

    set.beginGroup("Camera5");
    QString addr5 = set.value("addr5","192.168.1.105").toString();
    QString user5 = set.value("user5","admin").toString();
    QString poww5 = set.value("poww5","admin").toString();
    set.endGroup();

    set.beginGroup("Camera6");
    QString addr6 = set.value("addr6","192.168.1.106").toString();
    QString user6 = set.value("user6","admin").toString();
    QString poww6 = set.value("poww6","admin").toString();
    set.endGroup();

    set.beginGroup("Main");
    set.setValue("path",imgPath);
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

    cameraPar.insert(1,{addr1,user1,poww1});
    cameraPar.insert(2,{addr2,user2,poww2});
    cameraPar.insert(3,{addr3,user3,poww3});
    cameraPar.insert(4,{addr4,user4,poww4});
    cameraPar.insert(5,{addr5,user5,poww5});
    cameraPar.insert(6,{addr6,user6,poww6});
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
    dataFrom= QSharedPointer<DataBaseForm>(new DataBaseForm(nullptr,imgPath));
    connect(dataFrom.data(),SIGNAL(signalUpWhiteList(QMap<int,QMap<QString,QString>>)),plateC.data(),SLOT(slotUpWhiteList(QMap<int,QMap<QString,QString>>)));
    connect(dataFrom.data(),SIGNAL(signalUgWhiteList(QMap<int,QMap<QString,QString>>)),plateC.data(),SLOT(slotUgWhiteList(QMap<int,QMap<QString,QString>>)));
    dataFrom.data()->show();
}

void MainWindow::on_actionCapture_triggered()
{
    emit signalDoSomething(this->comboBox->currentIndex()+1,0,0);
}

void MainWindow::on_actionLifting_triggered()
{
    emit signalDoSomething(this->comboBox->currentIndex()+1,1,0);
}

void MainWindow::on_actionPlay_triggered()
{
    emit signalDoSomething(this->comboBox->currentIndex()+1,2,0);
}

void MainWindow::on_actionLogin_triggered()
{
    emit signalDoSomething(this->comboBox->currentIndex()+1,4,0);
}

void MainWindow::on_actionClose_triggered()
{
    emit signalDoSomething(this->comboBox->currentIndex()+1,3,winIDMap.value(this->comboBox->currentIndex()+1));
}

void MainWindow::on_actionSetting_triggered()
{
    sendRs485Data(QString::fromLocal8Bit("冀A93JT0"),this->comboBox->currentIndex()+1);
    slotPlateResult(1,"粤B050CS",0,nullptr);
}

void MainWindow::slotPlateResult(int channel, QString plate, int color,QByteArray imgArr)
{
    QDateTime time= QDateTime::currentDateTime();
    QString y = time.toString("yyyy");
    QString m = time.toString("MM");
    QString d = time.toString("dd");
    QDir dir(imgPath);
    dir.mkdir(y);
    dir.cd(y);
    dir.mkdir(m);
    dir.cd(m);
    dir.mkdir(d);
    dir.cd(d);

    QMap<QString,QString> dataMap;

    dataMap.insert("Timer",time.toString("yyyy-MM-dd hh:mm:ss zzz"));
    dataMap.insert("Channel",QString::number(channel));
    dataMap.insert("Type","-1");
    dataMap.insert("Plate",plate);
    dataMap.insert("Color",QString::number(color));
    dataMap.insert("ImgPlate",QString("%1_%2.jpg").arg(time.toString("yyyyMMddhhmmss"),plate));

    /*****************************
    * @brief:插入数据库
    ******************************/
    emit signalInsertDataBase(dataMap);
    dataMap.clear();

    QPixmap pix;
    if(!imgArr.isEmpty()){
         pix.loadFromData(imgArr);
         pix.save(QString("%1/%2_%3.jpg").arg(dir.path(),time.toString("yyyyMMddhhmmss"),plate),"JPEG");

         /*****************************
        * @brief:重绘使用
        ******************************/
         imgArrMap.insert(channel,imgArr);
    }

    QPalette palette;

    QString sheet="";
    switch (color) {
    case 0:
        sheet="background-color: rgb(255, 0, 0);color: rgb(0, 0, 0);";
        break;
    case 1:
        sheet="background-color: rgb(0, 143, 214);color: rgb(0, 0, 0);";
        break;
    case 2:
        sheet="background-color: rgb(255, 255, 0);color: rgb(0, 0, 0);";
        break;
    case 5:
        sheet="background-color: rgb(170, 255, 0);color: rgb(0, 0, 0);";
        break;
    case 6:
        sheet="background-color: rgb(0, 143, 214);color: rgb(0, 0, 0);";
        break;
    case 8:
        sheet="background-color: rgb(0, 0, 0);color: rgb(255, 255, 255);";
        break;
    default:
        sheet="background-color: rgb(255, 0, 0);color: rgb(0, 0, 0);";
    }

    switch (channel) {
    case 1:
        ui->lineEdit->setText(plate);
        ui->lineEdit->setStyleSheet(sheet);
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label->size(), Qt::IgnoreAspectRatio)));
        ui->label->setPalette(palette);        
        break;
    case 2:
        ui->lineEdit_2->setStyleSheet(sheet);
        ui->lineEdit_2->setText(plate);
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_2->size(), Qt::IgnoreAspectRatio)));
        ui->label_2->setPalette(palette);
        break;
    case 3:
        ui->lineEdit_3->setStyleSheet(sheet);
        ui->lineEdit_3->setText(plate);
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_3->size(), Qt::IgnoreAspectRatio)));
        ui->label_3->setPalette(palette);
        break;
    case 4:
        ui->lineEdit_4->setStyleSheet(sheet);
        ui->lineEdit_4->setText(plate);
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_4->size(), Qt::IgnoreAspectRatio)));
        ui->label_4->setPalette(palette);
        break;
    case 5:
        ui->lineEdit_5->setStyleSheet(sheet);
        ui->lineEdit_5->setText(plate);
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_5->size(), Qt::IgnoreAspectRatio)));
        ui->label_5->setPalette(palette);
        break;
    case 6:
        ui->lineEdit_6->setStyleSheet(sheet);
        ui->lineEdit_6->setText(plate);
        palette.setBrush(QPalette::Background, QBrush(pix.scaled(ui->label_6->size(), Qt::IgnoreAspectRatio)));
        ui->label_6->setPalette(palette);
        break;
    }

    QJsonDocument jsonDoc;
    QJsonObject jsonObj1,jsonObj2;

    jsonObj1.insert("action", "InOutAction");
    jsonObj1.insert("method", "Verification");
    jsonObj1.insert("service", "container");

    jsonObj2.insert("currentDate",time.toString("yyyy-MM-dd hh:mm:ss"));
    jsonObj2.insert("doorNumber","02");
    jsonObj2.insert("laneNumber",QString("%1").arg(channel,2,10,QLatin1Char('0')));
    jsonObj2.insert("goodsType",0);
    jsonObj2.insert("carNumber",QString::fromLocal8Bit("粤B050CS"));
    jsonObj2.insert("goodsList","WDFU7652013");

    jsonObj1.insert("dto",QJsonValue(jsonObj2));

    jsonDoc.setObject(jsonObj1);
    qDebug()<<jsonDoc.toJson(QJsonDocument::Compact);
    emit signalPostData(jsonDoc.toJson(QJsonDocument::Compact));

    ///
    /// \brief sendRs485Data 推送车牌数据到显示屏
    ///
    sendRs485Data(plate,channel);
}

void MainWindow::slotResumeShows()
{
    QObject* sender=QObject::sender();
    QTimer* tt=qobject_cast<QTimer*>(sender);
    if(tt){
        emit signalPushShow(timerMap.key(tt),nullptr,0);
    }
}

void MainWindow::sendRs485Data(QString plate,int channel)
{
    locker.lockForRead();

    QString ValidTime="";
    bool Blacklist=false;
    bool Validity=true;
    QString Name="";
    QString Department="";

    bool isRecord=false;

    QString bg=QString::fromLocal8Bit("黑名单车辆，禁止通行！");
    QString wg=QString::fromLocal8Bit("港区车辆，请通行！");
    QString lg=QString::fromLocal8Bit("临时车辆，请下车登记！");

    QString filter=QString("Plate='%1'").arg(plate);
    QScopedPointer<QSqlTableModel> model(new QSqlTableModel(this,db));
    model->setTable(QString("WhiteList"));
    model->setFilter(filter);
    model->select();
    while (model->canFetchMore()) {
        model->fetchMore();
    }

    if(model->rowCount()==1){
        qInfo().noquote()<<QString("Description The whitelist number data is searched successfully<%1>").arg(plate);

        /*****************************
        * @brief:查询到数据库，进一步读取内容
        ******************************/
        QSqlRecord record=model->record(0);
        ValidTime=record.value("ValidTime").toString();
        Department=record.value("Department").toString();
        Name=record.value("Name").toString();
        Blacklist=record.value("Blacklist").toBool();
        Validity=record.value("Validity").toBool();

        isRecord=true;
    }

    QString msgR="";
    QStringList msgList;

    bool isWg=false;

    if(isRecord && Validity){
        if(Blacklist){
            msgList.append(bg);
        }
        else
        {            
            isWg=true;
            msgList.append(wg);

            /*****************************
            * @brief:白名单抬杆
            ******************************/
            emit signalDoSomething(channel,1,0);
        }
    }
    else
    {
        msgList.append(lg);
    }

    /*****************************
    * @brief:相机不参与抬杆，直接通过软件抬杆。临时车辆出闸直接方行，数据库没有启用的数据也不抬杆
    ******************************/
    if(!isWg && !Blacklist && !isRecord && channel<=3){
        emit signalDoSomething(channel,1,0);
    }

    msgList.append(plate);
    for(int i=0;i<msgList.size();i++){
        QString tmp=bgkToHex(msgList.at(i));
        if(i==0){
            msgR+=QString("%1").arg(i+1,2,16,QChar('0')).toUpper()+"00030201"+QString("%1").arg(msgList.at(i).toLatin1().length()*2,2,16,QChar('0')).toUpper()+tmp.toUpper();
        }
        else {
            msgR+=QString("%1").arg(i+1,2,16,QChar('0')).toUpper()+"0B0A0101"+QString("%1").arg(msgList.at(i).toLatin1().length()+1,2,16,QChar('0')).toUpper()+tmp.toUpper();
        }
    }
    QString head="F501"+QString("%1").arg(msgR.length()/2+3,4,16,QChar('0')).toUpper()+"000200"+msgR;
    QByteArray arr=head.toLatin1();

    /*****************************
    * @brief:求xor校验
    ******************************/
    int xorResult = arr.mid(0,2).toInt(0,16);
    for (int i = 2; i < arr.count(); i+=2) {
        xorResult ^= arr.mid(i,2).toInt(0,16);
    }

    if(msgList.at(0).indexOf("您")!=-1){
        arr=head.insert(head.length()-4,"0A").toLatin1()+QString("%1").arg(xorResult,2,16,QChar('0')).toLatin1().toUpper();
    }
    else {
        arr=head.toLatin1()+QString("%1").arg(xorResult,2,16,QChar('0')).toLatin1().toUpper();
    }

    /*****************************
    * @brief:推送车牌显示
    ******************************/
    emit signalPushShow(channel,hexStringtoByteArray(arr),1);

    if(timerMap.value(channel)->isActive()){
        timerMap.value(channel)->stop();
    }
    timerMap.value(channel)->start(10000);
}

QByteArray MainWindow::strToHex(QString str)
{
    QByteArray buf;
    for(int i = 0; i < str.length(); i += 2)
    {
        bool ok;
        char chr = (str.mid(i, 2).toInt(&ok, 16)) & 0xFF;
        buf.append(chr);
    }
    return buf;
}

QByteArray MainWindow::hexStringtoByteArray(QString hex)
{
    QByteArray ret;
    hex=hex.trimmed();
    formatString(hex,2,' ');
    QStringList sl=hex.split(" ");
    foreach(QString s,sl)
    {
        if(!s.isEmpty())
            ret.append((char)s.toInt(0,16)&0xFF);
    }
    return ret;
}

QByteArray MainWindow::bgkToHex(QString str)
{
    QTextCodec *gbk = QTextCodec::codecForName("gb2312");
    QByteArray hex_data;

    hex_data.append(gbk->fromUnicode(str).toHex().toUpper());
    return  hex_data;
}

void MainWindow::formatString(QString &org,int n=2,const QChar &ch=QChar(' '))
{
    int size= org.size();
    int space= qRound(size*1.0/n+0.5)-1;
    if(space<=0)
        return;
    for(int i=0,pos=n;i<space;++i,pos+=(n+1))
    {
        org.insert(pos,ch);
    }
}

void MainWindow::on_actionLock_triggered()
{
    QSharedPointer<LockDialog> lockDlg=QSharedPointer<LockDialog>(new LockDialog(this));
    bool lock=true;
    while (lock) {
        if(lockDlg->exec()){
            lock=false;
        }
    }
}
