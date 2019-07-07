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
        object[i]->SetDeltaColor(666);
        object[i]->SetColorR(666);
        object[i]->SetColorG(666);
        object[i]->SetColorB(666);

        object[i]->SetColorR(objWidget[i]->palette().window().color().red());
        object[i]->SetColorG(objWidget[i]->palette().window().color().green());
        object[i]->SetColorB(objWidget[i]->palette().window().color().blue());

        object[i]->SetDeltaColor(abs(RWindow - object[i]->GetColorR()));
        object[i]->SetDeltaColor(abs(GWindow - object[i]->GetColorG()));
        object[i]->SetDeltaColor(abs(BWindow - object[i]->GetColorB()));

        if (object[i]->GetDeltaColor() < minDeltaColor)
        {
            minDeltaColor = object[i]->GetDeltaColor();
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
                object[c]->SetColorR(rand() %9 + (-4));
            }
            else if (color == 1)
            {
                object[c]->SetColorG(rand() %9 + (-4));
            }
            else
                object[c]->SetColorB(rand() %9 + (-4));
        }


//        Colour.setRgb(object[c]->GetColorR(), object[c]->GetColorG(), object[c]->GetColorB());
//        darkPalette2.setColor(QPalette::Window, Colour);
//        objWidget[c]->setPalette(darkPalette2);
    }

    for (int c = 0; c < 5; c++)
    {



        Colour.setRgb(object[c]->GetColorR(), object[c]->GetColorG(), object[c]->GetColorB());
        darkPalette2.setColor(QPalette::Window, Colour);
        objWidget[c]->setPalette(darkPalette2);
    }

    ui->label->setText( "R " + QString::number(object[0]->GetColorR()) + " G "
            +QString::number(object[0]->GetColorG()) +" B "
            +QString::number(object[0]->GetColorB()));

    ui->label_2->setText( "R " + QString::number(object[0]->GetColorR()) + " G "
            +QString::number(object[0]->GetColorG()) +" B "
            +QString::number(object[0]->GetColorB()));

    ui->label_3->setText( "R " + QString::number(object[0]->GetColorR()) + " G "
            +QString::number(object[0]->GetColorG()) +" B "
            +QString::number(object[0]->GetColorB()));

    ui->label_4->setText( "R " + QString::number(object[0]->GetColorR()) + " G "
            +QString::number(object[0]->GetColorG()) +" B "
            +QString::number(object[0]->GetColorB()));

    ui->label_5->setText( "R " + QString::number(object[0]->GetColorR()) + " G "
            +QString::number(object[0]->GetColorG()) +" B "
            +QString::number(object[0]->GetColorB()));


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
