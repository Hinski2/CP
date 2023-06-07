#include <bits/stdc++.h>
using namespace std;

const int MAX  = 100005;
int n,x,wynik;
bool rodzaj[MAX],nie[MAX];


int main()
{
    //wczytywanie
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        rodzaj[x] = true;
    }

    //liczene
    for(int i = 1;i <= 1e5;i++)
    {
        bool find = false;
        for(int j = i;j <= 1e5;j += i)
        {
            if(rodzaj[j] == true)
            {
                find = true;
                break;
            }
        }
        nie[i]=find;
    }

    //szukanie
    for(int i = 1;wynik == 0;i++)
    {
        if(nie[i] == false)wynik = i;
    }

    //wypisywanie
    printf("%d\n",wynik);
}
