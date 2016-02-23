#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "degrees.h"
#include "QDebug"

namespace Ui {
class MainWindow;
}

const QString UD = "Usual Degrees:";
const QString DMS = "Degrees, Minutes, Seconds:";

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_rbUDtoDMS_clicked();

    void on_rbDMStoUD_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonConvert_clicked();

private:
    Ui::MainWindow *ui;
    Degrees m_degree;
    Coord m_coordinates;
};

#endif // MAINWINDOW_H
