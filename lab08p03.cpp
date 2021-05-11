#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

struct RGB
{
    int R;
    int G;
    int B;
};

class punkt
{
protected:
    int x;
    int y;

public:
    int getX() { return x; }
    int getY() { return y; }
    double getR()
    {
        return sqrt(x * x + y * y);
    }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    string toString()
    {
        stringstream temp;
        temp << "(" << x << ";" << y << ")";
        return temp.str();
    }
};

class pixel : public punkt
{
protected:
    RGB kolor;

public:
    void setColor(int r, int g, int b)
    {
        kolor.R = r;
        kolor.G = g;
        kolor.B = b;
    }
    RGB getColor() { return kolor; }

    string toString()
    {
        stringstream temp;
        temp << punkt::toString() << " R=" << kolor.R << " G=" << kolor.G << " B=" << kolor.B;
        return temp.str();
    }
};

class punkt3D : public punkt
{
protected:
    int z;

public:
    void setZ(int Z) { z = Z; }
    int getZ() { return z; }
    double getR()
    {
        return sqrt(x*x + y*y + z*z);
    }

    string toString()
    {
        stringstream temp;
        // temp << "(" << punkt::getX() << ";" << punkt::getY() << ";" << z << ")";
        temp << "(" << x << ";" << y << ";" << z << ")";
        return temp.str();
    }
};

int main()
{
    pixel p1;
    p1.setX(15);
    p1.setY(35);
    p1.setColor(10, 20, 30);
    cout << p1.toString();
    cout << " " << p1.getR();

    punkt3D p2;

    return 0;
}