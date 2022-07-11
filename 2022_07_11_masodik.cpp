#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// szetoszto rendezes:
vector <int> szetoszto(int tomb[], int n)
{
    vector <int> y(n+1);

    for (int i = 0; i < n; i++)
    {
        y[tomb[i]] = tomb[i];
    }

    return y;

}

// szamlalva szetoszto rendezes:
// H.F.

int main()
{
    int tomb[] = { 1,4,2,3,5 };
    int n = sizeof(tomb) / sizeof(int);

    vector<int> eredmeny = szetoszto(tomb, n);

    for (int i = 1; i < eredmeny.size(); i++)
    {
        cout << i << ". elem: " << eredmeny[i] << endl;
    }

}
