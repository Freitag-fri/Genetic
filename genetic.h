#ifndef GEMETIC_H
#define GEMETIC_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Genetic
{
public:
    Genetic();
    int GetColorR();
    int GetColorG();
    int GetColorB();
    int GetDeltaColor();
    int GetPosObj();

    void SetColorR(int value);
    void SetColorG(int value);
    void SetColorB(int value);
    void SetDeltaColor(int value);
    void SetPosObj(int value);

    void ChangeColorR(int value);
    void ChangeColorG(int value);
    void ChangeColorB(int value);

    void ResetColor();



    Genetic& operator =(Genetic& obj) // Оператор присваивания
    {
        colorR = obj.colorR;
        colorG = obj.colorG;
        colorB = obj.colorB;
        deltaColor = obj.deltaColor;
        posObj = obj.posObj;
        return *this;
    }

private:
    int colorR;
    int colorG;
    int colorB;
    int posObj;
    int deltaColor;

};


#endif // GEMETIC_H
