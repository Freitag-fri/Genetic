#include "genetic.h"

Genetic::Genetic()
{
    colorR = 0;
    colorG = 0;
    colorB = 0;
    deltaColor = 0;
}

void Genetic::ResetColor()
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
    colorR += value;
    if (colorR > 255)
        colorR = 255;
    else if(colorR < 0)
        colorR = 0;
}

void Genetic::SetColorG(int value)
{
    colorG += value;
    if (colorG > 255)
        colorG = 255;
    else if(colorG < 0)
        colorG = 0;
}

void Genetic::SetColorB(int value)
{
    colorB += value;
    if (colorB > 255)
        colorB = 255;
    else if(colorB < 0)
        colorB = 0;
}

void Genetic::SetDeltaColor(int value)
{
    deltaColor += value;
}

void Genetic::ChangeColorR(int value)
{
    colorR = value;
}

void Genetic::ChangeColorG(int value)
{
    colorG = value;
}

void Genetic::ChangeColorB(int value)
{
    colorB = value;
}

