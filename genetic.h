#ifndef GEMETIC_H
#define GEMETIC_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Genetic
{
public:
    Genetic();

    //Genetic(const Genetic &other);

    Genetic(const Genetic &other)
    {
        this->colorR = other.colorR;
        this->colorG = other.colorG;
        this->colorB = other.colorB;
        this->deltaColor = other.deltaColor;
    }

    Genetic& operator =(Genetic& obj) // Оператор присваивания
    {
        colorR = obj.colorR;
        colorG = obj.colorG;
        colorB = obj.colorB;
        deltaColor = obj.deltaColor;
        return *this;
    }

    //private:
    int colorR;
    int colorG;
    int colorB;
    int deltaColor;

};


#endif // GEMETIC_H
