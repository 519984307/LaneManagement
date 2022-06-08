#ifndef AUDIOSERVER_H
#define AUDIOSERVER_H

#include <QObject>
#include <QUrl>
#include <QtWebSockets/QWebSocket>
#include <QAbstractSocket>
#include <QSslConfiguration>
#include <QSslError>


class AudioServer : public QObject
{
    Q_OBJECT
public:
    explicit AudioServer(QObject *parent = nullptr);

    QWebSocket* client;

signals:

private slots:


    void slotConnected();
    void slotDisconnected();
    void slotError(QAbstractSocket::SocketError error);


    void onSslErrors(const QList<QSslError> &errors);
};

#endif // AUDIOSERVER_H
