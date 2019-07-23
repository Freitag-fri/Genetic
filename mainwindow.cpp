#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "genetic.h"
#include <time.h>
#include <windows.h>

extern int MaxDelta = 0;

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("One parents");     //0
    ui->comboBox->addItem("Bubble sort");    //1
    ui->comboBox->addItem("Best parents");      //2

    schedule = new QChart;              //задаем параметры графика
    ui->widget->setChart(schedule);
    schedule->addSeries(series1);
    series1->setName("Min");
    series2->setName("Average");
    schedule->addSeries(series2);
    schedule->setAxisX(axisX,series1);
    schedule->setAxisY(axisY,series1);
    schedule->setAxisX(axisX,series2);
    schedule->setAxisY(axisY,series2);
    axisX->setRange(1, 10);
    axisY->setRange(1, 10);
    axisY->setLabelFormat("%d");
    axisX->setLabelFormat("%d");

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

    SetColor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MaxDelta = 0;
    series1->clear();       //очищаем график
    series2->clear();

    if (ui->comboBox->currentIndex() == 0)
        OneParents();
    else if (ui->comboBox->currentIndex() == 1)
        Variant2();
    else if ((ui->comboBox->currentIndex() == 2))
        BestPerents();

}

void MainWindow::Schedule(int pos, int n, int deltaAverage)
{
    if (deltaAverage > MaxDelta)
        MaxDelta = deltaAverage;
    series1->append(n,pos);
    series2->append(n,deltaAverage);
    axisX->setRange(1, n);
    axisY->setRange(1, MaxDelta + 5);
}

void MainWindow::Schedule(int pos, int n)
{
    if (pos > MaxDelta)
        MaxDelta = pos;
    series1->append(n,pos);
    axisX->setRange(1, n);
    axisY->setRange(1, MaxDelta + 5);
}

void MainWindow::BestPerents()
{
    Genetic tempObj[10];
    const int RWindow = ui->SliderRed->value();
    const int GWindow = ui->SliderGreen->value();
    const int BWindow = ui->SliderBlue->value();
    Genetic *temp;                                  //позырчатая сортировка
    int element = 0;                                //рандомный родитель
    int R = 0;                                      //переменные для закрашивания
    int G = 0;
    int B = 0;
    int bestDeltaColor = 1000;                      //лучший цвет
    int pass = 0;                                   //количество проходов

    for (int i = 0; i < allElements; i++)
    {
        object[i]->ResetColor();
        object[i]->SetColorR(objWidget[i]->palette().window().color().red());
        object[i]->SetColorG(objWidget[i]->palette().window().color().green());
        object[i]->SetColorB(objWidget[i]->palette().window().color().blue());
    }

    while (bestDeltaColor > 2)
    {
        pass++;
        Sleep(50);
        QApplication::processEvents();
        for (int i = 0; i < allElements; i++)
        {   object[i]->ChangeDeltaColor(0);

            object[i]->SetDeltaColor(abs(RWindow - object[i]->GetColorR()));
            object[i]->SetDeltaColor(abs(GWindow - object[i]->GetColorG()));
            object[i]->SetDeltaColor(abs(BWindow - object[i]->GetColorB()));
        }

        for(int i = 0; i < allElements-1; i++)          //пузырчатая сортировка
        {
            for(int c = 0; c < allElements-(1+i); c++)
            {
                if (object[c]->GetDeltaColor() > object[c+1]->GetDeltaColor())
                {
                    temp = object[c];
                    object[c] = object[c+1];
                    object[c+1] = temp;
                }
            }
        }

        for (int i = 0; i < 10; i++)        //записываем лучшие 10 цветов в массив
        {
            tempObj[i] = *object[i];
        }
        bestDeltaColor = tempObj[0].GetDeltaColor();;

        for (int i = 0; i < 2; i++)
        {
            *object[i] = tempObj[0];
            Mutation(i);
        }

        for (int i = 2; i < 3; i++)
        {
            *object[i] = tempObj[1];
            Mutation(i);
        }

        for (int i = 3; i < 25; i++)
        {
            element = rand()%10;
            *object[i] = tempObj[element];
            Mutation(i);
        }

        for (int c = 0; c < allElements; c++)
        {
            Colour.setRgb(object[c]->GetColorR(), object[c]->GetColorG(), object[c]->GetColorB());
            darkPalette2.setColor(QPalette::Window, Colour);
            objWidget[c]->setPalette(darkPalette2);
        }
        Schedule(bestDeltaColor,  pass);         //вывод данных на график
    }
}

