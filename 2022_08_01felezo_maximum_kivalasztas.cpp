#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int felezo(T tomb, int bal, int jobb)
{
	int center;
	int balmax;
	int jobbmax;
	if (bal == jobb)
	{
		return bal;
	}
	else {
		center = (bal + jobb) / 2;
		balmax = felezo(tomb, bal, center);
		jobbmax = felezo(tomb, center + 1, jobb);

		if (tomb[balmax] >= tomb[jobbmax])
		{
			return balmax;
		}
		else {
			return jobbmax;
		}

	}
}

int main()
{
	int tomb[] = { 2,10,13,8,7,5 };
	cout << "A tomb index :" <<felezo(tomb, 0, sizeof(tomb) / sizeof(int) - 1) << endl;

	vector<int> vektor;
	vektor.push_back(2);
	vektor.push_back(10);
	vektor.push_back(13);
	vektor.push_back(8);
	vektor.push_back(7);
	vektor.push_back(5);

	cout << "A vektor index :" << felezo(vektor, 0, vektor.size()-1) << endl;

}

