#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

class postac
{
private:
    string imie;
    //string imiona[6] = {"Adam","Jan","Anna","Olga","Zofia","Stefan"};
    //losujemy imie bez owtorzrn, gdy imiona w tablicy sie skoncza nadajemy imie "NN"
public:
    static string imiona[6];
    static int limit;
    postac(string im) : imie(im) {}

    postac()
    {
        int los;
        if (limit > 0)
        {
            while (1)
            {
                los = rand() % 6;
                if (imiona[los] != "")
                {
                    imie = imiona[los];
                    imiona[los] = "";
                    limit--;
                    break;
                }
            }
        } else imie= "NN";
    }

    string getImie() { return imie; }
};

string postac::imiona[] = {"Adam", "Jan", "Anna", "Olga", "Zofia", "Stefan"};
int postac::limit = 6;

int main()
{
    srand(time(NULL));
    postac zespol[10];
    for (int i = 0; i < 10; i++)
        cout << zespol[i].getImie() << " ";
    return 0;
}