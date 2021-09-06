#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QFile>
#include <QIcon>
#include <QVariantMap>
#include "databasehandler.h"


namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    QString enteredUsername;
    QString enteredPassword;

    void getUserInfo( QString username , QString password );


private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;

};

#endif // LOGINWINDOW_H
