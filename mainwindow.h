#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "samplinggraphicsview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);

public slots:
    void restore();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    SamplingGraphicsView *view;
};

#endif // MAINWINDOW_H
