#pragma once

// Header rész ahol csak deklarálunk
#include <iostream>

class Komplex
{
    double re;
    double im;
public:
    Komplex(double re = 0, double im = 0)
    {
        this->re = re;
        this->im = im;
    }

    // amit visszaad a fgv elsõ paramétere az ostream referencia, a második pedig amit ki akarunk iratni
    // osztály barátjául fogadja a függvényt
    // osztályhoz írunk gettereket, így lát bele a függvény az osztály tagjaiba
    // kiiratás
    friend std::ostream& operator<<(std::ostream& os, Komplex const& k);

    // összeadás
    Komplex operator+(const Komplex& a);

    // szorzás

    Komplex operator*(const Komplex& a);

    // += mûvelet

    Komplex& operator+=(const Komplex& a);

    // Házi feladat
    bool operator==(const Komplex& a);

    bool operator!=(const Komplex& a);

};

Komplex Komplex_sqrt(double ertek);