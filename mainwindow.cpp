#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCustomPlot *QCP = ui->widget;

    Wave wave(3000, 150000);
    int i;
    for (i = 0; i < 178; i++) {
        wave.step();
    }
    QVector<PointPressure> pV = wave.getWave();
    for (i = 0; i < pV.size(); i++) {
        qDebug() << pV[i].x << pV[i].y;
    }

    QVector<double> vectorForQCP_x, vectorForQCP_y;

    for (int i = 0; i < pV.size(); i++)
    {
        vectorForQCP_x.push_back(pV[i].x);
        vectorForQCP_y.push_back(pV[i].y);
    }
    //QCP->xAxis->setRange(0,vectorForQCP_x.back()*1.05);
    QCP->xAxis->setRange(0,vectorForQCP_x.back()*1.05);
    QCP->yAxis->setRange(0,2.91805e-08);
    QCP->addGraph();
    QCP->graph(0)->addData(vectorForQCP_x,vectorForQCP_y);
    QCP->replot();
    QCP->setInteraction(QCP::iRangeDrag,true);
    QCP->setInteraction(QCP::iRangeZoom,true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

