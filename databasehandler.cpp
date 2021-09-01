#include "databasehandler.h"

#include <QJsonDocument>


databaseHandler::databaseHandler(QObject *parent) : QObject(parent)
{
    m_networkManager = new QNetworkAccessManager(this);

//    m_networkReply = m_networkManager->get(
//                    QNetworkRequest(
//                    QUrl("https://mitlogger-fb1b8-default-rtdb.europe-west1.firebasedatabase.app/empolyees.json")) );

//    connect( m_networkReply , &QNetworkReply::readyRead , this ,&databaseHandler::networkReplyReadyRead );

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

    m_networkManager->post( newRequest , jsonData.toJson() ); //Adding Data

}

void databaseHandler::readData(QString path , void (*callBackFunc)(QString DATA) )
{
    QNetworkRequest newRequest( QUrl( DB_PATH + path + ".json" ) ); //Path to the DB storing location

    newRequest.setHeader( QNetworkRequest::ContentTypeHeader , QString("application/json") ); //Define Json datatype

    m_networkReply = m_networkManager->get( newRequest ); //Getting Data

    connect( m_networkReply , &QNetworkReply::readyRead , this , [=](){ callBackFunc( m_networkReply->readAll() ); } );

}

//void databaseHandler::networkReplyReadyRead( void (*func)(QString DATA) )
//{
////    qDebug()<< m_networkReply->readAll();
//    func( m_networkReply->readAll() );
//}