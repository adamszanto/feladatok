#include <iostream>
using namespace std;

template<typename T>
int maximum(T* tomb, int jobb)
{
    int max = 1;

    if (jobb == 0)
    {
        return 0;
    }
    else {
        max = maximum(tomb, jobb - 1);
        if (tomb[jobb] >= tomb[max])
        {
            return jobb;
        }
        else {
            return max;
        }
    }


}

int main()
{
    int tomb[] = {2,1,6,5,8,3};

    cout << "A max elem = " << (maximum(tomb, 6)+1) << "." << endl;
}
