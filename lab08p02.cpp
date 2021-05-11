#include <iostream>
#include <sstream>

using namespace std;

class RGB
{
private:
    int R;
    int G;
    int B;

public:
    int getR() { return R; }
    int getG() { return G; }
    int getB() { return B; }
    void setR(int r) { R = r; }
    void setG(int g) { R = g; }
    void setB(int b) { R = b; }
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
       kolor.setR(r);
       kolor.setG(g);
       kolor.setB(b);

    }
    RGB getColor() { return kolor; }
};

int main()
{
    pixel p1;
    p1.setColor(10, 20, 30);
    cout << p1.getColor().getR();

    pixel *p2 = new pixel;
    p2->setColor(100, 200, 300);
    cout << p2->getColor().getG();
    return 0;
}