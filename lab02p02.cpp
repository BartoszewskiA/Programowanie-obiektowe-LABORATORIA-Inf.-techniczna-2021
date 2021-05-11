#include <iostream>
#include <ctime>

using namespace std;

class osoba
{
private:
    string imie;
    string nazwisko;
    int rok_urodzenia;

public:
    void setImie(string im) {imie=im;}
    void setNazwisko(string nazw) {nazwisko=nazw;}
    void setWiek( int wiek);
    void setRokUrodzenia(int r) {rok_urodzenia=r;}
    string getImie() {return imie;}
    string getNazwisko() {return nazwisko;}
    int getRokUrodzenia() {return rok_urodzenia;}
    int getWiek();
};

void osoba::setWiek(int wiek)
{
    time_t czas = time(NULL);
    tm* czas_lokalny = localtime(&czas);
    rok_urodzenia = 1900 + czas_lokalny->tm_year - wiek;
}

int osoba::getWiek()
{
    time_t czas = time(NULL);
    tm* czas_lokalny = localtime(&czas);
    return (1900 + czas_lokalny->tm_year) - rok_urodzenia;
}

int
main()
{
    osoba ktos;
    string s;
    int w;
    cout<<"podaj imie: ";
    cin>>s;
    ktos.setImie(s);
    cout<<"podaj nazwisko: ";
    cin>>s;
    ktos.setNazwisko(s);
    cout<<"podaj rok urodzenia: ";
    cin>>w;
    //ktos.setWiek(w);
    ktos.setRokUrodzenia(w);

    cout<<ktos.getNazwisko()<<" "<<ktos.getImie()<<" lat "<<ktos.getWiek();
    return 0;
}