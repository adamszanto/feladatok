#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define ellenoriz(felt, pont) if (felt) pont++; else cerr << "Nem teljesul a feltetel a " << __LINE__<< ". sorban." <<endl;


/* Szabályok:

    - csak az a beugró érvényes, amely nem tartalmaz semmilyen változtatást a main()-ben,
        és már nincs benne kommentezve semmi az "//idaig" sor után
    - az "ellenoriz"-en kívül nem tartalmaz #define sorokat, és azt sem szabad megváltoztatni
    - új #include megengedett a C/C++ standard könyvtárbeli elemek közül
*/



// Innentol

string kezd()
{
    return "Ertem, hogy ez NEM az ervenyesseg feltetele";
}

// Idaig


//2020 május 22.

struct S {
    float f;
    int i;
};

class A {
public:
    int x;
    int temp;

    A()
    {
        temp = 0;
        x = 3;
    } 

    A(const A& obj)
    {
        x = obj.x + 1;
    }

    int ezmegmi()
    {
        // statikus változóként
        // static int y = 0;
        // y++;
        // return y;
        temp++;
        return temp;
    }
};

class B
{


public:
    string &y;
    // a ref. típusú változók kell hogy értéket kapjanak. amikor ref. típusú változó készül, akkor a konstruktorba így kell
    // hogy értéket kapjon, a tag inicializációs listán keresztül. hasonlóan mint a konstansok esetében kell értéket kapniuk.
    // az y változó kapcsolódjon a be változóhoz. a mainben lévő s1-et hozzákapcsoltuk a be segítségével az y-hoz, és ha az y megváltoztatjuk, mivel az referencia így megváltoztathatjuk az eredetit is, mert ugyan arra hivatkozunk két referenciával.
    B(string& be) :y(be)
    {
        y = "lent";
    }

    ~B()
    {
        y = "fent";
    }
    // A konstruktornak nincs visszatérési értelme, de vannak paraméterei
    // A destruktornak nincs értelme paramétert átadni. Objektumokhoz kapcsolódó erőforrásokat bezárja, lezárja, dinamikus memóriát felszabadítsa, stb.
};

int main()
{
    int pont = 0;


    string s = kezd();
    ellenoriz(s == "Ertem, hogy ez NEM az ervenyesseg feltetele", pont);
    
    A a;
    ellenoriz(a.x == 3, pont);
    
    set<S> lefordule;
    ellenoriz(lefordule.size() == 0, pont);
    
    A b(a);
    ellenoriz(b.x == 4, pont);
    ellenoriz(b.x == 4, pont);
    
    A x;
    ellenoriz(x.ezmegmi() == 1 && x.ezmegmi() == 2, pont);
    
    string s1 = "egyszer";
    {
        B b(s1);
        ellenoriz(s1 == "lent", pont);
        ellenoriz(s1 == "lent", pont);
    }
    
    ellenoriz(s1 == "fent", pont);
    ellenoriz(s1 == "fent", pont);

    
    cout << endl << pont << "/10 pont" << endl;
}
