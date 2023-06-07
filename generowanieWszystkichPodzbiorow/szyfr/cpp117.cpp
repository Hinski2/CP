#include <bits/stdc++.h>
using namespace std;

int n;
int s, arr[45];
bool is[45];


int main()
{
    //wczytywanie
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &s);

    //liczenie
    for(int mask = 0; mask < (1 << n); mask++)
    {
        //generaowanie podzbioru
        int temp = mask;
        for(int i = 0; i < n; i++)
        {
            is[i] = temp % 2;
            temp /= 2;
        }
        int liczba = 0;
        for(int i = 0; i < n; i++)
        {
            liczba += (int)is[i] * arr[i];
        }

        //sprawdzanie podzbioru
        if(liczba == s)
        {
            for(int i = 0; i < n; i++)
            {
                cout<<is[i];
            }
        }
    }
}