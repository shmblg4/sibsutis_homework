// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readDataFromFile("../rout.dat");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readDataFromFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        // Handle error
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_15);

    for (int i = 0; i < 20; ++i)
    {
        QString model;
        qint32 speed, ports, antennas;
        QString antennaType;
        in >> model >> speed >> ports >> antennas >> antennaType;
        qDebug() << "Model:" << model << ", Speed:" << speed << ", Ports:" << ports << ", Antennas:" << antennas << ", Antenna Type:" << antennaType;
    }

    file.close();
}

bool MainWindow::findRouterModel(const QString &model)
{
    QFile file("../rout.dat");
    if (!file.open(QIODevice::ReadOnly))
    {
        // Handle error
        return false;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_15);

    while (!in.atEnd())
    {
        QString readModel;
        qint32 speed, ports, antennas;
        QString antennaType;
        in >> readModel >> speed >> ports >> antennas >> antennaType;
        if (readModel == model)
        {
            ui->resultLabel->setText("Model: " + readModel + ", Speed: " + QString::number(speed) + ", Ports: " + QString::number(ports) +
                                     ", Antennas: " + QString::number(antennas) + ", Antenna Type: " + antennaType);
            file.close();
            return true;
        }
    }

    ui->resultLabel->setText("Model not found.");
    file.close();
    return false;
}

void MainWindow::on_searchButton_clicked()
{
    QString searchModel = ui->searchModelLineEdit->text();
    findRouterModel(searchModel);
}
