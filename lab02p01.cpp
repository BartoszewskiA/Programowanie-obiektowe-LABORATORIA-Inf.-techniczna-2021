#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

class punkt
{
private:
    int x;
    int y;
    int kolor;
    // 0 - czarny;
    // 1 - czerwony;
    // 2 - zielony;
    // 3 - niebieski;
    // 4 - bialy;

public:
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    void setKolor(string k);
    int getX() { return x; }
    int getY() { return y; }
    string getKolor();
    void setLosowa();
    double getR();
} tab[100];

void punkt::setKolor(string k)
{
    if (k == "czarny")
        kolor = 0;
    else if (k == "czerwony")
        kolor = 1;
    else if (k == "zielony")
        kolor = 2;
    else if (k == "niebieski")
        kolor = 3;
    else if (k == "bialy")
        kolor = 4;
    else
        kolor = -1;
}

string punkt::getKolor()
{
    switch (kolor)
    {
        case 0: return "czarny"; 
        case 1: return "czerwony";
        case 2: return "zielony";
        case 3: return "niebieski";
        case 4: return "bialy";
    }
    return "brak koloru";
}

void punkt::setLosowa()
{
    x = rand() % 201 - 100;
    y = rand() % 201 - 100;
    //setKolor("czarny");
    kolor = rand()%5;
}

double punkt::getR()
{
    return sqrt(x * x + y * y);
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
        {
            tab[i].setLosowa();
            tab[i].setKolor("czarny");
        }
    for (int i = 0; i < 100; i++)
    {
        if (tab[i].getR() <= 50)
            cout << "(" << tab[i].getX() << ";" << tab[i].getY() << ")-"<<tab[i].getKolor()<<"  ";
    }

    return 0;
}