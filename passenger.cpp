#include "passenger.h"
#include "ui_passenger.h"

Passenger::Passenger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passenger)
{
    ui->setupUi(this);
}

Passenger::~Passenger()
{
    delete ui;
}
