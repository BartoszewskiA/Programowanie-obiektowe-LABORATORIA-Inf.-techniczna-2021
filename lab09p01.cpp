#include <iostream>
#include <sstream>

using namespace std;

class student
{
protected:
    int Id;
    string imie;
    string nazwisko;
    string kierunek;
    string wydzial;
    string *historia_studiow;

public:
    static int ile;
    student(string im = "", string nazw = "", string k = "", string w = "") : imie(im), nazwisko(nazw), kierunek(k), wydzial(w)
    {
        Id = ++ile;
        historia_studiow = new string;
        *historia_studiow = "";
    }
    student(const student &wzorzec, string im = "", string nazw = "")
    {
        Id = ++ile;
        imie = im;
        nazwisko = nazw;
        kierunek = wzorzec.kierunek;
        wydzial = wzorzec.wydzial;
        // historia_studiow = wzorzec.historia_studiow; // - kopiowanie płytkie
        historia_studiow = new string;
        * historia_studiow = "";

    }

    void addWpis(string tekst)
    {
        string temp = *historia_studiow;
        temp += "\n";
        temp += tekst;
        *historia_studiow = temp;
    }

    string toString()
    {
        stringstream temp;
        temp << "(" << Id << ") " << nazwisko << " " << imie << " Wydzial: " << wydzial << " Kierunek: " << kierunek
             << endl
             << "Historia studiow: " << *historia_studiow;
        return temp.str();
    }

    ~student()
    {
        delete historia_studiow;
    }
};

int student::ile = 0;

student kierunki[] = {
    student("", "", "Informatyka techniczna", "WTEiI"),
    student("", "", "Informatyka ogolnoakademicka", "WTEiI"),
    student("", "", "Pedagogika", "WFP"),
    student("", "", "Transport", "WTEiI")};

int main()
{
    student::ile = 0;

    student s1(kierunki[0], "Jan", "Kowalski");
    s1.addWpis("Przyjety na studia.");
    s1.addWpis("Zdal na 2 semestr");
    
    student s2(kierunki[0], "Andrzej", "Nowak");
    s2.addWpis("Przyjety na studia.");
    s2.addWpis("Skreslony z listy studentow");

    cout << s1.toString()<<endl;
    cout << s2.toString();

    return 0;
}