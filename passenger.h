#ifndef PASSENGER_H
#define PASSENGER_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class Passenger;
}

class Passenger : public QDialog
{
    Q_OBJECT

public:
    explicit Passenger(QWidget *parent = 0);
    ~Passenger();

public slots:
    void mytimer();

private:
    Ui::Passenger *ui;
    QTimer *timer;
};

#endif // PASSENGER_H
