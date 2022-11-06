#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    const int n = 50;
    int d = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            for (int k = 1; k < n; k++)
            {
                d = cbrt((i * i * i) + (j * j * j) + (k * k * k));
                if ((i * i * i) + (j * j * j) == (k * k * k) + (d*d*d))
                {
                    cout << "\na : " << i << " b : " << j << " c : " << k << " d : " << d;
                }
            }
        }
    }
}
