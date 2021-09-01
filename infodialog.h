#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    QString getTaskDetails() const;
    void setTaskDetails( QString DATA ) const;


private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    QString TaskFetchedDetails;
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
