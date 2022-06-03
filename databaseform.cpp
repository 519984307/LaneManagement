#include "databaseform.h"
#include "ui_databaseform.h"

DataBaseForm::DataBaseForm(QWidget *parent,const QString &imgPath) :
    QWidget(parent),
    ui(new Ui::DataBaseForm)
{
    ui->setupUi(this);

    this->path=imgPath;

    whiteState=false;

    pDataBase=new DataBase(this);
    connect(pDataBase,&DataBase::returnModelSingal,this,&DataBaseForm::slot_returnModel);
    connect(pDataBase,&DataBase::statisticalDataSignal,this,&DataBaseForm::slot_statisticalData);
    connect(this,&DataBaseForm::signalInitDataBase,pDataBase,&DataBase::initDataBaseSlot);

    emit signalInitDataBase("READ","admin","ABCabc123","127.0.0.1",1);
}

DataBaseForm::~DataBaseForm()
{
    /*****************************
    * @brief:关闭白名单数据库
    ******************************/
    QString name = db.connectionName();
    db.close();
    db=QSqlDatabase();
    db.removeDatabase(name);

    delete pDataBase;
    pDataBase=nullptr;

    delete ui;
}

void DataBaseForm::on_pushButton_clicked()
{
    whiteState=false;

    QPointer<FilterDialog> filter(new FilterDialog(this));
    connect(filter,&FilterDialog::signal_filterData,pDataBase,&DataBase::setDataBaseFilterSlot);
    filter->exec();
}

void DataBaseForm::slot_returnModel(QSqlTableModel *ml)
{
    ui->tableView->setModel(ml);
    ui->tableView->setColumnHidden(ID,true);
    ui->tableView->setColumnHidden(ImgPlate,true);
    ui->tableView->setColumnHidden(ImgAfterPlate,true);
}

void DataBaseForm::slot_statisticalData(int total, double correct, double error, double statistical)
{
    Q_UNUSED(total)
    Q_UNUSED(correct)
    Q_UNUSED(error)
    Q_UNUSED(statistical)
}

void DataBaseForm::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(whiteState){
        return;
    }

    QSharedPointer<ShowDialog> Dlg=QSharedPointer<ShowDialog>(new ShowDialog(this));
    connect(this,SIGNAL(signalShowPic(QString)),Dlg.data(),SLOT(slotShowPic(QString)));

    QString imgTmp=index.sibling(index.row(),ImgPlate).data().toString();
    QStringList tmpP=imgTmp.split("_");

    emit signalShowPic(QDir::toNativeSeparators(QString("%1/%2/%3/%4/%5").arg(path,tmpP.at(0).mid(0,4),tmpP.at(0).mid(4,2),tmpP.at(0).mid(6,2),imgTmp)));
    Dlg.data()->exec();
}

