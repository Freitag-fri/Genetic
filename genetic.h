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

    void SetColorR(int value);
    void SetColorG(int value);
    void SetColorB(int value);
    void SetDeltaColor(int value);

    void ChangeColorR(int value);
    void ChangeColorG(int value);
    void ChangeColorB(int value);

    void ResetColor();

    //    Genetic(const Genetic &other)
    //    {
    //        this->colorR = other.colorR;
    //        this->colorG = other.colorG;
    //        this->colorB = other.colorB;
    //        this->deltaColor = other.deltaColor;
    //    }

    Genetic& operator =(Genetic& obj) // Оператор присваивания
    {
        colorR = obj.colorR;
        colorG = obj.colorG;
        colorB = obj.colorB;
        deltaColor = obj.deltaColor;
        return *this;
    }

private:
    int colorR;
    int colorG;
    int colorB;
    int deltaColor;

};


#endif // GEMETIC_H
