#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "todaybasehourschart.h"
#include "weeklyhourschart.h"

void fetchedUserData( QString in );


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //--------------------------------------------------------------------------- Window Settings

    //---------------------------------------------- Window Customization
    this->setWindowTitle("MIT WorkLogger");
    this->setWindowIcon(QIcon(":/resources/logo.png"));
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    //---------------------------------------------- Program Stylesheet
    QFile File(":/style/style.css");
    File.open(QIODevice::ReadOnly);
    QString style( File.readAll() );
    this->setStyleSheet(style);

    //-------------------------------------------------------------------------- Left Info Panel settings
    //--------------------------------------------- Logo Setting
    QLabel label;
    QPixmap pixmap(":/resources/icons/fulllogo.jpg");
    ui->companyLogo->setPixmap(pixmap);
    ui->companyLogo->setMask(pixmap.mask());

    int w = ui->companyLogo->width();
    int h = ui->companyLogo->height();
    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->companyLogo->setPixmap( pixmap.scaled(w,h,Qt::KeepAspectRatio) );

    //---------------------------------------------- Info Labels
    //# get the palette
    QPalette palette1 = ui->todayHoursLabel->palette();
    QPalette palette2 = ui->todayMinutesLabel->palette();
    QPalette palette3 = ui->weekHoursLabel->palette();
    QPalette palette4 = ui->weekMinutesLabel->palette();

    //# foreground color
    palette1.setColor(palette1.WindowText, QColor(0x1c4e80) );
    palette2.setColor(palette2.WindowText, QColor(0x1c4e80) );
    palette3.setColor(palette3.WindowText, QColor(0x1c4e80) );
    palette4.setColor(palette4.WindowText, QColor(0x1c4e80) );

    //# set the palette
    ui->todayHoursLabel->setPalette(palette1);
    ui->todayMinutesLabel->setPalette(palette2);
    ui->weekHoursLabel->setPalette(palette3);
    ui->weekMinutesLabel->setPalette(palette4);

    //#Aligning labels texts
    ui->HoursLabel->setAlignment( Qt::AlignHCenter );
    ui->HoursLabel_2->setAlignment( Qt::AlignHCenter );
    ui->MinutesLabel->setAlignment( Qt::AlignHCenter );
    ui->MinutesLabel_2->setAlignment( Qt::AlignHCenter );
    ui->nameLabel->setAlignment( Qt::AlignHCenter );
    ui->titleLabel->setAlignment( Qt::AlignHCenter );
    ui->teamLabel->setAlignment( Qt::AlignHCenter );


    //-------------------------------------------------------------------------- Telegram settings

    bot = new telegramHandler(); //Initialization of Telegram Bot


    //-------------------------------------------------------------------------- Today Progress section
    EmployeeTasks = new TasksTable(this);
    ui->TasksWidget->removeTab(0);
    ui->TasksWidget->insertTab(0 , EmployeeTasks->m_pTableWidget , "Today Tasks");
    ui->TasksWidget->setCurrentIndex(0);


    //--------------------------------------------------------------------------- Firebase Section
//    DB = new databaseHandler(this);

//    QVariantMap DATA;
//    DATA["name"] = "Mohamed Saad22";
//    DATA["mainteam"] = "Electronics";
//    DATA["userrole"] = "admin";
//    DATA["title"] = "Software Engineer";
//    DATA["username"] = "msaad";
//    DATA["password"] = "456789";
//    DB->pushData( "zz",DATA );




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickedArrive()
{
    qDebug() << "clickedArrive()";

    databaseHandler* DB = new databaseHandler();
//    QEventLoop loop;




    QVariantMap DATA;
    DATA[".sv"] = "timestamp"; //Add Timestamp
    DATA["type"] = "arrive_office";
    DATA["fullname"] = currentUserFullName;
    DATA["username"] = currentUsername;
    DATA["mainteam"] = currentUserMainTeam;
    DATA["subteam"] = currentUserSubTeam;

//    DB->readData( "employees" , &fetchedUserData );

    DB->pushData("fromArrive", DATA );
//    DB->readData( "employees" , &fetchedUserData );

//    loop.exec();


}



void MainWindow::on_actionChange_password_triggered()
{

}


