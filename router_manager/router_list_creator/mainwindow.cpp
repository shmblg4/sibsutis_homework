#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_confirmButton_clicked()
{
    QString filename = "../rout.dat";
    writeDataToFile(filename);
}

void MainWindow::writeDataToFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::Append))
    {
        // Handle error
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15);

    QString model = ui->modelLineEdit->text();
    qint32 speed = ui->speedSpinBox->value();
    qint32 ports = ui->portsSpinBox->value();
    qint32 antennas = ui->antennasSpinBox->value();
    QString antennaType = ui->antennaTypeLineEdit->text();

    out << model << speed << ports << antennas << antennaType;

    file.close();
}
