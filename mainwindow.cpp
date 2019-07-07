#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "genetic.h"
#include <time.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    srand(time(0));             //сбрасывает рандомные числа
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

    for (int i = 0; i < 5; i++)                             //закрашиваем окна случайным цветом
    {
        Colour.setRgb(rand()%256, rand()%256, rand()%256);
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
    const int RWindow = ui->SliderRed->value();
    const int GWindow = ui->SliderGreen->value();
    const int BWindow = ui->SliderBlue->value();

    int minDeltaColor = 1000;
    int mainObject = 5;

    for (int i = 0; i < 5; i++)
    {
        object[i]->colorR = objWidget[i]->palette().window().color().red();
        object[i]->colorG = objWidget[i]->palette().window().color().green();
        object[i]->colorB = objWidget[i]->palette().window().color().blue();

        object[i]->deltaColor += RWindow - object[i]->colorR;
        object[i]->deltaColor += GWindow - object[i]->colorG;
        object[i]->deltaColor += BWindow - object[i]->colorB;

        object[i]->deltaColor = abs(object[i]->deltaColor);         //взятие модуля
        if (object[i]->deltaColor < minDeltaColor)
        {
            minDeltaColor = object[i]->deltaColor;
            mainObject = i;
        }
    }

    for (int c = 0; c < 5; c++)
    {
        object[c]->operator=(*object[mainObject]);

        if(/*rand()%100 < 100*/true)
        {
            int color = rand()%3;

            if (color == 0)
            {
                object[c]->colorR += rand() %9 + (-4);
            }
            else if (color == 1)
            {
                object[c]->colorG += rand() %9 + (-4);
            }
            else
                object[c]->colorB += rand() %9 + (-4);
        }


        Colour.setRgb(object[c]->colorR, object[c]->colorG, object[c]->colorB);
        darkPalette2.setColor(QPalette::Window, Colour);
        objWidget[c]->setPalette(darkPalette2);
    }

    for (int c = 0; c < 5; c++)
    {



        Colour.setRgb(object[c]->colorR, object[c]->colorG, object[c]->colorB);
        darkPalette2.setColor(QPalette::Window, Colour);
        objWidget[c]->setPalette(darkPalette2);
    }

    ui->label->setText( "R " + QString::number(object[0]->colorR) + " G "
            +QString::number(object[0]->colorG) +" B "
            +QString::number(object[0]->colorB));

    ui->label_2->setText( "R " + QString::number(object[1]->colorR) + " G "
            +QString::number(object[1]->colorG) +" B "
            +QString::number(object[1]->colorB));

    ui->label_3->setText( "R " + QString::number(object[2]->colorR) + " G "
            +QString::number(object[2]->colorG) +" B "
            +QString::number(object[2]->colorB));

    ui->label_4->setText( "R " + QString::number(object[3]->colorR) + " G "
            +QString::number(object[3]->colorG) +" B "
            +QString::number(object[3]->colorB));

    ui->label_5->setText( "R " + QString::number(object[4]->colorR) + " G "
            +QString::number(object[4]->colorG) +" B "
            +QString::number(object[4]->colorB));


}

void MainWindow::ColorWindow()
{
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
    ColorWindow();
}

void MainWindow::on_SliderGreen_sliderMoved(int position)
{
    ui->labelGreen->setText("Green "+QString::number(position));
    ColorWindow();
}

void MainWindow::on_SliderBlue_sliderMoved(int position)
{
    ui->labelBlue->setText("Blue "+QString::number(position));
    ColorWindow();
}
