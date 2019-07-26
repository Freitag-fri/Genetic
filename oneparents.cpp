#include "mainwindow.h"
#include "ui_mainwindow.h"

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
