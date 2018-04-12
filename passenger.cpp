#include "passenger.h"
#include "ui_passenger.h"
#include <QDateTime>

Passenger::Passenger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passenger)
{
    ui->setupUi(this);
    timer = new QTimer(this);  // constructor takes parent
    connect(timer, SIGNAL(timeout()),
            this, SLOT(mytimer()));
    timer->start(1000);  // update every 1 sec
}

Passenger::~Passenger()
{
    delete ui;
}

void Passenger::mytimer()
{
    QTime time = QTime::currentTime();
    QString timeTxt = time.toString();
    ui->label_time->setText(timeTxt);
}
