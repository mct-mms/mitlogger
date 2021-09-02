#ifndef WEEKLYHOURSCHART_H
#define WEEKLYHOURSCHART_H

#include <QWidget>
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>

class WeeklyHoursChart : public QWidget
{
    Q_OBJECT

public:
    explicit WeeklyHoursChart(QWidget *parent = nullptr);
    QBarSet *set;
    QChartView *chartView;
    QBarSeries *series;
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;



    void setUserName( QString username );
    void setData( QList<qreal> data );



signals:

private slots:
};


//--------------------------------------- How to use the class ----------------------------------------
//    WeeklyHoursChart* WeeklyChart = new WeeklyHoursChart(this);
//    WeeklyChart->setUserName("Mohamed Saad");
//    WeeklyChart->setData( {5,8,8,10,6,7,8,7,6,5,5,8,8,10,6,7,8,7,6,5,5,8,8,10,6,7,8,7,6,5} ); //Adding data hours

//    ui->performanceTabWidget->removeTab(0);
//    ui->performanceTabWidget->insertTab( 0 , WeeklyChart->chartView , "Last 30 Days working hours");
//-----------------------------------------------------------------------------------------------------

#endif // WEEKLYHOURSCHART_H
