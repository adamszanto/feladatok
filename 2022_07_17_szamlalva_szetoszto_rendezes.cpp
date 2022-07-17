#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// szetoszto rendezes

vector<int> szam(int tomb[], int size, int m)
{
	vector<int> db(m);
	for (int i = 0; i < size; i++)
	{
		if (tomb[i] != 0)
		{
			db[tomb[i]]++;
		}
	}

	int count = 0;

	for (int i = 0; i < m; i++)
	{
		count += db[i];
		db[i] = count;
	}
	
	vector<int> y(size, 0);

	for (int i = 0; i < size; i++)
	{
		y[db[tomb[i]] - 1] = tomb[i];
		db[tomb[i]]--;
	}

	return y;
}

int main()
{
	int tomb[] = { 4,3,5,4,2,1,8,4,8,2,3,4 };
	int size = sizeof(tomb) / sizeof(int);
	int m = 9;

	vector<int> eredmeny = szam(tomb, size, m);

	for (int i = 0; i < size; i++)
	{
		cout << (i+1) << ". szam: " << eredmeny[i] << endl;
	}

}

