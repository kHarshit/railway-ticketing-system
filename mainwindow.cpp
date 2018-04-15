#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextPassenger_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(username == "test" && password == "test"){
        jou1 = new Journey(this);
        this->hide();
        jou1->show();
    }
    else
        ui->statusBar->showMessage("username and password not correct. Please try again!", 3500);
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAbout_triggered()
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

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionReport_Bug_triggered()
{

}