void MainWindow::on_actionArrived_office_triggered()
{
    ui->actionArrived_office->setEnabled(false);
    ui->actionStart_from_home->setEnabled(false);
    ui->actionPause_working->setEnabled(true);
    ui->actionResumed_working->setEnabled(false);
    ui->actionStopped_from_home->setEnabled(false);
    ui->actionLeft_office->setEnabled(true);

    QString MessageForm;
    QString ArrivedEmoj= "🏣";

    MessageForm.append( TodayDate ).append(" | ").append(currentTime).append("%0A"); // "%0A" is a new line
    MessageForm.append( currentUserFullName ).append(" | ").append(ArrivedEmoj).append(" Arrived Office"); // "%0A" is a new line

    bot->sendChannelMessage(MessageForm);

    this->clickedArrive();

//    databaseHandler* DB = new databaseHandler();


//    QVariantMap DATA;
//    DATA[".sv"] = "timestamp"; //Add Timestamp
//    DATA["type"] = "arrive_office";
//    DATA["fullname"] = currentUserFullName;
//    DATA["username"] = currentUsername;
//    DATA["mainteam"] = currentUserMainTeam;
//    DATA["subteam"] = currentUserSubTeam;

////    DB->readData( "employees" , &fetchedUserData );

//    DB->pushData("fromArrive", DATA );
}


void MainWindow::on_actionStart_from_home_triggered()
{
    ui->actionArrived_office->setEnabled(false);
    ui->actionStart_from_home->setEnabled(false);
    ui->actionPause_working->setEnabled(true);
    ui->actionResumed_working->setEnabled(false);
    ui->actionStopped_from_home->setEnabled(true);
    ui->actionLeft_office->setEnabled(false);

    QString MessageForm;
    QString ArrivedEmoj= "\U00002733";

    MessageForm.append( TodayDate ).append(" | ").append(currentTime).append("%0A"); // "%0A" is a new line
    MessageForm.append( currentUserFullName ).append(" | ").append(ArrivedEmoj).append(" Started from home"); // "%0A" is a new line

    bot->sendChannelMessage(MessageForm);

    QVariantMap DATA;
    DATA[".sv"] = "timestamp"; //Add Timestamp
    DATA["type"] = "home_start";
    DATA["fullname"] = currentUserFullName;
    DATA["username"] = currentUsername;
    DATA["mainteam"] = currentUserMainTeam;
    DATA["subteam"] = currentUserSubTeam;

//    DB->pushData("attendancelog", DATA );
}


void MainWindow::on_actionPause_working_triggered()
{
    ui->actionArrived_office->setEnabled(true);
    ui->actionStart_from_home->setEnabled(true);
    ui->actionPause_working->setEnabled(false);
    ui->actionResumed_working->setEnabled(true);
    ui->actionStopped_from_home->setEnabled(true);
    ui->actionLeft_office->setEnabled(false);

    QString MessageForm;
    QString ArrivedEmoj= "⏸";

    MessageForm.append( TodayDate ).append(" | ").append(currentTime).append("%0A"); // "%0A" is a new line
    MessageForm.append( currentUserFullName ).append(" | ").append(ArrivedEmoj).append(" Paused working"); // "%0A" is a new line

    bot->sendChannelMessage(MessageForm);

    QVariantMap DATA;
    DATA[".sv"] = "timestamp"; //Add Timestamp
    DATA["type"] = "pause";
    DATA["fullname"] = currentUserFullName;
    DATA["username"] = currentUsername;
    DATA["mainteam"] = currentUserMainTeam;
    DATA["subteam"] = currentUserSubTeam;

//    DB->pushData("attendancelog", DATA );

}


void MainWindow::on_actionResumed_working_triggered()
{
    ui->actionArrived_office->setEnabled(false);
    ui->actionStart_from_home->setEnabled(false);
    ui->actionPause_working->setEnabled(true);
    ui->actionResumed_working->setEnabled(false);
    ui->actionStopped_from_home->setEnabled(true);
    ui->actionLeft_office->setEnabled(true);

    QString MessageForm;
    QString ArrivedEmoj= "\U00002733";

    MessageForm.append( TodayDate ).append(" | ").append(currentTime).append("%0A"); // "%0A" is a new line
    MessageForm.append( currentUserFullName ).append(" | ").append(ArrivedEmoj).append(" Resumed Working"); // "%0A" is a new line

    bot->sendChannelMessage(MessageForm);

    QVariantMap DATA;
    DATA[".sv"] = "timestamp"; //Add Timestamp
    DATA["type"] = "resume";
    DATA["fullname"] = currentUserFullName;
    DATA["username"] = currentUsername;
    DATA["mainteam"] = currentUserMainTeam;
    DATA["subteam"] = currentUserSubTeam;

//    DB->pushData("attendancelog", DATA );
}


