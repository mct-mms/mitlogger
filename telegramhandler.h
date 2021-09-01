#ifndef TELEGRAMHANDLER_H
#define TELEGRAMHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>

class telegramHandler : public QObject
{
    Q_OBJECT

public:
    explicit telegramHandler(QObject *parent = nullptr);
    void sendChannelMessage(QString MSG);
    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_networkReply;
    QString BOT_KEY = "1957538655:AAENDdP6SNy7kA8I0fBXZQLv_2nquakkJbc";
    QString Channel_ID = "@mitloggerchannel";
    QString Channel_idNo= "1001384076516";
    QString URL;


public slots:
    void onfinish(QNetworkReply *rep);
private:



signals:

};

#endif // TELEGRAMHANDLER_H
