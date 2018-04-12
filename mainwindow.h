#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <passenger.h>
#include <journey.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_nextPassenger_clicked();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    Passenger *pass1;
    Journey *jou1;
};

#endif // MAINWINDOW_H
