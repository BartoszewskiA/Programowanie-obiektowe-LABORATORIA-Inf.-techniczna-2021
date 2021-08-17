#include <iostream>
#include <string>
using namespace std;

class RGB
{
protected:
    int R;
    int G;
    int B;

public:
    RGB(int r = 0, int g = 0, int b = 0) : R(r), G(g), B(b) {}
    int getR() { return R; }
    int getG() { return G; }
    int getB() { return B; }
};

class RGBA : public RGB
{
protected:
    int A;
    // bool czy_rozne;
    // bool czy_te_same;
    // bool wiekszy;
    // bool mniejszy;

public:
    static int nr;
    RGBA(int r = 0, int g = 0, int b = 0, int a = 0) : RGB(r, g, b), A(a)
    {
        nr++;
    }
    int getA() { return A; }
    // string getCzy_rozne() { return czy_rozne ? "prawda" : "falsz"; };
    // string getCzy_te_same() { return czy_te_same ? "prawda" : "falsz"; };
    // string getWiekszy() { return wiekszy ? "prawda" : "falsz"; };
    // string getMniejszy() { return mniejszy ? "prawda" : "falsz"; };
    void setR(int r) { this->R = r; }
    void setG(int g) { this->G = g; }
    void setB(int b) { this->B = b; }
    void setA(int a) { this->A = a; }

    friend RGBA operator+(RGBA ob1, RGBA ob2);
    friend RGBA operator-(RGBA ob1, RGBA ob2);
    friend bool operator!=(RGBA ob1, RGBA ob2);
    friend bool operator==(RGBA ob1, RGBA ob2);
    friend bool operator<(RGBA ob1, RGBA ob2);
    friend bool operator>(RGBA ob1, RGBA ob2);
    friend ostream &operator<<(ostream &str, RGBA ob1);
    friend istream &operator>>(istream &str, RGBA &ob1);
    ~RGBA() { nr--; }
};

ostream &operator<<(ostream &str, RGBA ob1)
{
    str << ob1.R << "," << ob1.G << "," << ob1.B << "," << ob1.A;
    return str;
}

istream &operator>>(istream &str, RGBA &ob1)
{
    string temp, strR, strG, strB, strA;
    str >> temp;
    int poz1, poz2, poz3;
    poz1 = temp.find(',');
    poz2 = temp.find(poz1+1,',');
    poz3 = temp.find(poz2+1,',');
    strR = temp.substr(0,poz1);
    strG = temp.substr(poz1+1, poz2-(poz1+1));
    strB = temp.substr(poz2+1,poz3-(poz2+1));
    strA = temp.substr(poz3+1,temp.length()-(poz3+1));
    ob1.R = atoi(strR.c_str());
    ob1.G = atoi(strG.c_str());
    ob1.B = atoi(strB.c_str());
    ob1.A = atoi(strA.c_str());

//  445,345,33,222
    return str;
}

RGBA operator+(RGBA ob1, RGBA ob2)
{
    RGBA temp;
    //r
    if (ob1.R + ob2.R > 255)
    {
        // temp.setR(255);
        temp.R = 255;
    }
    else
    {
        // temp.setR(ob1.R + ob2.R);
        temp.R = ob1.R + ob2.R;
    }
    //g
    if (ob1.G + ob2.G > 255)
    {
        temp.setG(255);
    }
    else
    {
        temp.setG(ob1.G + ob2.G);
    }
    //b
    if (ob1.B + ob2.B > 255)
    {
        temp.setB(255);
    }
    else
    {
        temp.setB(ob1.B + ob2.B);
    }
    //a
    if (ob1.A + ob2.A > 255)
    {
        temp.setA(255);
    }
    else
    {
        temp.setA(ob1.A + ob2.A);
    }
    return temp;
}