void DataBaseForm::on_pushButton_3_clicked()
{
    QString filepath = QFileDialog::getSaveFileName(this, QString("Save as..."),
                                                  QString(), QString("EXCEL files (*.xls);;HTML-Files (*.txt);;"));

    if (filepath != "")
    {
        int row = ui->tableView->model()->rowCount();
        int col = ui->tableView->model()->columnCount();
        QList<QString> list;
        //添加列标题
        QString HeaderRow;
        for (int i = 0; i < col; i++)
        {
            HeaderRow.append(ui->tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\t");
        }
        list.push_back(HeaderRow);
        for (int i = 0; i < row; i++)
        {
            QString rowStr = "";
            for (int j = 0; j < col; j++){
                QModelIndex index = ui->tableView->model()->index(i, j);
                rowStr += ui->tableView->model()->data(index).toString() + "\t";
            }
            list.push_back(rowStr);
        }
        QTextEdit textEdit;
        for (int i = 0; i < list.size(); i++)
        {
            textEdit.append(list.at(i));
        }

        QFile file(filepath);
        if (file.open(QFile::WriteOnly | QIODevice::Text))
        {
            QTextStream ts(&file);
            ts.setCodec("GB2312");/* 这个地方大家自己判断是否用“utf-8” */
            ts << textEdit.document()->toPlainText();
            file.close();
            QMessageBox::information(this,"excel data","Data export successful");
        }else{
            QMessageBox::warning(this,"excel data","Data export failed");
        }
    }
}

void DataBaseForm::on_pushButton_2_clicked()
{
    whiteState=true;

    QString name;
    name = db.connectionName();
    //db.close();
    db=QSqlDatabase();
    db.removeDatabase(name);

    /*  创建插件目录  */
    QDir dir(QCoreApplication::applicationDirPath());
    const QString pluginPath="Data";
    dir.mkdir(pluginPath);
    dir.cd(pluginPath);

    db=QSqlDatabase::addDatabase("QSQLITE","White");
    db.setDatabaseName(QDir::toNativeSeparators(QString("%1/%2").arg(dir.path()).arg("WhiteList")));

    if(db.open()){
        QSqlQuery query(db);
        query.prepare(QString("CREATE TABLE `WhiteList` (\
                      `ID`  INTEGER PRIMARY KEY AUTOINCREMENT,\
                      `ValidTime`   TEXT,\
                      `Blacklist` INTEGER NOT NULL,\
                      `Plate`  TEXT,\
                      `Department`  TEXT,\
                      `Name`  TEXT,\
                      `Validity`  INTEGER NOT NULL\
                  )"));
        if(!query.exec()){
                          qWarning().noquote()<<QString("Create table containers error<errorCode=%1>").arg(query.lastError().text());
                      }
                      else {
                          qInfo().noquote()<<QString("Create table Containers sucess");
                      }
                      query.clear();

                model=QSharedPointer<QSqlTableModel>(new QSqlTableModel(this,db));
                model->setEditStrategy(QSqlTableModel::OnManualSubmit);
                model->setTable(QString("WhiteList"));
                model->setFilter("");
                model->select();
                while (model->canFetchMore()) {
                    model->fetchMore();
                }

                ui->tableView->setModel(model.data());
    }
    else {
        qWarning().noquote()<<QString("Open databse  error<errorCode=%1>").arg(db.lastError().text());
    }

}

/*****************************
* @brief:删除数据
******************************/
void DataBaseForm::on_pushButton_6_clicked()
{
    if(!model){
        return;
    }

    QMap<int,QMap<QString,QString>> wlst_vehicle;

    int row=index.row();
    int col = ui->tableView->model()->columnCount();

    //添加列标题
    QStringList HeaderRow;
    for (int i = 0; i < col; i++)
    {
        HeaderRow.append(ui->tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
    }

    int ID = -1;
    QMap<QString,QString> var;
    for (int j = 0; j < col; j++){
        QModelIndex index = ui->tableView->model()->index(row, j);
        if(j==0){
            ID=ui->tableView->model()->data(index).toInt();
        }
        else {
            var.insert(HeaderRow.at(j),ui->tableView->model()->data(index).toString());
        }
    }
    wlst_vehicle.insert(ID,var);

    model->removeRow(row);
    model->submitAll();
    model->select();

    emit signalDeWhiteList(wlst_vehicle);
}

/*****************************
* @brief:添加数据
******************************/
void DataBaseForm::on_pushButton_5_clicked()
{
    QSharedPointer<AddDialog> Dlg=QSharedPointer<AddDialog>(new AddDialog(this));
    connect(Dlg.data(),SIGNAL(signalAddItem(QMap<QString,QString>)),this,SLOT(slotAddItem(QMap<QString,QString>)));
    Dlg->exec();
}

void DataBaseForm::slotAddItem(QMap<QString,QString> item)
{
    if(!model){
        return;
    }

    QSqlRecord record=model->record();

    foreach (auto key, item.keys()) {
        record.setValue(key,item.value(key));
    }
    if(!model->insertRecord(-1,record)){
        qWarning().noquote()<<QString("%1:Insert data to databse  error<errorCode=%2>").arg(record.value("Plate").toString()).arg(model->lastError().text());
    }
    else {
        qDebug().noquote()<<QString("%1:Insert data to databse  sucessful").arg(record.value("Plate").toString());
    }
    model->submitAll();
    model->select();

    //row = ui->tableView->model()->rowCount();


    QMap<int,QMap<QString,QString>> wlst_vehicle;

    int row = ui->tableView->model()->rowCount()-1;
    int col = ui->tableView->model()->columnCount();

    //添加列标题
    QStringList HeaderRow;
    for (int i = 0; i < col; i++)
    {
        HeaderRow.append(ui->tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
    }

    int ID = -1;
    QMap<QString,QString> var;
    for (int j = 0; j < col; j++){
        QModelIndex index = ui->tableView->model()->index(row, j);
        if(j==0){
            ID=ui->tableView->model()->data(index).toInt();
        }
        else {
            var.insert(HeaderRow.at(j),ui->tableView->model()->data(index).toString());
        }
    }
    wlst_vehicle.insert(ID,var);

    emit signalUpWhiteList(wlst_vehicle);
}

/*****************************
* @brief:上传白名单
******************************/
void DataBaseForm::on_pushButton_7_clicked()
{
    if(!model){
        return;
    }

    QMap<int,QMap<QString,QString>> wlst_vehicle;

    int row = ui->tableView->model()->rowCount();
    int col = ui->tableView->model()->columnCount();

    //添加列标题
    QStringList HeaderRow;
    for (int i = 0; i < col; i++)
    {
        HeaderRow.append(ui->tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
    }

    for (int i = 0; i < row; i++)
    {
        int ID = -1;
        QMap<QString,QString> var;
        for (int j = 0; j < col; j++){
            QModelIndex index = ui->tableView->model()->index(i, j);
            if(j==0){
                ID=ui->tableView->model()->data(index).toInt();
            }
            else {
                var.insert(HeaderRow.at(j),ui->tableView->model()->data(index).toString());
            }
        }
        wlst_vehicle.insert(ID,var);
    }
    emit signalUpWhiteList(wlst_vehicle);
}

/*****************************
* @brief:编辑数据
******************************/
void DataBaseForm::on_pushButton_4_clicked()
{
    model->database().transaction();
    if(model->submitAll()){
        model->database().commit();
    }
    else {
        model->database().rollback();
    }

    int col = ui->tableView->model()->columnCount();
    int row = index.row();

    QMap<int,QMap<QString,QString>> wlst_vehicle;

    QStringList HeaderRow;
    for (int i = 0; i < col; i++)
    {
        HeaderRow.append(ui->tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
    }

    int ID = -1;
    QMap<QString,QString> var;
    for (int j = 0; j < col; j++){
        QModelIndex index = ui->tableView->model()->index(row, j);
        if(j==0){
            ID=ui->tableView->model()->data(index).toInt();
        }
        else {
            var.insert(HeaderRow.at(j),ui->tableView->model()->data(index).toString());
        }
    }
    wlst_vehicle.insert(ID,var);

    emit signalUgWhiteList(wlst_vehicle);
}

void DataBaseForm::on_tableView_clicked(const QModelIndex &index)
{
    this->index=index;
}
