// CPP f�jlban pedig meg�rjuk a fgv-et
// Komplex::Komplex
// Oszt�lyneve :: oszt�ly �rv�nyess�gi oper�tor, majd pedig mag�nak a fgv a neve
#include "Complex.h"

std::ostream& operator<<(std::ostream& os, Komplex const& k) {
    os << k.re;
    if (k.im >= 0)
        os << "+";
    os << k.im << "i";
    return os;
}

// Els� komplex a visszat�r�si �rt�k t�pusa, m�sodik f�ggv�ny teljes neve (amihez az oszt�ly is hozz�tartozik)
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

    // referenci�t adunk vissza, mag�t az obj v�ltoztatjuk meg
    return *this;
}

// gy�kvon�s, nem oszt�lytag f�ggv�ny, hanem glob�lis f�ggv�ny
// b�rmely val�s sz�mb�l tudjon sqrt vonni, az eredm�ny mindig komplex sz�m legyen

Komplex Komplex_sqrt(double ertek)
{
    if (ertek >= 0)
    {
        return Komplex(sqrt(ertek));
    }

    return Komplex(0, sqrt(-ertek));
}