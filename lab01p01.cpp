#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

struct punkt
{
    int x;
    int y;
};

punkt *punkty[100];

void losuj(int a, int b);
void wypisz();
double odleglosc(punkt *p);
int usun(double granica);
void usun_tablice();

int main()
{
    // srand(time(NULL));
    losuj(-200, 50);
    wypisz();
    cout << endl<<endl
         << "usunieto: " << usun(50) 
         << endl<<endl;
    wypisz();
    usun_tablice();
    return 0;
}
void losuj(int a, int b)
{
    for (int i = 0; i < 100; i++)
    {
        punkty[i] = new punkt;
        punkty[i]->x = rand() % (b - a) + a;
        punkty[i]->y = rand() % (b - a) + a;
    }
}
void wypisz()
{
    for (int i = 0; i < 100; i++)
    {
        if (punkty[i] != NULL)
        {
            cout << "(" << punkty[i]->x
                 << ";" << punkty[i]->y
                 << ")\t\t";
            if (i != 0 && i % 5 == 0)
                cout << endl;
        }
    }
}

double odleglosc(punkt *p)
{
    return sqrt(p->x * p->x + p->y * p->y);
}

int usun(double granica)
{
    int ile = 0;
    for (int i = 0; i < 100; i++)
    {
        if (punkty[i] != NULL)
        {

            if (odleglosc(punkty[i]) > granica)
            {
                delete punkty[i];
                punkty[i] = NULL;
                ile++;
            }
        }
    }
    return ile;
}

void usun_tablice()
{
    for (int i = 0; i < 100; i++)
    {
        delete punkty[i];
    }
}
