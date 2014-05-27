#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = new SamplingGraphicsView(ui->widget);
    connect(view,SIGNAL(restore()),this,SLOT(restore()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QTime time;
    time.start();
    double width = this->size().width();
    int heigth = this->size().height();
    /*QPainter p(this);
    QPainterPath path;
    QPointF points[3]={QPointF(0,0),QPointF(100,100),QPointF(200,100)};
    p.fillPolygon(points,3);*/
}

void MainWindow::on_pushButton_clicked()
{
    view->addSamplingPoint(ui->spinBox->value(),ui->doubleSpinBox->value(),ui->doubleSpinBox_2->value());
    ui->spinBox->setValue(ui->spinBox->value()+1);
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<view->getSelectedPoints();
    view->setParent(NULL);
    view->showFullScreen();
}

void MainWindow::restore()
{
    view->setParent(ui->widget);
}
