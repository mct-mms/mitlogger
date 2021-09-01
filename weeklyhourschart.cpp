#include "weeklyhourschart.h"
#include <QMouseEvent>
 #include <QGraphicsSimpleTextItem>


WeeklyHoursChart::WeeklyHoursChart(QWidget *parent) : QWidget(parent)
{



}

void WeeklyHoursChart::setUserName(QString username)
{
    set = new QBarSet(username);

//    qDebug() << username ;

}

void WeeklyHoursChart::setData(QList<qreal> data)
{
//    set->remove(6,7);
//    set->append(data);

    //---------------------
    QLineSeries *series = new QLineSeries();

    QList<qreal>::iterator i;
    char loopIndex = 1;

    for (i = data.begin(); i != data.end(); ++i)
    {
//        qDebug() << "ITEM : "  << *i << "\n";
        series->append(loopIndex, *i);
        loopIndex++;
    }

    chart = new QChart();
    chart->addSeries(series);
//    chart->setTitle("Weekly working hours");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//    chart->createDefaultAxes();

//    QStringList categories;
//    categories << "SUN" << "MON" << "TUE" << "WED" << "THU" << "FRI" << "SAT" ;

//    axisX = new QBarCategoryAxis();
//    axisX->append(categories);
//    chart->addAxis(axisX, Qt::AlignBottom);
//    series->attachAxis(axisX);

    axisX = new QValueAxis();
    axisX->setRange(0,30);
//    axisX->setTickCount(30);
//    axisX->setMinorTickCount(30);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(0,12);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(false);
//    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->layout()->setContentsMargins(0, 0, 0, 0);
    chart->setBackgroundRoundness(0);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);



//    qDebug() << data ;
}


