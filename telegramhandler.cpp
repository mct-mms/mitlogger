#include "telegramhandler.h"
#include <QMessageBox>

telegramHandler::telegramHandler(QObject *parent) : QObject(parent)
{

    URL = "https://api.telegram.org/bot";
    URL.append(BOT_KEY);
    URL.append("/sendMessage?chat_id=-");
    URL.append( Channel_idNo );
    URL.append("&text=");

}


void telegramHandler::sendChannelMessage(QString MSG)
{
    m_networkManager = new QNetworkAccessManager(this);

    connect(m_networkManager, &QNetworkAccessManager::finished ,this, &telegramHandler::onfinish );
    connect(m_networkManager, &QNetworkAccessManager::finished ,m_networkManager, &QObject::deleteLater );

    m_networkManager->get(  QNetworkRequest( QUrl( URL + MSG ) )  );
}


void telegramHandler::onfinish(QNetworkReply *rep)
{
    //------------------------------------- Printing Bot Response After sending a message
//    QByteArray bts = rep->readAll();
//    QString str(bts);
//    qDebug()<< "Response : " << str ;
}
