#ifndef LOGCONTROLLER_H
#define LOGCONTROLLER_H

#include <QObject>
#include <QDateTime>

#include "LogController_global.h"

class LOGCONTROLLER_EXPORT LogController:public QObject
{   
    Q_OBJECT

public:
    LogController(QString App,QObject *parent = nullptr);

signals:

    ///
    /// \brief singal_newLogText ����־��Ϣ
    /// \param value ��Ϣ��
    ///
    void signal_newLogText(QtMsgType type,QDateTime time,QString value);
};

#endif // LOGCONTROLLER_H
