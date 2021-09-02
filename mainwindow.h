#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMainWindow>
#include <QtCharts>
#include <QPushButton>
#include <QChartView>
#include <QLineSeries>
#include <QApplication>
#include <QFile>
#include <QDialog>
#include <QSslSocket> //To use QSslSocket Class

#include <databasehandler.h>
#include "taskstable.h"
#include "telegramhandler.h"
#include "infodialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    telegramHandler* bot;

    TasksTable* EmployeeTasks;


    QString currentUsername = "M.saad";
    QString currentUserFullName = "Mohamed Saad";
    QString currentUserMainTeam = "Electronics Team";
    QString currentUserSubTeam = "GUI";
    QString TodayDate = "30 Aug";
    QString currentTime = "11:15AM";





private slots:

    void on_actionChange_password_triggered();

    void on_actionStart_from_home_triggered();

    void on_actionArrived_office_triggered();

    void on_actionPause_working_triggered();

    void on_actionResumed_working_triggered();

    void on_actionLeft_office_triggered();

    void on_actionStopped_from_home_triggered();

    void on_addTaskButton_clicked();

    void on_editTaskButton_clicked();

    void on_deleteTaskButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
