
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// +, -
// +=, -=

class zespolona
{
private:
    double r; //część rzeczywista
    double u; //część urojona
public:
    zespolona(double R = 0, double U = 0) : r(R), u(U) {}
    friend ostream &operator<<(ostream &str, zespolona x);
    friend istream &operator>>(istream &str, zespolona & x);
};
ostream &operator<<(ostream &str, zespolona x)
{
    if (x.r == 0 && x.u == 0)
    {
        str << 0;
    }
    else
    {
        if (x.r != 0)
            str << x.r;
        if (x.r != 0 && x.u > 0)
            str << "+";
        if (x.u != 0)
            str << x.u << "i";
    }
    return str;
}

istream &operator>>(istream &str, zespolona & x)
{
    string temp, tempR, tempU;
    int poz;
    str>>temp;
    if (temp[temp.length()-1]!='i')
    {
        //liczba nie ma części urojonej
        x.r = atof(temp.c_str());
        x.u =0;
    }
    else 
    {
        for (int i= temp.length()-1; i>=0; i--)
            if (temp[i]=='+' || temp[i]=='-')
                {
                    poz=i;
                    break;
                }
        if (poz==0)  //liczba nie ma części rzeczywistej
            {
                temp = temp.substr(0, temp.length()-1);
                x.u = atof(temp.c_str());
                x.r =0;
            }
        else  //liczba posiad część rzeywistą i urojoną
        {
            tempR = temp.substr(0,poz);
            x.r= atof(tempR.c_str());
            tempU = temp.substr(poz, temp.length()-poz -1);
            x.u= atof(tempU.c_str());
        }
    }
    return str;
}

int main()
{
    zespolona a(10, 3), b, c(0, 5), d(-3, -5), e(3, 0);
    
    cin >> b;
    
    //cout << a << endl;
    cout << b << endl;
    //cout << c << endl;
    //cout << d << endl;
    //cout << e << endl;

    return 0;
}