#include "todaybasehourschart.h"
#include <QHBoxLayout>
#include <QStyleOption>
#include <QWidget>

TodayBaseHoursChart::TodayBaseHoursChart(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout();


    QLabel* hoursLabel = new QLabel();
    QLabel* minutesLabel = new QLabel();
    QLabel* hoursLabelText = new QLabel();
    QLabel* minutesLabelText = new QLabel();

    hoursLabel->setText("05");
    minutesLabel->setText("53");

    hoursLabelText->setText("Hours");
    minutesLabelText->setText("Minutes");

    hoursLabel->setAccessibleName("hoursLabel");
    minutesLabel->setAccessibleName("minutesLabel");

    hoursLabelText->setAccessibleName("hoursLabelText");
    minutesLabelText->setAccessibleName("minutesLabelText");

    hoursLabel->setAutoFillBackground(true);
    minutesLabel->setAutoFillBackground(true);
    hoursLabelText->setAutoFillBackground(true);
    minutesLabelText->setAutoFillBackground(true);


    grid->addWidget(hoursLabel , 0 , 0 );
    grid->addWidget(minutesLabel , 0 , 1);

    grid->addWidget(hoursLabelText , 1 , 0);
    grid->addWidget(minutesLabelText , 1 , 1);

    layout = new QHBoxLayout(this);

    auto widget = new QWidget();
       widget->setLayout( grid );

    layout->addWidget(widget);


//    QFrame* FrameContainer = new QFrame (this);

//    FrameContainer->setLayout(layout);


}