void MainWindow::Variant2()                     //турнирная селекция (из 2-х вариантов выбирается более приспособленный)
{
    const int RWindow = ui->SliderRed->value();
    const int GWindow = ui->SliderGreen->value();
    const int BWindow = ui->SliderBlue->value();
    int n = 0;
    int minDeltaColor = 1000;
    int minDeltaColor2 = 1000;
    int minDeltaColor3 = 100;
    while (minDeltaColor3 > 50)
    {
        minDeltaColor3 = 0;
        minDeltaColor2 = 1000;
        n++;
        Sleep(50);
        QApplication::processEvents();
        for (int i = 0; i < allElements/2; i++)
        {
            minDeltaColor = 1000;

            object[i*2]->ResetColor();

            object[i*2]->SetColorR(objWidget[i*2]->palette().window().color().red());
            object[i*2]->SetColorG(objWidget[i*2]->palette().window().color().green());
            object[i*2]->SetColorB(objWidget[i*2]->palette().window().color().blue());

            object[i*2]->SetDeltaColor(abs(RWindow - object[i*2]->GetColorR()));
            object[i*2]->SetDeltaColor(abs(GWindow - object[i*2]->GetColorG()));
            object[i*2]->SetDeltaColor(abs(BWindow - object[i*2]->GetColorB()));


            object[i*2+1]->ResetColor();

            object[i*2+1]->SetColorR(objWidget[i*2+1]->palette().window().color().red());
            object[i*2+1]->SetColorG(objWidget[i*2+1]->palette().window().color().green());
            object[i*2+1]->SetColorB(objWidget[i*2+1]->palette().window().color().blue());

            object[i*2+1]->SetDeltaColor(abs(RWindow - object[i*2+1]->GetColorR()));
            object[i*2+1]->SetDeltaColor(abs(GWindow - object[i*2+1]->GetColorG()));
            object[i*2+1]->SetDeltaColor(abs(BWindow - object[i*2+1]->GetColorB()));

            if (object[i*2+1]->GetDeltaColor() < object[i*2]->GetDeltaColor())
            {
                if(object[i*2+1]->GetDeltaColor()<minDeltaColor)
                    minDeltaColor = object[i*2+1]->GetDeltaColor();
                Children(i*2+1, i*2);

            }
            else
            {
                if(object[i*2]->GetDeltaColor()<minDeltaColor)
                    minDeltaColor = object[i*2]->GetDeltaColor();
                Children(i*2, i*2+1);
            }

            Mutation(i*2);
            Mutation(i*2+1);

            Colour.setRgb(object[i*2]->GetColorR(), object[i*2]->GetColorG(), object[i*2]->GetColorB());
            darkPalette2.setColor(QPalette::Window, Colour);
            objWidget[i*2]->setPalette(darkPalette2);

            Colour.setRgb(object[i*2+1]->GetColorR(), object[i*2+1]->GetColorG(), object[i*2+1]->GetColorB());
            darkPalette2.setColor(QPalette::Window, Colour);
            objWidget[i*2+1]->setPalette(darkPalette2);


            if(minDeltaColor < minDeltaColor2)
                minDeltaColor2 = minDeltaColor;
            minDeltaColor3 += minDeltaColor;
        }

        Schedule(minDeltaColor2,  n, (minDeltaColor3*2)/allElements);
        for( int i = 0; i < allElements-1; i++)
        {
            QWidget *a = objWidget[i];
            int pos = (i + allElements-1) % allElements;
            objWidget[i] = objWidget[pos];
            objWidget[pos] = a;
        }
    }
}

