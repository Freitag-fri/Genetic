#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "genetic.h"

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

    Genetic colorLabel0;
    Genetic colorLabel1;
    Genetic colorLabel2;
    Genetic colorLabel3;
    Genetic colorLabel4;

    Genetic *object[5];
    QWidget *objWidget[5];

    QPalette darkPalette2;
    QColor Colour;

    void ColorWindow();
};

#endif // MAINWINDOW_H
