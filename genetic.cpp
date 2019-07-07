#include "genetic.h"

Genetic::Genetic()
{
    colorR = 0;
    colorG = 0;
    colorB = 0;
    deltaColor = 0;
}

int Genetic::GetColorR()
{
    return colorR;
}

int Genetic::GetColorG()
{
    return colorG;
}

int Genetic::GetColorB()
{
    return colorB;
}

int Genetic::GetDeltaColor()
{
    return deltaColor;
}

void Genetic::SetColorR(int value)
{
    if (value == 666)
    {
       colorR = 0;
       return;
    }

    colorR += value;
    if (colorR > 255)
        colorR = 255;
    else if(colorR < 0)
        colorR = 0;
}

void Genetic::SetColorG(int value)
{
    if (value == 666)
    {
       colorG = 0;
       return;
    }

    colorG += value;
    if (colorG > 255)
        colorG = 255;
    else if(colorG < 0)
        colorG = 0;
}

void Genetic::SetColorB(int value)
{
    if (value == 666)
    {
       colorB = 0;
       return;
    }

    colorB += value;
    if (colorB > 255)
        colorB = 255;
    else if(colorB < 0)
        colorB = 0;
}

void Genetic::SetDeltaColor(int value)
{
    if (value == 666)
    {
       deltaColor = 0;
       return;
    }
    deltaColor += value;
}


