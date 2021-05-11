#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random
{
public:
    Random()
    {
        srand(time(NULL));
    }
    int nextInt()
    {
        return rand();
    }
    int nextInt(int b) // <0,b)
    {
        return rand()%b;
    }
    int nextInt(int a, int b) //<a;b)
    {
        return rand()%(b-a)+a;
    }
    double nextDouble()
    {
        return (double)1/(rand()%100+1); // <0,1> rzeczywista
    }
    int kostka()
    {
        return rand()%6+1;
    }
    string moneta()
    {
        int w = rand();
        if (w%2==1) return "orzel";
        else return "reszka";
    }
};

int main()
{
    Random *random = new Random;
    for (int i=0; i<30;i++)
     cout << random->nextDouble()<<"  ";
    
    delete random;
    //getchar();
    return 0;
}
