#include "mainwindow.h"






int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //---------------------------------------------- Window Customization
    w.setWindowTitle("MIT WorkLogger");
    w.setWindowIcon(QIcon(":/resources/logo.png"));
    w.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    //---------------------------------------------- Program Stylesheet
    QFile File(":/style/style.css");
    File.open(QIODevice::ReadOnly);
    QString style( File.readAll() );
    a.setStyleSheet(style);

    //------------------------------------------------


    //------------------------------------

    w.show();
    return a.exec();
}


