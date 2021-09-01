#ifndef TODAYBASEHOURSCHART_H
#define TODAYBASEHOURSCHART_H

#include <QWidget>
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>


class TodayBaseHoursChart : public QWidget
{

    public:
        TodayBaseHoursChart(QWidget *parent);
        QGridLayout* grid;
        QHBoxLayout* layout;


};

#endif // TODAYBASEHOURSCHART_H
