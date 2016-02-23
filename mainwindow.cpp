#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->rbUDtoDMS->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rbUDtoDMS_clicked()
{
    this->ui->labelTextFrom->setText(UD);
    this->ui->labelTextTo->setText(DMS);
}

void MainWindow::on_rbDMStoUD_clicked()
{
    this->ui->labelTextFrom->setText(DMS);
    this->ui->labelTextTo->setText(UD);
}

void MainWindow::on_pushButtonClear_clicked()
{
    this->ui->lineEditLatFrom->clear();
    this->ui->lineEditLonFrom->clear();
    this->ui->lineEditLatTo->clear();
    this->ui->lineEditLonTo->clear();
}

void MainWindow::on_pushButtonConvert_clicked()
{
    QString textLon;
    QString textLat;
    if(this->ui->rbUDtoDMS->isChecked())
    {
        textLon = this->ui->lineEditLonFrom->text();
        textLat = this->ui->lineEditLatFrom->text();
        m_coordinates = m_degree.convertUDToDMS(textLon, textLat);
        this->ui->lineEditLonTo->setText(m_coordinates.lon);
        this->ui->lineEditLatTo->setText(m_coordinates.lat);
    }
    else
    {
        textLon = this->ui->lineEditLonFrom->text();
        textLat = this->ui->lineEditLatFrom->text();
        m_coordinates = m_degree.convertDMStoUD(textLon, textLat);
        this->ui->lineEditLonTo->setText(m_coordinates.lon);
        this->ui->lineEditLatTo->setText(m_coordinates.lat);
    }
}
