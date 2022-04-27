#include <iostream>

using namespace std;

typedef struct Dot
{
    float x;
    float y;
}Dot;

int main()
{
    int n;
    float x;

    cout << "Unesite broj tacaka: ";
    cin >> n;

    cout << "Unesite x: ";
    cin >> x;

    Dot dots[n];

    for (int i = 0; i < n; i++)
    {
        cin >> dots[i].x >> dots[i].y;
    }

    int rez = 0;

    for(int i = 0; i < n; i++)
    {
        int deo = 1;
        for(int j = 0; j < n; j++)
        {
            if(i==j)
            {
                continue;
            }
            deo *= (x - dots[j].x)/(dots[i].x - dots[j].x);
        }
        rez += deo * dots[i].y;
    }

    cout << rez;

    return 0;
}
