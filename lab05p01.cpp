#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

class postac
{
private:
    string imie;
    int zycie;
    int atak;
    int obrona;
    int zrecznosc;
    int pula_punktow = 10;

public:
    postac(string kto, int at, int obr, int zr) : imie(kto), atak(at), obrona(obr), zrecznosc(zr)
    {
        // if (atak > 20)
        //     atak = 20;
        // if (atak < 5)
        //     atak = 5;
        // if (obrona > 10)
        //     obrona = 10;
        // if (obrona < 0)
        //     obrona = 0;
        // if (zrecznosc > 10)
        //     zrecznosc = 10;
        // if (zrecznosc < 0)
        //     zrecznosc = 0;
        zycie = 200;
    }
    void setImie(string imie) { this->imie = imie; }
    void setZycie(int zycie) { this->zycie = zycie; }
    void setAtake(int atak) { this->atak = atak; }
    void setObrona(int obrona) { this->obrona = obrona; }
    string getImie() { return imie; }
    int getZycie() { return zycie; }
    int getAtak() { return atak; }
    int getObrona() { return obrona; }
    int getZrecznosc() { return zrecznosc; }
    void przedstaw_sie()
    {
        cout << endl;
        cout << "Postac " << imie << "(" << zycie << ";" << atak << ":" << obrona <<";"<<zrecznosc ")";
    }

    int damage()
    {
        int x = atak + (rand() % 7 - 3);
        if (x <= 0)
            x = 0;
        return x;
    }

    int redukcja_obrazen()
    {
        return rand()%(obrona+1);
    }
    ~postac()
    {

        przedstaw_sie();
        cout << " schodzi z ringu" << endl;
    }
};

int ring(postac &z1, postac &z2);

int main()
{
    srand(time(NULL));
    postac gracz1("Conan", 4, 4, 2), gracz2("Chuck", 3, 5, 2);
    cout << ring(gracz1, gracz2);
    cout << "koniec walki";
    return 0;
}

int ring(postac &z1, postac &z2)
{
    int rundy = 0;

    if (z1.getZrecznosc() >= z2.getZrecznosc())
    {
        cout << "Walke rozpoczyna " << z1.getImie() << endl;
        while (z1.getZycie() > 0 && z2.getZycie() > 0)
        {
            z2.setZycie(z2.getZycie() - (z1.damage() - z2.redukcja_obrazen()));
            if (z2.getZycie()<=0) break;
            z1.setZycie(z1.getZycie() - (z2.damage() - z1.redukcja_obrazen()));
            rundy++;
        }
    }
    else
    {
        cout << "Walke rozpoczyna " << z2.getImie() << endl;
        while (z1.getZycie() > 0 && z2.getZycie() > 0)
        {
            z1.setZycie(z1.getZycie() - (z2.damage() - z1.redukcja_obrazen()));
            if (z1.getZycie()<=0) break;
            z2.setZycie(z2.getZycie() - (z1.damage() - z2.redukcja_obrazen()));
            rundy++;
        }
    }
    return rundy;
}