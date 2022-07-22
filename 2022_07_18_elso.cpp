#include <iostream>
#include <vector>
#include <map>
using namespace std;


#define ellenoriz(felt, pont) if (felt) pont++; else cerr << "Nem teljesul a feltetel a " << __LINE__<< ". sorban." <<endl;

/* Szabalyok:
    - csak az a beugró érvényes, amely nem tartalmaz semmilyen változtatást a main()-ben,
        és már nincs benne kommentezve semmi
    - az "ellenoriz"-en kívül nem tartalmaz #define sorokat, és azt sem szabad megváltoztatni
*/

// Innentol

class A
{
public:

    vector<int> vektor;

    vector<int>::iterator eleje()
    {
        return vektor.begin();
    }

    vector<int>::iterator vege()
    {
        return vektor.end();
    }

    A()
    {
        vektor.push_back(10);
    }
};

class C
{
public:
    int c;
    int d;

    C()
    {
        c = 33;
        d = 0;
    }

    // default parameter a num2 eseteben, ha adunk neki erteket akkor azt megkapja a d
    C(int num1, int num2 = 0)
    {
        c = num1;
        d = num2;
    }

    // map kulcs miatt kell mert a kulcsoknak osszehasonlithatoak kell hogy legyenek:
    bool operator< (const C& vizsgalt) const
    {
        return c < vizsgalt.c || (c == vizsgalt.c && d < vizsgalt.d);
    }
};

class D
{
    
public: int& d;
      // :d(d0) a tag inicializacios lista, a konstansoknak es referenciaknak csak igy lehet erteket adni!!
      D(int& d0) :d(d0) {}
      ~D() { d++; }
};

// Pelda a tag inicializacios listara:

/*
* 
* class Valami
{
    int x, y, z;
    Valami (int x0, int y0, int z0): x(x0), y(y0), z(z0) {}

}
* 
* 
* 
*/

int ezmegmi(int num1, int num2, int num3 = 0, int num4 = 0)
{
    if (num4 != 0)
    {
        return num4;
    }
    else if (num3 != 0)
    {
        return num3;
    }
    else {
        return num2;
    }
}

// Idaig




int main()
{
    int pont = 0;
    
        C c;
        ellenoriz(c.c==33, pont)

        map<C, int> m;
        m[C(1)]=2;
        m[C(1)]=1;
        ellenoriz(m.size()==1,  pont )
        ellenoriz(m.at(C(1))==1,  pont )
            
        m[C(2,1)]=3;
        m[C(1,2)]=2;
        m[C(1)]=1;
        m[C(1,2)]=2;
        m.erase(C(2,1));
        ellenoriz(m.size()==2,  pont )
        ellenoriz(m.at(C(1,0))==1 && m.at(C(1,2))==2,  pont )
            
        int egyik = ezmegmi(1,2);
        int masik = ezmegmi(1,2,3);
        int harmadik = ezmegmi(1,2,3,4);
        ellenoriz(egyik==2 && masik==3 && harmadik==4,  pont )
            
        A a;
        int sum=0;
        for (vector<int>::iterator it = a.eleje(); it!=a.vege(); ++it) {
            sum+=*it;
        }
        ellenoriz(sum==10,  pont )
        ellenoriz(sum==10,  pont ) // ez ket pontot er


        int pp=3;
        int pk;
        {
            D d(pp);
            pk = pp;
        }
        ellenoriz(pp!=pk, pont)
        ellenoriz(pp!=pk, pont) // ez ket pontot er

 
    cout << pont << "/10 pont" << endl;
    return 0;
}
