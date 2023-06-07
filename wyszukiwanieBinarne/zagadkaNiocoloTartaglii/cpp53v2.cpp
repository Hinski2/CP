#include <bits/stdc++.h>
using namespace std;

int ile;
long long p,q;

int sprawdzenie(long long p,long long q)
{
    long long l=0,r=1000000;
    long long x=(l+r)/2,wynik=x*x*x+p*x;
    while(l<r)
    {
        if(wynik>q)     //wynik<q
        {
           r=x-1;
        }
        else            //wynik>=q
        {
            l=x;
        }

        x=(l+r+1)/2;
        wynik=x*x*x+p*x;
    }

    if(wynik==q)        //if wynik==q
    {
        printf("%lld\n",x);
        return 0;
    }
    else
    {
        printf("NIE\n");
        return 0;
    }
    
}

int main()
{
    scanf("%d",&ile);//ilość zagadek 
    while(ile--)//rozwiązanie dla każdej zagatki 
    {
        scanf("%lld %lld",&p,&q);
        sprawdzenie(p,q);
    }
}