#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

class liczba
{
private:
    int wartosc;

public:
    static int ile;
    liczba()
    {
        wartosc = rand() % 1000;
        ile++;
    }
    int getwartosz() { return wartosc; }
    ~liczba()
    {
        ile--;
    }
};
int liczba::ile = 0;

liczba *tab[100];
int main()
{
    srand(time(NULL));

    for (int i = 0; i < 30; i++)
        tab[i] = new liczba;
    cout << liczba::ile << endl;
    for (int i = 0; i < 30; i++)
        delete tab[i];
    cout << liczba::ile << endl;
    return 0;
}