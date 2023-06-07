#include <bits/stdc++.h>
using namespace std;

int ileWojska,ansIle,suma=1;
long long zasieg,wsp[50005],ansPos;

int main()
{
    scanf("%d%lld",&ileWojska,&zasieg);
    //wczytywanie położenia każdego żołnierza
    for(int i=0;i<ileWojska;i++)
    {
        long long x;
        scanf("%lld",&x);
        wsp[i]=x;
    }
    sort(wsp,wsp+ileWojska);//sortowanie
    int l=0,r=1;//implementacja lewego i prawego końca gąsielnicy
    zasieg*=2;
    //gąsielnica
    for(int i=0;i<ileWojska;i++)
    {
        if(wsp[l]+zasieg>=wsp[r])//jeśli r zanjduje się pomiędzy l a zasięgiem wieży 
        {
            suma++;
            r++;
        }
        else //jeśłi r znajduje się poza l a widzeniem wieży 
        {
            if(suma>0)suma--;
            l++;
        }
        //sparwdzenie wyniku
        if(suma>ansIle)
        {
            ansIle=suma;
            ansPos=wsp[r-1]-(zasieg/2);
        }
    }
    //wypisanie wyniku
    cout<<ansPos<<" "<<ansIle;
}