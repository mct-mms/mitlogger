#include "loginwindow.h"
#include "mainwindow.h"
#include "ui_loginwindow.h"

void processLoginData(QString in);

LoginWindow::LoginWindow(QWidget *parent) : QDialog(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    //---------------------------------------------- Window Customization
    this->setWindowTitle("MIT WorkLogger");
    this->setWindowIcon(QIcon(":/resources/logo.png"));
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    //---------------------------------------------- Program Stylesheet
    QFile File(":/style/login.css");
    File.open(QIODevice::ReadOnly);
    QString style( File.readAll() );
    this->setStyleSheet(style);

    //--------------------------------------------- Logo Setting
    QLabel label;
    QPixmap pixmap(":/resources/icons/fulllogo.jpg");
    ui->LogoLabel->setPixmap(pixmap);
    ui->LogoLabel->setMask(pixmap.mask());

    int w = ui->LogoLabel->width();
    int h = ui->LogoLabel->height();
    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->LogoLabel->setPixmap( pixmap.scaled(w,h,Qt::KeepAspectRatio) );

    //----------------------------------------------------------------------




}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_clicked()
{

    this->enteredUsername = ui->usernameLineEdit->text();
    this->enteredPassword = ui->passwordLabel->text();





    this->getUserInfo( this->enteredUsername , this->enteredPassword );


//    this->close();


//    MainWindow* w = new MainWindow(); //Select the default Class for the startup window

//    w->show();
//    this->hide();

}



void LoginWindow::getUserInfo(QString username, QString password)
{
    databaseHandler* DB = new databaseHandler(this);


    qDebug() << "login clicked started \n" ;

    DB->readData( "employees" , &processLoginData );


}

 void processLoginData(QString in)
{
        qDebug() << "Fetched User Data: \n " << in << "End: \n " ;

        QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());
        QJsonObject json = doc.object();

        QJsonArray jsonArray;

        foreach(const QString& key, json.keys())
        {
            qDebug() << "KEY: " << key << "\n";

            QJsonObject Obj = json.value(key).toObject();
            jsonArray.push_back(Obj);
        }


        // TO ACCESS YOUR ARRAY

        for(int i = 0; i<jsonArray.size(); i++)
        {

            QJsonObject child = jsonArray.at(i).toObject();

            qDebug() << "child: "    << child << "\n";

            qDebug() << "Key: "    << json.keys()[0] << "\n";


            qDebug() << "name: "     << child.value("name").toString()      << "\n";
            qDebug() << "title: "    << child.value("title").toString()      << "\n";
            qDebug() << "mainteam: " << child.value("mainteam").toString()  << "\n";
            qDebug() << "username: " << child.value("username").toString()      << "\n";
            qDebug() << "password: " << child.value("password").toString()      << "\n";
            qDebug() << "userrole: " << child.value("userrole").toString()      << "\n";

        }

        if(true)
        {
//            this.done(QDialog::Accepted);
            qDebug() << "username: " << this->enteredUsername   << "\n";

        }
        else
        {

        }

}

