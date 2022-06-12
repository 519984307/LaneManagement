#include "platecl.h"

PlateCL* PlateCL::pThis=nullptr;

PlateCL::PlateCL(QMap<int, QStringList> cameraPar, QString imgPath)
{
    PlateCL::pThis=this;
    
    this->cameraPar=cameraPar;
    this->imgPath=imgPath;
       
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
    cameraPort=80;        

    handList<<handle1<<handle2<<handle3<<handle4<<handle5<<handle6;
    
    QtConcurrent::run(this,&PlateCL::initializingCamera);
}

PlateCL::~PlateCL()
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
}

void PlateCL::CommonNotityCallBack(VzLPRClientHandle handle, void *pUserData, VZ_LPRC_COMMON_NOTIFY eNotify, const char *pStrDetail)
{
    Q_UNUSED(pUserData)
    Q_UNUSED(eNotify)
    Q_UNUSED(pStrDetail)
    Q_UNUSED(handle)

    switch (eNotify) {
    /**<无错误*/
    case VZ_LPRC_NO_ERR:
        break;
    /**<用户名密码错误*/
    case VZ_LPRC_ACCESS_DENIED:
        break;
    /**<网络连接故障*/
    case VZ_LPRC_NETWORK_ERR:
        break;
    /**<设备上线*/
    case VZ_LPRC_ONLINE:
        break;
    /**<设备掉线*/
    case VZ_LPRC_OFFLINE:
        break;
    /**<IO口输入信号*/
    case VZ_LPRC_IO_INPUT:
        break;
    }
}

