#include "journey.h"
#include "ui_journey.h"
#include <QDateTime>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>

Journey::Journey(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Journey)
{
    ui->setupUi(this);
    timer = new QTimer(this);  // constructor takes parent
    connect(timer, SIGNAL(timeout()),
            this, SLOT(mytimer()));
    timer->start(1000);  // update every 1 sec
}

Journey::~Journey()
{
    delete ui;
}

void Journey::mytimer()
{
    QTime time = QTime::currentTime();
    QString timeTxt = time.toString();
    ui->label_time->setText(timeTxt);
}

void Journey::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}


void Journey::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About",
                       "This is a Railway Reservation System \n"
                       "developed for the OOP project.\n\n"
                       "Tools & Technologies used:\n"
                       "C++\n"
                       "Qt\n\n"
                       "Developers:\n"
                       "Harshit Kumar (024)\n"
                       "Abhishek (002)\n"
                       "Aman Deep (008)");
}

void Journey::on_actionQuit_triggered()
{
    QApplication::quit();
}

void Journey::on_actionHome_triggered()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}
