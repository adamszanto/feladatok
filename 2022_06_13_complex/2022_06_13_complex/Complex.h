// Header r�sz ahol csak deklar�lunk
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

    // amit visszaad a fgv els� param�tere az ostream referencia, a m�sodik pedig amit ki akarunk iratni
    // oszt�ly bar�tj�ul fogadja a f�ggv�nyt
    // oszt�lyhoz �runk gettereket, �gy l�t bele a f�ggv�ny az oszt�ly tagjaiba
    // kiirat�s
    friend std::ostream& operator<<(std::ostream& os, Komplex const& k);

    // �sszead�s
    Komplex operator+(const Komplex &a);

    // szorz�s

    Komplex operator*(const Komplex &a);

    // += m�velet

    Komplex& operator+=(const Komplex& a);



};

Komplex Komplex_sqrt(double ertek);