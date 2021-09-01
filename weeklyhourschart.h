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

#endif // WEEKLYHOURSCHART_H
