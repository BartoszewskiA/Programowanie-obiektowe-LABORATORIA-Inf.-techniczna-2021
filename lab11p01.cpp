#include <iostream>

using namespace std;

// Utworzyć klasę ARGB - pochodną od RGB a w niej:
//      Pole statyczne informujące o liczbie istniejących obiektów klasy ARGB
//      Operatory:
//          ARGB +/- ARGB
//          != ==
//          > < - porównujemy jasność (R+G+B)/3
//          << >> format  A,R,G,B  - A, R, G, B -  dziesiętnie np: 255,0,0,255   50,100,10,50

class RGB
{
protected:
    int R;
    int G;
    int B;
public:
    RGB(int r=0, int g=0, int b=0):R(r), G(g), B(b) {}
    int getR() {return R;}
    int getG() {return G;}
    int getB() {return B;}
};

int main()
{
    
    return 0;
}