#include "databaseform.h"
#include "ui_databaseform.h"

DataBaseForm::DataBaseForm(QWidget *parent,const QString &imgPath) :
    QWidget(parent),
    ui(new Ui::DataBaseForm)
{
    ui->setupUi(this);

    this->path=imgPath;

    pDataBase=new DataBase(this);
    connect(pDataBase,&DataBase::returnModelSingal,this,&DataBaseForm::slot_returnModel);
    connect(pDataBase,&DataBase::statisticalDataSignal,this,&DataBaseForm::slot_statisticalData);
    connect(this,&DataBaseForm::signalInitDataBase,pDataBase,&DataBase::initDataBaseSlot);

    emit signalInitDataBase("READ","admin","ABCabc123","127.0.0.1",1);
}

DataBaseForm::~DataBaseForm()
{
    delete pDataBase;
    pDataBase=nullptr;

    delete ui;
}

void DataBaseForm::on_pushButton_clicked()
{
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

}

void DataBaseForm::on_tableView_doubleClicked(const QModelIndex &index)
{
    QSharedPointer<ShowDialog> Dlg=QSharedPointer<ShowDialog>(new ShowDialog(this));
    connect(this,SIGNAL(signalShowPic(QString)),Dlg.data(),SLOT(slotShowPic(QString)));

    QString imgTmp=index.sibling(index.row(),ImgPlate).data().toString();
    QStringList tmpP=imgTmp.split("_");
    qDebug()<<QDir::toNativeSeparators(QString("%1/%2/%3/%3/%4/%5").arg(path,tmpP.at(0).mid(0,4),tmpP.at(0).mid(4,2),tmpP.at(0).mid(6,2),imgTmp));

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
