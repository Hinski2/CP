#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

long long wynik;
int ilosc,typ,arr[1000005],liczba,r,l;
bool boo[1000005];

int main()
{
    scanf("%d %d",&ilosc,&typ);

    if(typ == 1)
    {
        printf("%d",ilosc);
        return 0;
    }
    for(int i=0;i<ilosc;i++)
    {
        scanf("%d",&liczba);
        arr[i]=liczba;
    }

    for(l;l<ilosc;boo[arr[l++]]=false)
    {
        while(boo[arr[r]]==false&&r<ilosc)
        {
            boo[arr[r++]]=true;
        }
        wynik+=r-l;
    }
    printf("%lld\n",wynik);
}