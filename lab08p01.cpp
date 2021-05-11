#include <iostream>
#include <sstream>

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
};

int main()
{
    pixel p1;
    p1.setColor(10, 20, 30);
    cout << p1.getColor().R;

    pixel *p2 = new pixel;
    p2->setColor(100, 200, 300);
    cout << p2->getColor().G;
    return 0;
}