#include <iostream>
#include <vector>
#include <iostream>
using namespace std;


class Film {
private:
    string filmCim;
    int filmEv;
    double filmErtekeles;
    int filmHossz;

public:
    Film(string filmCim, int filmEv, double filmErtekeles, int filmHossz)
    {
        this->filmCim = filmCim;
        this->filmEv = filmEv;
        if (filmErtekeles <= 10 && filmErtekeles > 1)
        {
            this->filmErtekeles = filmErtekeles;
        }
        else {
            cout << "Ervenytelen film bevitel: Ertekeles csak 1.0 - 10.0 ertek kozott lehet" << endl;
        }
        this->filmHossz = filmHossz;

    }

    string getFilmCim()
    {
        return this->filmCim;
    }

    int getFilmEv()
    {
        return this->filmEv;
    }

    double getFilmErtekeles()
    {
        return this->filmErtekeles;
    }

    int getFilmHossz()
    {
        return this->filmHossz;
    }

    void filmAdatok()
    {
        cout << "Film cime:         " <<  getFilmCim() << endl;
        cout << "Film  eve:         " << getFilmEv() << endl;
        cout << "Film ertekeles:    " <<  getFilmErtekeles() << endl;
        cout << "Film hossza (perc):" <<  getFilmHossz() << endl;
        cout << "================================" << endl;
    }
};

// Kivalogatas 

template <typename TIPUS, typename P>
TIPUS kivalogatas(TIPUS tomb, int n, P pred)
{
    TIPUS eredmeny;

    for (int i = 0; i < n; i++)
    {
        if (pred(tomb[i]))
        {
            eredmeny.push_back(tomb[i]);
        }
    }

    return eredmeny;
}

// pred fgv
bool paratlan(int num)
{
    return num % 2 != 0;
}

bool ujfilm(Film& film1)
{
    return film1.getFilmEv() > 2000;
}

int main()
{
    vector<int> tomb;
    tomb.push_back(5);
    tomb.push_back(6);
    tomb.push_back(7);

    // vector<int> paratlan = kivalogatas(tomb, tomb.size(), paratlan);

    vector<Film> videoteka;


    Film film1("Casablanca", 1942, 8.5, 102);
    videoteka.push_back(film1);

    Film film2("The Godfather", 1972, 9.2, 175);
    videoteka.push_back(film2);

    Film film3("Interstellar", 2014, 8.6, 169);
    videoteka.push_back(film3);

    Film film4("Forrest Gump", 1994, 8.8, 142);
    videoteka.push_back(film4);

    Film film5("Shrek", 2001, 7.9, 90);
    videoteka.push_back(film5);

    vector<Film> ujak = kivalogatas(videoteka, videoteka.size(), ujfilm);

    for (auto x : ujak)
    {
         cout << x.getFilmEv() << endl;
    }
}
