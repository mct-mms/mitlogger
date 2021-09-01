#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent,Qt::WindowSystemMenuHint | Qt::WindowTitleHint),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);

}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okButton_clicked()
{

    //Collect information
    QString taskDetails = ui->taskDetailsInput->toPlainText();

    if( !taskDetails.isEmpty())
    {
        TaskFetchedDetails = taskDetails;
    }

    // Accept the dialog
    accept();

}

void InfoDialog::on_cancelButton_clicked()
{
    //
    reject();
}

QString InfoDialog::getTaskDetails() const
{
    return TaskFetchedDetails;
}

void InfoDialog::setTaskDetails(QString DATA) const
{
    ui->taskDetailsInput->setPlainText(DATA);
}
