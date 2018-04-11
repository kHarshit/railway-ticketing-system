#ifndef PASSENGER_H
#define PASSENGER_H

#include <QDialog>

namespace Ui {
class Passenger;
}

class Passenger : public QDialog
{
    Q_OBJECT

public:
    explicit Passenger(QWidget *parent = 0);
    ~Passenger();

private:
    Ui::Passenger *ui;
};

#endif // PASSENGER_H
