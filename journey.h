#ifndef JOURNEY_H
#define JOURNEY_H

#include <QMainWindow>
#include <QDialog>
#include <QTimer>

namespace Ui {
class Journey;
}

class Journey : public QMainWindow
{
    Q_OBJECT

public:
    explicit Journey(QWidget *parent = 0);
    ~Journey();

public slots:
    void mytimer();

private slots:
    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionHome_triggered();

private:
    Ui::Journey *ui;
    QTimer *timer;
};

#endif // JOURNEY_H
