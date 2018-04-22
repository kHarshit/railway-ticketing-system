#include "journey.h"
#include "ui_journey.h"
#include <QDateTime>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QFile>
#include <QString>
#include <QDebug>

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

void Journey::on_pushButton_bookTicket_clicked()
{
    /* file handling: csv data input functionality */
    QFile file(":/fare.csv");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << file.errorString();
    }
    QList<QString> fromList, toList, fareList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        fromList.append(line.split(',').first());  // selecting first column
        toList.append(line.split(',').at(1));
        fareList.append(line.split(',').at(2));
    }

    /* Button functionality */
    QString fromStation = ui->comboBox_from->currentText();
    QString toStation = ui->comboBox_to->currentText();

    if(fromStation == "----" ||
            toStation == "----")
        QMessageBox::warning(this, "Error!", "Please select From and To stations");

    else if (fromStation == toStation)
        QMessageBox::warning(this, "Error!", "From to To stations can\'t be same.");

    else {
        QString cost;
        qint16 id;

        /*
         * l1 = ("a", "b", "d", "c", "d", "b")
         * l2 = ("b", "a", "b", "b", "a", "c")
         * l3 = (2, 4, 3, 5, 4, 5)  // fare
         * if index of inputs in l1 and l2 are same then fare will be the value at that index in l3
         * if "d" and "a" are input then index will be 5 hence fare will be the value corresponding to index 5 in l3 i.e. 4
         * */

        for (int i = 0; i < fromList.size(); ++i) {
                if (fromList.indexOf(fromStation) == toList.indexOf(toStation)){
                    id = fromList.indexOf(fromStation);
                    break;
                }
        }

        if (id == 0){
            for (int i = 0; i < toList.size(); ++i) {
                if (toList.indexOf(fromStation) == fromList.indexOf(toStation)){
                    id = toList.indexOf(toStation);
                    qDebug() << id;
                    break;
                }
            }
            //cost = "NA";
        }
        cost = fareList.at(id);

        qDebug() << "fromStation: " << fromStation
                 << ", toStation: " << toStation
                 << ", id: " << id
                 << ", cost: " << cost;

        QMessageBox::information(this,
                                 "Ticket booked",
                                 "Hello " +
                                 ui->lineEdit_PassengerName->text() +
                                 "!\nYour ticket from " +
                                 fromStation +
                                 " to " +
                                 toStation +
                                 " on " +
                                 ui->dateEdit->text() +
                                 " is confirmed.\n"
                                 "Cost: ₹" + cost +
                                 "\n\nDetails:\n" +
                                 "Passenger Name: " + ui->lineEdit_PassengerName->text() +
                                 "\nFrom: " + fromStation +
                                 "\nDate of Journey: " + ui->dateEdit->text() +
                                 "\nTo: " + toStation +
                                 "\nCoach No: " +
                                 QString(QChar('A' + (qrand() % 9))) +  // random character
                                 QString::number(qrand() % 9)  // random number
                                 );
    }
}
