#include <bits/stdc++.h>
using namespace std;

const int MAX  = 100*10000+10;
int n,rodzaj[MAX],wynik,Max;
bool nie[MAX];

int main()
{
    //wczytywanie
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&rodzaj[i]);
    }
    
    int x = 0;
    while(wynik == 0)
    {
        x++;
        for(int i = 0;i < n ;i++)
        {
            if((rodzaj[i] % x) == 0)break;
            if(i == n-1)wynik = x;
        }
    }
    //wypisanie wyniku
    printf("%d\n",wynik);
}