#ifndef TASKSTABLE_H
#define TASKSTABLE_H

#include <QObject>
#include <QTableWidget>
#include <QWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>

class TasksTable : public QWidget
{
    Q_OBJECT

public:
    explicit TasksTable(QWidget *parent = nullptr);
    QTableWidget* m_pTableWidget;
    char tasksRowIndex = 0;

    QList <QString> tasksListArray;



private:

    QStringList m_TableHeader;

public slots:

    void cellSelected(int nRow, int nCol);

    void addTask(QString TaskDetails);
    int getSelectedTask();
    void replaceTask( int index , QString DATA );
    void deleteSelectedTask( int index );
};

#endif // TASKSTABLE_H
