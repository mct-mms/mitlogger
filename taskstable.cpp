#include "taskstable.h"



TasksTable::TasksTable(QWidget *parent) : QWidget(parent)
{

    //-------------------------------------------------------------- Table Creation
    m_pTableWidget = new QTableWidget(this);
    m_pTableWidget->setRowCount(0); //At each new task pushed we add a new row so we start with 0 rows here
    m_pTableWidget->setColumnCount(2);


    //-------------------------------------------------------------- Table Header
    QHeaderView* header = m_pTableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setSectionResizeMode( 0, QHeaderView::Fixed );
    m_TableHeader<<"NO."<<"Task Details";
    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);


    //-------------------------------------------------------------- Table Characteristics
    m_pTableWidget->verticalHeader()->setVisible(false);
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pTableWidget->setShowGrid(true);





    connect( m_pTableWidget, SIGNAL( cellDoubleClicked (int, int) ), this, SLOT( cellSelected( int, int ) ) );



}

void TasksTable::addTask(QString TaskDetails)
{
    //------------------------------------------------------- Adding a new row
    m_pTableWidget->insertRow( m_pTableWidget->rowCount() );

    //------------------------------------------------------- Row Items
    QTableWidgetItem* rowIndex = new QTableWidgetItem();
    rowIndex->setTextAlignment(Qt::AlignCenter);
    rowIndex->setData( Qt::DisplayRole, (tasksRowIndex+1) );
    m_pTableWidget->setItem( tasksRowIndex , 0 , rowIndex); //Insert data into table row

    QTableWidgetItem* item = new QTableWidgetItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setData( Qt::DisplayRole, TaskDetails );
    m_pTableWidget->setItem( tasksRowIndex , 1 , item); //Insert data into table row

    tasksListArray.append(TaskDetails); //Storing the task to the tasks array

    tasksRowIndex++; //Increment the Tasks rows index for the next data insertion

}

int TasksTable::getSelectedTask()
{
    QModelIndexList selectedRows = m_pTableWidget->selectionModel()->selectedRows();
//    QString fetchedTask;
    int selectedTaskIndex = -1 ;

    if( !selectedRows.empty() ) //Check if the user selected a task
    {

        foreach( QModelIndex index, selectedRows )
        {
            selectedTaskIndex = index.row();
//            fetchedTask =  m_pTableWidget->model()->index( selectedTaskIndex , 1 ).data().toString();
//            qDebug() << "Selected row : " << fetchedTask ;
        }
    }
    else
    {
        qDebug() << "No Task is selected";
    }

    return  selectedTaskIndex;

}

void TasksTable::replaceTask(int index, QString DATA)
{
    QTableWidgetItem* rowIndex = new QTableWidgetItem();
    rowIndex->setTextAlignment(Qt::AlignCenter);
    rowIndex->setData( Qt::DisplayRole, (index+1) );
    m_pTableWidget->setItem( index , 0 , rowIndex); //Insert data into table row

    QTableWidgetItem* item = new QTableWidgetItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setData( Qt::DisplayRole, DATA );
    m_pTableWidget->setItem( index , 1 , item); //Insert data into table row



    tasksListArray.replace(index ,  DATA); //Storing the task to the tasks array

}


void TasksTable::deleteSelectedTask(int index)
{

    if(index >= 0)
    {

        if(index<tasksRowIndex) //check if there are some table rows after the deleted row
        {
            //Fix the index of the task next to the deleted one (Index needs to be decremented by 1)

            int followingTasksIndex =  index+1;

            for(int i=followingTasksIndex ; i<tasksRowIndex ; i++ )
            {
                QTableWidgetItem* rowIndex = new QTableWidgetItem();
                rowIndex->setTextAlignment(Qt::AlignCenter);
                rowIndex->setData( Qt::DisplayRole, i );
                m_pTableWidget->setItem( i , 0 , rowIndex ); //Insert data into table row
            }

        }

        //Delete the row
        m_pTableWidget->removeRow( index );

        if(tasksRowIndex>0)
        {
            tasksRowIndex--;
        }

        tasksListArray.removeAt(index); //Update the tasks array

    }
    else
    {
        //No tasks selected
    }


}


void TasksTable::cellSelected(int nRow, int nCol)
{
    qDebug() << "Cell Clicked";

    QMessageBox::information(this, "",
    "Cell at row "+ QString::number(nRow) + " column " + QString::number(nCol) + " was double clicked.");

}


