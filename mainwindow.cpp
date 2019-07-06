#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "genetic.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    object[0] = &colorLabel0;
    object[1] = &colorLabel1;
    object[2] = &colorLabel2;
    object[3] = &colorLabel3;
    object[4] = &colorLabel4;

    objWidget[0] = ui->label;
    objWidget[1] = ui->label_2;
    objWidget[2] = ui->label_3;
    objWidget[3] = ui->label_4;
    objWidget[4] = ui->label_5;

//    Colour.setRgb(255, 255, 255);
//    darkPalette2.setColor(QPalette::Window, Colour);
//    MainWindow::setPalette(darkPalette2);
    for (int i = 0; i < 5; i++)                             //закрашиваем окна случайным цветом
    {
        Colour.setRgb(rand()%255, rand()%255, rand()%255);
        darkPalette2.setColor(QPalette::Window, Colour);
        objWidget[i]->setPalette(darkPalette2);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < 5; i++)
    {
        object[i]->colorR = objWidget[i]->palette().window().color().red();
        object[i]->colorG = objWidget[i]->palette().window().color().green();
        object[i]->colorB = objWidget[i]->palette().window().color().blue();

        Colour.setRgb(rand()%254, rand()%254, rand()%254);
        darkPalette2.setColor(QPalette::Window, Colour);
        objWidget[i]->setPalette(darkPalette2);

    }
    int R = ui->SliderRed->value();
    int G = ui->SliderGreen->value();
    int B = ui->SliderBlue->value();

    Colour.setRgb(R, G, B);
    darkPalette2.setColor(QPalette::Window, Colour);
    MainWindow::setPalette(darkPalette2);
}




void MainWindow::on_SliderRed_sliderMoved(int position)
{
   ui->labelRed->setText("Red "+QString::number(position));
}

void MainWindow::on_SliderGreen_sliderMoved(int position)
{
    ui->labelGreen->setText("Green "+QString::number(position));
}

void MainWindow::on_SliderBlue_sliderMoved(int position)
{
    ui->labelBlue->setText("Blue "+QString::number(position));
}
