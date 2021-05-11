#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class rown_kwadratowe
{
private:
    int a;
    int b;
    int c;
    int delta;
    int liczba_rozwiazan;
    void licz_delta()
    {
        delta = b * b - 4 * a * c;
        if (delta > 0)
            liczba_rozwiazan = 2;
        else if (delta == 0)
            liczba_rozwiazan = 1;
        else
            liczba_rozwiazan = 0;
    }

public:
    // rown_kwadratowe(int a = 0, int b = 0, int c = 0)
    // {
    //     this->a = a;
    //     this->b = b;
    //     this->c = c;
    //     licz_delta();
    // }

    rown_kwadratowe(int A, int B, int C): a(A), b(B), c(c)
    {
        licz_delta();
    }

    void setA(int a)
    {
        this->a = a;
        licz_delta();
    }
    void setB(int b)
    {
        this->b = b;
        licz_delta();
    }
    void setC(int c)
    {
        this->c = c;
        licz_delta();
    }
    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }
    int getDelta() { return delta; }
    int getLiczbaRozwiazan() { return liczba_rozwiazan; }

    double getX1()
    {
        if (delta >= 0)
            return (-b - sqrt(delta)) / (2 * a);
        else
            return 0;
    }

    double getX2()
    {
        if (delta >= 0)
            return (-b + sqrt(delta)) / (2 * a);
        else
            return 0;
    }

    string getTextX1()
    {
        stringstream temp;
        if (delta >= 0)
            temp << (-b - sqrt(delta)) / (2 * a);
        else
            temp << "#brakRozwiazan";
        return temp.str();
    }

    string getTextX2()
    {
        stringstream temp;
        if (delta >= 0)
            temp << (-b + sqrt(delta)) / (2 * a);
        else
            temp << "#brakRozwiazan";
        return temp.str();
    }
};

int main()
{
    rown_kwadratowe r1;
    r1.setA(4);
    r1.setB(6);
    r1.setC(-5);
    cout << r1.getLiczbaRozwiazan() << endl;
    return 0;
}