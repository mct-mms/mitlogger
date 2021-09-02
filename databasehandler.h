#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>

class databaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit databaseHandler(QObject *parent = nullptr);
    ~databaseHandler();

    void pushData( QString path , QVariantMap data );
    void readData ( QString path , void (*callBackFunc)(QString DATA) );



private:
    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_networkReply;
    QString DB_PATH = "https://mitlogger-aa08f-default-rtdb.europe-west1.firebasedatabase.app/";

public slots:


signals:



};

#endif // DATABASEHANDLER_H
