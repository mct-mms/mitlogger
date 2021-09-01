#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent,Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}
