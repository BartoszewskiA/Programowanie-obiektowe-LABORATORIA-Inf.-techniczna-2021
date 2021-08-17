#include <iostream>
using namespace std;
class Tablica
{
    int ile, *Tab;
public:
    Tablica(int eN = 1) : ile(eN)
    {
        Tab = new int[ile];
    }
    int &operator[](unsigned int index) // definicja operatora []
    {
        return Tab[index];
    }
    ~Tablica() { delete[] Tab; }
};