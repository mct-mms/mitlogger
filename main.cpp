#include "mainwindow.h"
#include "loginwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w; //Select the default Class for the startup window
    LoginWindow w; //Select the default Class for the startup window



    QTextStream out(stdout);

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    qDebug() << "Current date is: " << cd.toString() << "\n";
    qDebug() << "Current time is: " << ct.toString() << "\n";


    w.show();
    return a.exec();
}



/*
 *
 *  QApplication a(argc, argv);

    SecDialog *SecDialogPage = new SecDialog();
    SecDialogPage->setWindowFlags(Qt::Window);

    if(SecDialogPage->exec() == QDialog::Accepted)
    {
        MainWindow *MainWindowPage = new MainWindow();
        MainWindowPage->showMaximized();
    }

    SecDialogPage->deleteLater();

    return a.exec();
 *
 */
