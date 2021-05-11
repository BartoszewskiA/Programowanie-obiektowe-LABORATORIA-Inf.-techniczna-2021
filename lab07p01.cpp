#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;

class dana
{
private:
    int Id;
    int x;
    void zapis(int r); //r=0 - utworzenie
                       //r=1 - usuniecie

public:
    static int ile;
    static time_t start_prog;

    dana(int dana = 0) : x(dana)
    {
        Id = ++ile;
        zapis(0);
    }
    ~dana()
    {
        zapis(1);
    }
    void setDana(int dana) { x = dana; }
    int getId() { return Id; }
    int getDana() { return x; }
};

int dana::ile = 0;
time_t dana::start_prog;

void dana::zapis(int r)
{
    fstream plik;
    plik.open("lab07p01.log", ios::app);
    time_t czas_u = time(NULL);
    tm *czas_l = localtime(&czas_u);
    switch (r)
    {
    case 0:
        plik << "Obiekt " << Id << " Zawartośc: " << x
             << " Utworzony: " << czas_l->tm_hour << ":" << czas_l->tm_min << ":" << czas_l->tm_sec 
             <<" Po "<<czas_u - start_prog<<" s."<< endl;
        break;
    case 1:
        plik << "Obiekt " << Id << " Zawartośc: " << x
             << " Usuniety: " << czas_l->tm_hour << ":" << czas_l->tm_min << ":" << czas_l->tm_sec
             <<" Po "<<czas_u - start_prog<<" s."<< endl;
        break;
    }
    plik.close();
}

int main()
{
    dana::start_prog = time(NULL);
    cout << "Press any key";
    getch();
    dana a1(100);
    a1.setDana(200);
    cout << endl
         << "Press any key";
    getch();
    dana a2(200);
    cout << endl
         << "Press any key";
    getch();
    return 0;
}