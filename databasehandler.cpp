#include "databasehandler.h"

#include <QEventLoop>
#include <QJsonDocument>
#include <QTimer>


databaseHandler::databaseHandler(QObject *parent) : QObject(parent)
{
    m_networkManager = new QNetworkAccessManager(this);

//    m_networkReply = m_networkManager->get(
//                    QNetworkRequest(
//                    QUrl("https://mitlogger-fb1b8-default-rtdb.europe-west1.firebasedatabase.app/employees.json")) );

//    connect( m_networkReply , &QNetworkReply::readyRead , this ,[=](){ qDebug()<< m_networkReply->readAll(); } );

}

databaseHandler::~databaseHandler()
{
    m_networkManager->deleteLater();
}

void databaseHandler::pushData(QString path, QVariantMap data)
{
    QJsonDocument jsonData = QJsonDocument::fromVariant(data); //Will hold the input data arguments

    QNetworkRequest newRequest( QUrl( DB_PATH + path + ".json" ) ); //Path to the DB storing location

    newRequest.setHeader( QNetworkRequest::ContentTypeHeader , QString("application/json") ); //Define Json datatype

    qDebug() << "pushData at : " + DB_PATH + path + ".json" ;

    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &databaseHandler::onRequestCompleted);


//    m_networkManager->post( newRequest , jsonData.toJson() ); //Adding Data

    QEventLoop loop;
    QTimer getTimer; // let's use a 10 second period for timing out the GET opn

    QTimer::connect(&getTimer,SIGNAL(timeout()),&loop, SLOT(quit()));
    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply*)),&loop, SLOT(quit()));

    m_networkManager->post( newRequest , jsonData.toJson() ); //Adding Data

    getTimer.start(10000); // 10000 milliSeconds wait period for get() method to work properly
    loop.exec();


}

void databaseHandler::putData(QString path, QVariantMap data)
{
    QJsonDocument jsonData = QJsonDocument::fromVariant(data); //Will hold the input data arguments

    QNetworkRequest newRequest( QUrl( DB_PATH + path + ".json" ) ); //Path to the DB storing location

    newRequest.setHeader( QNetworkRequest::ContentTypeHeader , QString("application/json") ); //Define Json datatype

    qDebug() << "putData at : " + DB_PATH + path + ".json" ;


    m_networkManager->put( newRequest , jsonData.toJson() ); //Adding Data
}

void databaseHandler::readData(QString path , void (*callBackFunc)(QString DATA) )
{
    QNetworkRequest newRequest( QUrl( DB_PATH + path + ".json" ) ); //Path to the DB storing location

    newRequest.setHeader( QNetworkRequest::ContentTypeHeader , QString("application/json") ); //Define Json datatype

    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &databaseHandler::onRequestCompleted);

    m_networkReply = m_networkManager->get( newRequest ); //Getting Data

    connect( m_networkReply , &QNetworkReply::readyRead , this , [=](){ callBackFunc( m_networkReply->readAll() ); } );

}

void databaseHandler::removeData(QString path)
{

    QNetworkRequest newRequest( QUrl( DB_PATH + path + ".json" ) ); //Path to the DB storing location

    newRequest.setHeader( QNetworkRequest::ContentTypeHeader , QString("application/json") ); //Define Json datatype

    qDebug() << "removeData at : " + DB_PATH + path + ".json" ;


    m_networkManager->deleteResource( newRequest ); //Adding Data
}

void databaseHandler::onRequestCompleted(QNetworkReply* reply)
{
    reply->deleteLater();
    qDebug() << "databaseHandler::onRequestCompleted";

}


