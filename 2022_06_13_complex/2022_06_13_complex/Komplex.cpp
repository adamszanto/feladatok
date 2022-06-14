// CPP fájlban pedig megírjuk a fgv-et
// Komplex::Komplex
// Osztályneve :: osztály érvényességi operátor, majd pedig magának a fgv a neve
#include "Komplex.h"

std::ostream& operator<<(std::ostream& os, Komplex const& k) {
    os << k.re;
    if (k.im >= 0)
        os << "+";
    os << k.im << "i";
    return os;
}

// Elsõ komplex a visszatérési érték típusa, második függvény teljes neve (amihez az osztály is hozzátartozik)
Komplex Komplex:: operator+(const Komplex& a) {
   

    return Komplex(re + a.re, im + a.im);

    /*
    Komplex c;
    c.re = re + a.re;
    c.im = im + a.im;

    return c;
    */

}

Komplex Komplex:: operator*(const Komplex& a)
{
    return Komplex(re * a.re - im * a.im, re * a.im + im * a.re);
}

Komplex& Komplex:: operator+=(const Komplex& a)
{
    re += a.re;
    im += a.im;

    // referenciát adunk vissza, magát az obj változtatjuk meg
    return *this;
}

// gyökvonás, nem osztálytag függvény, hanem globális függvény
// bármely valós számból tudjon sqrt vonni, az eredmény mindig komplex szám legyen

Komplex Komplex_sqrt(double ertek)
{
    if (ertek >= 0)
    {
        return Komplex(sqrt(ertek));
    }

    return Komplex(0, sqrt(-ertek));
}