int PlateCL::PlateInfoCallBack(VzLPRClientHandle handle, void *pUserData, const TH_PlateResult *pResult, unsigned uNumPlates, VZ_LPRC_RESULT_TYPE eResultType, const VZ_LPRC_IMAGE_INFO *pImgFull, const VZ_LPRC_IMAGE_INFO *pImgPlateClip)
{
    Q_UNUSED(pUserData)
    Q_UNUSED(uNumPlates)
    Q_UNUSED(eResultType)
    Q_UNUSED(pImgPlateClip)

    if(eResultType==VZ_LPRC_RESULT_REALTIME){
        return 1;
    }

    qDebug().noquote()<<QString("License plate recognition results<%1-%2>").arg(QString::fromLocal8Bit(pResult->license),QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz"));

    char *buf = new char[1920*1080];
    VzLPRClient_ImageEncodeToJpeg(pImgFull,buf,1920*1080,80);

    QByteArray arrImg(reinterpret_cast<const char*>(buf),1920*1080);

    emit pThis->signalPlateResult(pThis->handMap.key(handle),QString::fromLocal8Bit(pResult->license),pResult->nColor,arrImg);
    
    delete [] buf;
    buf=nullptr;
    
    return 0;
}

void PlateCL::initializingCamera()
{
    ret=VzLPRClient_Setup();
    if(ret==0){
        qInfo().noquote()<<QString("Dynamic library initialization succeeded");
    }
    else {
        qCritical().noquote()<<QString("Dynamic library initialization failed");
        return;
    }

    if(0==VZLPRClient_SetCommonNotifyCallBack(PlateCL::CommonNotityCallBack, nullptr)){
        qInfo().noquote()<<QString("VZLPRClient_SetCommonNotifyCallBack set succeeded");
    }

    
    if(!cameraPar.value(1).at(0).isEmpty()){
        handle1 = VzLPRClient_OpenEx(cameraPar.value(1).at(0).toLatin1().data(),80,cameraPar.value(1).at(1).toLatin1().data(),cameraPar.value(1).at(2).toLatin1().data(),0);
        if(0==handle1){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(cameraPar.value(1).at(0));
        }
        else {            
            handMap.insert(1,handle1);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(cameraPar.value(1).at(0));
            if(0==VzLPRClient_SetPlateInfoCallBack(handle1,PlateCL::PlateInfoCallBack,nullptr,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(cameraPar.value(1).at(0));
            }
        }
    }
    if(!cameraPar.value(2).at(0).isEmpty()){
        handle2 = VzLPRClient_OpenEx(cameraPar.value(2).at(0).toLatin1().data(),80,cameraPar.value(2).at(1).toLatin1().data(),cameraPar.value(2).at(2).toLatin1().data(),0);
        if(0==handle2){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(cameraPar.value(2).at(0));
        }
        else {
            handMap.insert(2,handle2);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(cameraPar.value(2).at(0));
            if(0==VzLPRClient_SetPlateInfoCallBack(handle2,PlateCL::PlateInfoCallBack,nullptr,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(cameraPar.value(2).at(0));
            }
        }
    }
    if(!cameraPar.value(3).at(0).isEmpty()){
        handle3 = VzLPRClient_OpenEx(cameraPar.value(3).at(0).toLatin1().data(),80,cameraPar.value(3).at(1).toLatin1().data(),cameraPar.value(3).at(2).toLatin1().data(),0);
        if(0==handle3){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(cameraPar.value(3).at(0));
        }
        else {
            handMap.insert(3,handle3);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(cameraPar.value(3).at(0));
            if(0==VzLPRClient_SetPlateInfoCallBack(handle3,PlateCL::PlateInfoCallBack,nullptr,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(cameraPar.value(3).at(0));
            }
        }
    }
    if(!cameraPar.value(4).at(0).isEmpty()){
        handle4 = VzLPRClient_OpenEx(cameraPar.value(4).at(0).toLatin1().data(),80,cameraPar.value(4).at(1).toLatin1().data(),cameraPar.value(4).at(2).toLatin1().data(),0);
        if(0==handle4){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(cameraPar.value(4).at(0));
        }
        else {
            handMap.insert(4,handle4);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(cameraPar.value(4).at(0));
            if(0==VzLPRClient_SetPlateInfoCallBack(handle4,PlateCL::PlateInfoCallBack,nullptr,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(cameraPar.value(4).at(0));
            }
        }
    }
    if(!cameraPar.value(5).at(0).isEmpty()){
        handle5 = VzLPRClient_OpenEx(cameraPar.value(5).at(0).toLatin1().data(),80,cameraPar.value(5).at(1).toLatin1().data(),cameraPar.value(5).at(2).toLatin1().data(),0);
        if(0==handle5){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(cameraPar.value(5).at(0));
        }
        else {
            handMap.insert(5,handle5);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(cameraPar.value(5).at(0));
            if(0==VzLPRClient_SetPlateInfoCallBack(handle5,PlateCL::PlateInfoCallBack,nullptr,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(cameraPar.value(5).at(0));
            }
        }
    }
    if(!cameraPar.value(6).at(0).isEmpty()){
        handle6 = VzLPRClient_OpenEx(cameraPar.value(6).at(0).toLatin1().data(),80,cameraPar.value(6).at(1).toLatin1().data(),cameraPar.value(6).at(2).toLatin1().data(),0);
        if(0==handle6){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(cameraPar.value(6).at(0));
        }
        else {
            handMap.insert(6,handle6);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(cameraPar.value(6).at(0));
            if(0==VzLPRClient_SetPlateInfoCallBack(handle6,PlateCL::PlateInfoCallBack,nullptr,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(cameraPar.value(6).at(0));
            }
        }
    }

    QtConcurrent::run(this,&PlateCL::resumeShows);

//    for (int i=1;i<=6;i++) {
//        if(handMap.value(i,0)==0){
//            loginCamera(i);
//        }
//    }
}

void PlateCL::loginCamera(int key)
{
    if(!cameraPar.value(key).at(0).isEmpty()){
        handList[key] = VzLPRClient_OpenEx(cameraPar.value(key).at(0).toLatin1().data(),80,cameraPar.value(key).at(1).toLatin1().data(),cameraPar.value(key).at(2).toLatin1().data(),0);
        if(0==handList[key]){
            qWarning().noquote()<<QString("Camera login failure<%1>").arg(cameraPar.value(key).at(0));

            QtConcurrent::run(this,&PlateCL::loginCamera,key);
        }
        else {
            handMap.insert(key,handList[key]);
            qWarning().noquote()<<QString("Camera login succeeded<%1>").arg(cameraPar.value(key).at(0));
            if(0==VzLPRClient_SetPlateInfoCallBack(handle6,PlateCL::PlateInfoCallBack,nullptr,1)){
                qInfo().noquote()<<QString("VzLPRClient_SetPlateInfoCallBack set succeeded<%1>").arg(cameraPar.value(key).at(0));
            }
        }
    }
}

void PlateCL::slotUgWhiteList(QMap<int, QMap<QString, QString> > wlst)
{
    foreach(int id,wlst.keys()){

        VZ_TM struTMEnable,struTMOverdule;

        struTMEnable.nYear=QDate::currentDate().year();
        struTMEnable.nMonth=QDate::currentDate().month();
        struTMEnable.nMDay=QDate::currentDate().day();
        struTMEnable.nHour=QTime::currentTime().hour();
        struTMEnable.nMin=QTime::currentTime().minute();
        struTMEnable.nSec=QTime::currentTime().second();

        QDateTime TMOverdule=QDateTime::fromString(wlst.value(id).value("ValidTime"),"yyyy-MM-dd hh:mm:ss");
        struTMOverdule.nYear=TMOverdule.date().year();
        struTMOverdule.nMonth=TMOverdule.date().month();
        struTMOverdule.nMDay=TMOverdule.date().day();
        struTMOverdule.nHour=TMOverdule.time().hour();
        struTMOverdule.nMin=TMOverdule.time().minute();
        struTMOverdule.nSec=TMOverdule.time().second();

        VZ_LPR_WLIST_VEHICLE* wlistVehicle=new VZ_LPR_WLIST_VEHICLE();
        wlistVehicle->uVehicleID=wlst.value(id).value("ID").toInt();
        strcpy(wlistVehicle->strPlateID,wlst.value(id).value("Plate").toLocal8Bit().data());
        wlistVehicle->uCustomerID=wlst.value(id).value("ID").toInt();
        wlistVehicle->bEnable=wlst.value(id).value("Validity").toInt();
        wlistVehicle->bEnableTMEnable=1;
        wlistVehicle->bEnableTMOverdule=1;
        wlistVehicle->struTMEnable=struTMEnable;
        wlistVehicle->struTMOverdule=struTMOverdule;
        wlistVehicle->bUsingTimeSeg=0;
        wlistVehicle->bAlarm=wlst.value(id).value("Blacklist").toInt();

        foreach(auto hand,handMap.values()){
            if(0==VzLPRClient_WhiteListUpdateVehicleByCode(hand,wlistVehicle)){
                qInfo().noquote()<<QString("%2:The whitelist was upgrade successfully. Procedure<%1>").arg(wlst.value(id).value("Plate"),cameraPar.value(handMap.key(hand)).at(0));
            }
            else {
                qWarning()<<QString("%1-%2:The whitelist was upgrade successfully. Procedure<errCode=%3>").arg(cameraPar.value(handMap.key(hand)).at(0),wlst.value(id).value("Plate"),QString::number(VzLPRClient_GetLastError()));
            }
        }
    }
}

void PlateCL::slotDeWhiteList(QMap<int,QMap<QString, QString> > wlst)
{
    foreach(auto hand,handMap.values())
    {
        foreach(auto val,wlst.values()){
            int rec=VzLPRClient_WhiteListDeleteCustomerAndVehiclesByCustomerID(hand,val.value("ID").toInt());
            if(0==rec){
                qInfo().noquote()<<QString("%2:The whitelist was uploaded successfully. Procedure<%1>").arg(val.value("Plate"),cameraPar.value(handMap.key(hand)).at(0));
            }
            else {
                qWarning()<<QString("%1-%2:The whitelist was uploaded successfully. Procedure<errCode=%3>").arg(cameraPar.value(handMap.key(hand)).at(0),val.value("Plate"),QString::number(VzLPRClient_GetLastError()));
            }
        }
    }
}

void PlateCL::slotUpWhiteList(QMap<int, QMap<QString, QString> > wlst)
{
    foreach(int id,wlst.keys()){

        VZ_TM struTMEnable,struTMOverdule;

        struTMEnable.nYear=QDate::currentDate().year();
        struTMEnable.nMonth=QDate::currentDate().month();
        struTMEnable.nMDay=QDate::currentDate().day();
        struTMEnable.nHour=QTime::currentTime().hour();
        struTMEnable.nMin=QTime::currentTime().minute();
        struTMEnable.nSec=QTime::currentTime().second();

        QDateTime TMOverdule=QDateTime::fromString(wlst.value(id).value("ValidTime","yyyy-MM-dd hh:mm:ss"));
        struTMOverdule.nYear=TMOverdule.date().year();
        struTMOverdule.nMonth=TMOverdule.date().month();
        struTMOverdule.nMDay=TMOverdule.date().day();
        struTMOverdule.nHour=TMOverdule.time().hour();
        struTMOverdule.nMin=TMOverdule.time().minute();
        struTMOverdule.nSec=TMOverdule.time().second();

        VZ_LPR_WLIST_CUSTOMER* wlstCustomer=new VZ_LPR_WLIST_CUSTOMER();
        wlstCustomer->uCustomerID=wlst.value(id).value("ID").toInt();
        strcpy(wlstCustomer->strName,wlst.value(id).value("Name").toLocal8Bit().data());
        strcpy(wlstCustomer->strCode,wlst.value(id).value("Department").toLocal8Bit().data());

        VZ_LPR_WLIST_VEHICLE* wlistVehicle=new VZ_LPR_WLIST_VEHICLE();
        wlistVehicle->uVehicleID=wlst.value(id).value("ID").toInt();
        strcpy(wlistVehicle->strPlateID,wlst.value(id).value("Plate").toLocal8Bit().data());
        wlistVehicle->uCustomerID=wlst.value(id).value("ID").toInt();
        wlistVehicle->bEnable=wlst.value(id).value("Validity").toInt();
        wlistVehicle->bEnableTMEnable=1;
        wlistVehicle->bEnableTMOverdule=1;
        wlistVehicle->struTMEnable=struTMEnable;
        wlistVehicle->struTMOverdule=struTMOverdule;
        wlistVehicle->bUsingTimeSeg=0;
        wlistVehicle->bAlarm=wlst.value(id).value("Blacklist").toInt();

        VZ_LPR_WLIST_IMPORT_RESULT wlistR;

        VZ_LPR_WLIST_ROW* wlistRow=new VZ_LPR_WLIST_ROW();
        wlistRow->pCustomer = wlstCustomer;
        wlistRow->pVehicle = wlistVehicle;


        foreach(auto hand,handMap.values()){
            if(0==VzLPRClient_WhiteListImportRows(hand,1,wlistRow,&wlistR)){
                qInfo().noquote()<<QString("%2:The whitelist was uploaded successfully. Procedure<%1>").arg(wlst.value(id).value("Plate"),cameraPar.value(handMap.key(hand)).at(0));
            }
            else {
                qWarning()<<QString("%1-%2:The whitelist was uploaded successfully. Procedure<errCode=%3>").arg(cameraPar.value(handMap.key(hand)).at(0),wlst.value(id).value("Plate"),QString::number(VzLPRClient_GetLastError()));
            }
        }
    }
}

void PlateCL::resumeShows()
{
    /*****************************
    * @brief:出闸
    ******************************/
    QString msgOUT="F501005100010001000003011ECAAFBCD2D7AFB9FA0ABCCAC2BDB8DBA3ACD7A3C4FA0AD2BBC2B7CBB3B7E7A3A102000003011ED2BBB3B5D2BBB8CB2020BCFA05CBD9C2FDD0D02020D7A2D2E2B0B2C8ABA3A1030102030100BB";

    /*****************************
    * @brief:进闸
    ******************************/
    QString msgIN="F5010045000100010000030118CAAFBCD2D7AFB9FA0ABCCAC2BDB8DBA3ACBBB6D3ADC4FA0AA3A1020000030118D2BBB3B5D2BBB8CB202020202020D7A2D2E2B0B2C8ABA3A1030102030100F8";

    QByteArray arr;

    int ind=1;
    if(ind<4){
        arr=msgIN.toLatin1();
        arr=hexStringtoByteArray(arr);
    }
    else {
        arr=msgOUT.toLatin1();
        arr=hexStringtoByteArray(arr);
    }


    foreach(auto hand,handMap.values()){
        int rec= VzLPRClient_SerialStart(hand,0,nullptr,nullptr);
        VzLPRClient_SerialSend(rec,const_cast<unsigned char*>((const unsigned char*)arr.toStdString().c_str()) ,arr.length());
        VzLPRClient_SerialStop(rec);
        ind++;
    }
}

void PlateCL::slotPushShow(int channel, QByteArray arr,int type)
{
    if(type==0){
        /*****************************
        * @brief:出闸
        ******************************/
        QString msgOUT="F501005100010001000003011ECAAFBCD2D7AFB9FA0ABCCAC2BDB8DBA3ACD7A3C4FA0AD2BBC2B7CBB3B7E7A3A102000003011ED2BBB3B5D2BBB8CB2020BCFA05CBD9C2FDD0D02020D7A2D2E2B0B2C8ABA3A1030102030100BB";

        /*****************************
        * @brief:进闸
        ******************************/
        QString msgIN="F5010045000100010000030118CAAFBCD2D7AFB9FA0ABCCAC2BDB8DBA3ACBBB6D3ADC4FA0AA3A1020000030118D2BBB3B5D2BBB8CB202020202020D7A2D2E2B0B2C8ABA3A1030102030100F8";

        QByteArray arr;

        if(channel<=3){
            arr=msgOUT.toLatin1();
            arr=hexStringtoByteArray(arr);
        }
        else {
            arr=msgIN.toLatin1();
            arr=hexStringtoByteArray(arr);
        }
        int rec= VzLPRClient_SerialStart(pThis->handMap.value(channel),0,nullptr,nullptr);
        VzLPRClient_SerialSend(rec,const_cast<unsigned char*>((const unsigned char*)arr.toStdString().c_str()) ,arr.length());
        VzLPRClient_SerialStop(rec);

        qDebug()<<QString("%1:Restore default display").arg(cameraPar.value(channel).at(0));
    }
    else {
        int rec= VzLPRClient_SerialStart(pThis->handMap.value(channel),0,nullptr,nullptr);
        VzLPRClient_SerialSend(rec,const_cast<unsigned char*>((const unsigned char*)arr.toStdString().c_str()) ,arr.length());
        VzLPRClient_SerialStop(rec);

        qDebug()<<QString("%1:Send license plate display").arg(cameraPar.value(channel).at(0));
    }
}

void PlateCL::slotDoSomething(int channel, int type, quintptr Wid)
{
    if(type==0){
        int rt = VzLPRClient_ForceTriggerEx(handMap.value(channel));
        if(-1!=rt){
            qInfo().noquote()<<QString("%1:ForceTrigger signal succeeded").arg(cameraPar.value(channel).at(0));
        }
        else {
            qWarning().noquote()<<QString("%1:ForceTrigger signal failed errCode<%2>").arg(cameraPar.value(channel).at(0),QString::number(VzLPRClient_GetLastError()));
        }
    }
    else if (type==1) {
        int rt = VzLPRClient_SetIOOutputAuto(handMap.value(channel),0,500);
        if(-1!=rt){
            qInfo().noquote()<<QString("%1:Lifting door succeeded").arg(cameraPar.value(channel).at(0));
        }
        else {
            qWarning().noquote()<<QString("%1:Lifting door failed errCode<%2>").arg(cameraPar.value(channel).at(0),QString::number(VzLPRClient_GetLastError()));
        }
    }
    else if (type==2) {
        int rt = VzLPRClient_StartRealPlay(handMap.value(channel),reinterpret_cast<HWND>(Wid));
        if(-1!=rt){
            rHandMap[channel]=rt;
            qInfo().noquote()<<QString("%1:Open video succeeded").arg(cameraPar.value(channel).at(0));
        }
        else {
            qWarning().noquote()<<QString("%1:Open video failed errCode<%2>").arg(cameraPar.value(channel).at(0),QString::number(VzLPRClient_GetLastError()));
        }
    }
    else if (type==3) {
        int rt = VzLPRClient_StopRealPlay(rHandMap.value(channel));
        if(-1!=rt){
            rHandMap[channel]=rt;
            qInfo().noquote()<<QString("%1:Close video succeeded").arg(cameraPar.value(channel).at(0));
        }
        else {
            qWarning().noquote()<<QString("%1:Close video failed errCode<%2>").arg(cameraPar.value(channel).at(0),QString::number(VzLPRClient_GetLastError()));
        }
    }
    else if (type==4) {
        if(0 == VzLPRClient_Close(handMap.value(channel))){
            int rt = VzLPRClient_OpenEx(cameraPar.value(channel).at(0).toLatin1().data(),80,cameraPar.value(channel).at(1).toLatin1().data(),cameraPar.value(channel).at(2).toLatin1().data(),0);
            if(rt!=0){
                handMap[channel]=rt;
                qInfo().noquote()<<QString("%1:Camera login succeeded").arg(cameraPar.value(channel).at(0));
            }
            else {
                qWarning().noquote()<<QString("%2:Camera login failed errCode<%2>").arg(cameraPar.value(channel).at(0),QString::number(VzLPRClient_GetLastError()));
            }
        }
    }
    else {
        qWarning().noquote()<<QString("this->comboBox->currentIndex()+1");
    }
}

void PlateCL::slotSendAudio(int channel, QByteArray data)
{
    if(0==VzLPRClient_PlayVoice(handMap.value(channel),data,500,100,0)){
        qDebug().noquote()<<QString("Play license plate successfully");
    }
}

QByteArray PlateCL::hexStringtoByteArray(QString hex)
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

void PlateCL::formatString(QString &org,int n=2,const QChar &ch=QChar(' '))
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