void MainWindow::on_actionLeft_office_triggered()
{
    ui->actionArrived_office->setEnabled(true);
    ui->actionStart_from_home->setEnabled(true);
    ui->actionPause_working->setEnabled(false);
    ui->actionResumed_working->setEnabled(false);
    ui->actionStopped_from_home->setEnabled(false);
    ui->actionLeft_office->setEnabled(false);

    QString MessageForm;
    QString ArrivedEmoj= "\xF0\x9F\x8F\x81";

    MessageForm.append( TodayDate ).append(" | ").append(currentTime).append("%0A"); // "%0A" is a new line
    MessageForm.append( currentUserFullName ).append(" | ").append(ArrivedEmoj).append(" Left Office"); // "%0A" is a new line

    bot->sendChannelMessage(MessageForm);

    QVariantMap DATA;
    DATA[".sv"] = "timestamp"; //Add Timestamp
    DATA["type"] = "office_left";
    DATA["fullname"] = currentUserFullName;
    DATA["username"] = currentUsername;
    DATA["mainteam"] = currentUserMainTeam;
    DATA["subteam"] = currentUserSubTeam;

//    DB->pushData("attendancelog", DATA );

}


void MainWindow::on_actionStopped_from_home_triggered()
{
    ui->actionArrived_office->setEnabled(true);
    ui->actionStart_from_home->setEnabled(true);
    ui->actionPause_working->setEnabled(false);
    ui->actionResumed_working->setEnabled(false);
    ui->actionStopped_from_home->setEnabled(false);
    ui->actionLeft_office->setEnabled(false);


    QString MessageForm;
    QString ArrivedEmoj= "🔴";

    MessageForm.append( TodayDate ).append(" | ").append(currentTime).append("%0A"); // "%0A" is a new line
    MessageForm.append( currentUserFullName ).append(" | ").append(ArrivedEmoj).append(" Stopped from home"); // "%0A" is a new line


    if(  EmployeeTasks->tasksRowIndex >0  )
    {
        MessageForm.append("%0A");// Add new line to the message
        MessageForm.append("✅"); //Add emoji
        MessageForm.append(" Today Progress:");
        MessageForm.append("%0A------------%0A");// Add new line to the message


        foreach( QString item, EmployeeTasks->tasksListArray )
        {
            MessageForm.append("--> ");
            MessageForm.append(item); //Adding the tasks
            MessageForm.append("%0A");// Add new line to the message

        }
    }


    bot->sendChannelMessage(MessageForm); //Send the message to the telegram

    QVariantMap DATA;
    DATA[".sv"] = "timestamp"; //Add Timestamp
    DATA["type"] = "home_stop";
    DATA["fullname"] = currentUserFullName;
    DATA["username"] = currentUsername;
    DATA["mainteam"] = currentUserMainTeam;
    DATA["subteam"] = currentUserSubTeam;

//    DB->pushData("timestamp", DATA );
}


void MainWindow::on_addTaskButton_clicked()
{
    InfoDialog * dialog = new InfoDialog(this);

    int ret =dialog->exec(); //Show the dialog

    if( ret == QDialog::Accepted)
    {
        QString TaskDetails = dialog->getTaskDetails();

        EmployeeTasks->addTask(TaskDetails);

//        qDebug() << "TaskDetails : " << TaskDetails;
    }

    if( ret == QDialog::Rejected)
    {
        qDebug() << "Dialog rejected";
    }


}


void MainWindow::on_editTaskButton_clicked()
{
    InfoDialog * dialog = new InfoDialog(this);

    int selectedTask = EmployeeTasks->getSelectedTask();

    QString selectedTaskData =  EmployeeTasks->m_pTableWidget->model()->index( selectedTask , 1 ).data().toString();

    dialog->setTaskDetails( selectedTaskData );

    int ret =dialog->exec(); //Show the dialog

    if( ret == QDialog::Accepted)
    {
        QString TaskDetails = dialog->getTaskDetails();

        EmployeeTasks->replaceTask( selectedTask , TaskDetails);

//        qDebug() << "TaskDetails : " << TaskDetails;
    }

    if( ret == QDialog::Rejected)
    {
        qDebug() << "Dialog rejected";
    }
}


void MainWindow::on_deleteTaskButton_clicked()
{
    int selectedTask = EmployeeTasks->getSelectedTask();

    if( selectedTask>=0 )
    {
        QMessageBox msgBox;
        QPushButton *connectButton = msgBox.addButton(tr("Delete"), QMessageBox::ActionRole);
        QPushButton *abortButton = msgBox.addButton(QMessageBox::Abort);
        msgBox.setText("Are you sure you want to delete the task?");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowIcon(QIcon(":/resources/logo.png"));
        msgBox.exec();

        if (msgBox.clickedButton() == connectButton)
        {
            qDebug() << "Delete task is confirmed";
            EmployeeTasks->deleteSelectedTask(selectedTask);

        } else if (msgBox.clickedButton() == abortButton)
        {
            qDebug() << "Delete task is aborted";

        }
    }


}

