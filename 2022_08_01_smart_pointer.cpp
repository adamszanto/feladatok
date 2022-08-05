#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    void show()
    {
        cout << "A::show()" << endl;
    }

    A() { cout << "A konstruktor" << endl; };
    ~A() { cout << "A destruktor" << endl; };
};

int main()
{
    shared_ptr<A> p1(new A); // Letrejon egy A tipusu objektum, amire p1 okosmutato mutat. Erre tobb mutato is mutathat, nem unique.
    cout << p1.get() << endl; // A .get()-el Kikeri a benne levo hagyomanyos mutatot. 
    p1->show(); 
    shared_ptr<A> p2(p1);
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    
    // Returns the number of shared_ptr objects
    // referring to the same managed object.s
    // Megmutatja a .use_count() hogy osszesen hany hivatkozas van ra
    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    
    // Relinquishes ownership of p1 on the object
    // and pointer becomes NULL
    p1.reset();
    cout << p1.get() << endl;
    cout << p2.use_count() << endl;
    cout << p2.get() << endl;
    
    // ha a use_count erteke 0 lesz, akkor pedig meg is szunik
    return 0;
}