RGBA operator-(RGBA ob1, RGBA ob2)
{
    RGBA temp;
    //r
    if (ob1.R - ob2.R < 0)
    {
        temp.setR(0);
    }
    else
    {
        temp.setR(ob1.R - ob2.R);
    }
    //g
    if (ob1.G - ob2.G < 0)
    {
        temp.setG(0);
    }
    else
    {
        temp.setG(ob1.G - ob2.G);
    }
    //b
    if (ob1.B - ob2.B < 0)
    {
        temp.setB(0);
    }
    else
    {
        temp.setB(ob1.B - ob2.B);
    }
    //a
    if (ob1.A - ob2.A < 0)
    {
        temp.setA(0);
    }
    else
    {
        temp.setA(ob1.A - ob2.A);
    }
    return temp;
}

// bool operator!=(RGBA ob1, RGBA ob2)
// {
//     int prawda = 0;
//     bool czy_rozne;
//     RGBA temp;
//     //r
//     if (ob1.R != ob2.R)
//     {
//         prawda++;
//     }
//     //g
//     if (ob1.G != ob2.G)
//     {
//         prawda++;
//     }
//     //b
//     if (ob1.B != ob2.B)
//     {
//         prawda++;
//     }
//     //a
//     if (ob1.A != ob2.A)
//     {
//         prawda++;
//     }
//     prawda == 4 ? temp.czy_rozne = true : temp.czy_rozne = false;

//     return true;
// }

// RGBA operator==(RGBA ob1, RGBA ob2)
// {
//     int prawda = 0;
//     bool czy_te_same;
//     RGBA temp;
//     //r
//     if (ob1.R == ob2.R)
//     {
//         prawda++;
//     }
//     //g
//     if (ob1.G == ob2.G)
//     {
//         prawda++;
//     }
//     //b
//     if (ob1.B == ob2.B)
//     {
//         prawda++;
//     }
//     //a
//     if (ob1.A == ob2.A)
//     {
//         prawda++;
//     }
//     prawda == 4 ? temp.czy_te_same = true : temp.czy_te_same = false;

//     return temp;
// }

bool operator!=(RGBA ob1, RGBA ob2)
{
    if (ob1.R != ob2.R || ob1.G != ob2.G || ob1.B != ob2.B || ob1.A != ob2.A)
        return true;
    else
        return false;
}

bool operator==(RGBA ob1, RGBA ob2)
{
    if (ob1.R == ob2.R && ob1.G == ob2.G && ob1.B == ob2.B && ob1.A == ob2.A)
        return true;
    else
        return false;
}

bool operator<(RGBA ob1, RGBA ob2)
{

    if ((ob1.R + ob1.G + ob1.R) / 3.0 < (ob2.R + ob2.G + ob2.R) / 3.0)
        return true;
    else
        return false;
}

bool operator>(RGBA ob1, RGBA ob2)
{

    if ((ob1.R + ob1.G + ob1.R) / 3.0 > (ob2.R + ob2.G + ob2.R) / 3.0)
        return true;
    else
        return false;
}

int RGBA::nr = 0;

int main()
{
    RGBA obiekt1(1, 2, 3, 4);
    cin>>obiekt1;
    cout << obiekt1;
    // RGBA obiekt2(5, 5, 5, 5);
    // RGBA obiekt3;
    // obiekt3 = obiekt1 + obiekt2;
    // cout << "Plus: ";
    // cout << obiekt3.getR() << " " << obiekt3.getG() << " " << obiekt3.getB() << " " << obiekt3.getA() << endl;
    // cout << "Minus: ";
    // obiekt3 = obiekt2 - obiekt1;
    // cout << obiekt3.getR() << " " << obiekt3.getG() << " " << obiekt3.getB() << " " << obiekt3.getA() << endl;

    // if (obiekt1 == obiekt2)
    //     cout << "TAK";
    // else
    //     cout << "NIE";
    // cout << "Czy rozne: ";
    // obiekt3 = obiekt2 != obiekt1;
    // cout << obiekt3.getCzy_rozne() << endl;
    // cout << "Czy te same: ";
    // obiekt3 = obiekt2 == obiekt1;
    // cout << obiekt3.getCzy_te_same() << endl;
    // cout << "Mniejszy : ";
    // obiekt3 = obiekt2 < obiekt1;
    // cout << obiekt3.getWiekszy() << endl;
    // cout << "Wiekszy: ";
    // obiekt3 = obiekt2 > obiekt1;
    // cout << obiekt3.getMniejszy() << endl;
    return 0;
}