void MainWindow::Children(int main, int other)
{
    int n = rand()%3;
    if (n == 0)
    {
        object[main]->ChangeColorR(object[other]->GetColorR());
        object[other]->ChangeColorG(object[main]->GetColorG());
        object[other]->ChangeColorB(object[main]->GetColorB());
    }
    else if (n == 1)
    {
        object[main]->ChangeColorG(object[other]->GetColorG());
        object[other]->ChangeColorR(object[main]->GetColorR());
        object[other]->ChangeColorB(object[main]->GetColorB());
    }
    else if (n == 2)
    {
        object[main]->ChangeColorB(object[other]->GetColorB());
        object[other]->ChangeColorR(object[main]->GetColorR());
        object[other]->ChangeColorG(object[main]->GetColorG());
    }
}

void MainWindow::OneParents()
{

    int n = 0;
    int minDeltaColor = 1000;
    int mainObject = 26;

    const int RWindow = ui->SliderRed->value();
    const int GWindow = ui->SliderGreen->value();
    const int BWindow = ui->SliderBlue->value();

    for (int i = 0; i < allElements; i++)
    {
        object[i]->ResetColor();

        object[i]->SetColorR(objWidget[i]->palette().window().color().red());
        object[i]->SetColorG(objWidget[i]->palette().window().color().green());
        object[i]->SetColorB(objWidget[i]->palette().window().color().blue());
    }

    while(minDeltaColor > 2)
    {
        n++;
        Sleep(50);
        QApplication::processEvents();

        minDeltaColor = 1000;

        for (int i = 0; i < allElements; i++)
        {
            object[i]->ChangeDeltaColor(0);
            object[i]->SetDeltaColor(abs(RWindow - object[i]->GetColorR()));
            object[i]->SetDeltaColor(abs(GWindow - object[i]->GetColorG()));
            object[i]->SetDeltaColor(abs(BWindow - object[i]->GetColorB()));

            if (object[i]->GetDeltaColor() < minDeltaColor)
            {
                minDeltaColor = object[i]->GetDeltaColor();
                mainObject = i;
            }
        }

        for (int c = 0; c < allElements; c++)
        {
            object[c]->operator=(*object[mainObject]);
            Mutation(c);
        }

        for (int c = 0; c < allElements; c++)
        {
            Colour.setRgb(object[c]->GetColorR(), object[c]->GetColorG(), object[c]->GetColorB());
            darkPalette2.setColor(QPalette::Window, Colour);
            objWidget[c]->setPalette(darkPalette2);
        }
        Schedule(minDeltaColor,  n);                        //вывод графика
    }
}

void MainWindow::Mutation(int index)
{
    if(rand()%100 < 20)
    {
        int color = rand()%3;

        if (color == 0)
        {
            object[index]->SetColorR(rand() %11 + (-5));
        }
        else if (color == 1)
        {
            object[index]->SetColorG(rand() %11 + (-5));
        }
        else
            object[index]->SetColorB(rand() %11 + (-5));
    }
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

void MainWindow::SetColor()
{
    for (int i = 0; i < allElements; i++)            //закрашиваем окна случайным цветом
    {
        Colour.setRgb(rand()%256, rand()%256, rand()%256);
        darkPalette2.setColor(QPalette::Window, Colour);
        objWidget[i]->setPalette(darkPalette2);
    }

    ui->SliderRed->setValue(rand()%256);
    ui->SliderGreen->setValue(rand()%256);
    ui->SliderBlue->setValue(rand()%256);
    ui->labelRed->setText("Red "+QString::number(ui->SliderRed->value()));
    ui->labelGreen->setText("Green "+QString::number(ui->SliderGreen->value()));
    ui->labelBlue->setText("Blue "+QString::number(ui->SliderBlue->value()));

    Colour.setRgb(ui->SliderRed->value(), ui->SliderGreen->value(), ui->SliderBlue->value());
    darkPalette2.setColor(QPalette::Window, Colour);
    MainWindow::setPalette(darkPalette2);
}

void MainWindow::on_pushButton_2_clicked()
{
    for (int i = 0; i < allElements; i++)            //закрашиваем окна случайным цветом
    {
        Colour.setRgb(rand()%256, rand()%256, rand()%256);
        darkPalette2.setColor(QPalette::Window, Colour);
        objWidget[i]->setPalette(darkPalette2);
    }
}
