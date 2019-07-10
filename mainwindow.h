#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "genetic.h"
#include <QtCharts>


using namespace std;

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_SliderRed_sliderMoved(int position);

    void on_SliderGreen_sliderMoved(int position);

    void on_SliderBlue_sliderMoved(int position);



private:

    Ui::MainWindow *ui;

    QChart *schedule;

    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;
    QLineSeries* series1 = new QLineSeries();


    Genetic colorLabel0;
    Genetic colorLabel1;
    Genetic colorLabel2;
    Genetic colorLabel3;
    Genetic colorLabel4;
    Genetic colorLabel5;
    Genetic colorLabel6;
    Genetic colorLabel7;
    Genetic colorLabel8;
    Genetic colorLabel9;
    Genetic colorLabel10;
    Genetic colorLabel11;
    Genetic colorLabel12;
    Genetic colorLabel13;
    Genetic colorLabel14;
    Genetic colorLabel15;
    Genetic colorLabel16;
    Genetic colorLabel17;
    Genetic colorLabel18;
    Genetic colorLabel19;
    Genetic colorLabel20;
    Genetic colorLabel21;
    Genetic colorLabel22;
    Genetic colorLabel23;
    Genetic colorLabel24;

    const static int allElements = 25;   //количество элементов

    Genetic *object[allElements];
    Genetic *objectBest[allElements/2];
    QWidget *objWidget[allElements];

    QPalette darkPalette2;
    QColor Colour;

    void ColorWindow();
    void OneParents();
    void Variant2();
    void Mutation(int index);
    void Children(int main, int other);

    void Schedule(int pos, int n);
};

#endif // MAINWINDOW_H
