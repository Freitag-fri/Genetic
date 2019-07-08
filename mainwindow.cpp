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
    object[5] = &colorLabel5;
    object[6] = &colorLabel6;
    object[7] = &colorLabel7;
    object[8] = &colorLabel8;
    object[9] = &colorLabel9;
    object[10] = &colorLabel10;
    object[11] = &colorLabel11;
    object[12] = &colorLabel12;
    object[13] = &colorLabel13;
    object[14] = &colorLabel14;
    object[15] = &colorLabel15;
    object[16] = &colorLabel16;
    object[17] = &colorLabel17;
    object[18] = &colorLabel18;
    object[19] = &colorLabel19;
    object[20] = &colorLabel20;
    object[21] = &colorLabel21;
    object[22] = &colorLabel22;
    object[23] = &colorLabel23;
    object[24] = &colorLabel24;

    objWidget[0] = ui->label;
    objWidget[1] = ui->label_2;
    objWidget[2] = ui->label_3;
    objWidget[3] = ui->label_4;
    objWidget[4] = ui->label_5;
    objWidget[5] = ui->label_6;
    objWidget[6] = ui->label_7;
    objWidget[7] = ui->label_8;
    objWidget[8] = ui->label_9;
    objWidget[9] = ui->label_10;
    objWidget[10] = ui->label_11;
    objWidget[11] = ui->label_12;
    objWidget[12] = ui->label_13;
    objWidget[13] = ui->label_14;
    objWidget[14] = ui->label_15;
    objWidget[15] = ui->label_16;
    objWidget[16] = ui->label_17;
    objWidget[17] = ui->label_18;
    objWidget[18] = ui->label_19;
    objWidget[19] = ui->label_20;
    objWidget[20] = ui->label_21;
    objWidget[21] = ui->label_22;
    objWidget[22] = ui->label_23;
    objWidget[23] = ui->label_24;
    objWidget[24] = ui->label_25;


    for (int i = 0; i < 25; i++)                             //закрашиваем окна случайным цветом
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

    for (int i = 0; i < 25; i++)
    {
        object[i]->ResetColor();

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

    for (int c = 0; c < 25; c++)
    {
        object[c]->operator=(*object[mainObject]);

        if(rand()%100 < 50)
        {
            int color = rand()%3;

            if (color == 0)
            {
                object[c]->SetColorR(rand() %7 + (-3));
            }
            else if (color == 1)
            {
                object[c]->SetColorG(rand() %7 + (-3));
            }
            else
                object[c]->SetColorB(rand() %7 + (-3));
        }
    }

    for (int c = 0; c < 25; c++)
    {
        Colour.setRgb(object[c]->GetColorR(), object[c]->GetColorG(), object[c]->GetColorB());
        darkPalette2.setColor(QPalette::Window, Colour);
        objWidget[c]->setPalette(darkPalette2);
    }

    //    ui->label->setText( "R " + QString::number(object[0]->GetColorR()) + " G "
    //            +QString::number(object[0]->GetColorG()) +" B "
    //            +QString::number(object[0]->GetColorB()));

    //    ui->label_2->setText( "R " + QString::number(object[1]->GetColorR()) + " G "
    //            +QString::number(object[1]->GetColorG()) +" B "
    //            +QString::number(object[1]->GetColorB()));

    //    ui->label_3->setText( "R " + QString::number(object[2]->GetColorR()) + " G "
    //            +QString::number(object[2]->GetColorG()) +" B "
    //            +QString::number(object[2]->GetColorB()));

    //    ui->label_4->setText( "R " + QString::number(object[3]->GetColorR()) + " G "
    //            +QString::number(object[3]->GetColorG()) +" B "
    //            +QString::number(object[3]->GetColorB()));

    //    ui->label_5->setText( "R " + QString::number(object[4]->GetColorR()) + " G "
    //            +QString::number(object[4]->GetColorG()) +" B "
    //            +QString::number(object[4]->GetColorB()));


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
