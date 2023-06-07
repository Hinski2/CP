#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ileBonow;                      //liczba bonów,
    bool iBon[1000005],used[1000005];  //nr. paczki z bonem , numery które są wolne/zapisane
    int ileDni,ileOsob;       //liczba dni karnawału,ilość osób w poszczgólnym dniu karnawału
    int sold=0,guest[1000005];         //zmienna pomocnicza , liczba osób które kupiły cukierki przy poszczególnej liczbie gości
    int wynik=0,iWypisanie[1000005];   //wynik ,nr osoby z bonem
    int q,y;                           //zmienne pomocnicze
    const int Max=100000;

    scanf("%d",&ileBonow);
    for(int i=1;i<=ileBonow;i++)
    {
        scanf("%d",&q);
        iBon[q]=true;
    }

    scanf("%d",&ileDni);
    for(int i=1;i<=ileDni;i++)
    {
        scanf("%d",&ileOsob[i]);
    }

    //koniec wczytywania danych 
    for(int i=1;i<=ileDni;i++)  
    {
        if(guest[ileOsob[i]]==0)guest[ileOsob[i]]=1;

        for(int x=guest[ileOsob[i]];x<ileOsob[i]+guest[ileOsob[i]]+y;x++)
        {
            if(x*ileOsob[i]>Max)break;
            if(used[x*ileOsob[i]]==false)       //jeśli ta liczba nie wystąpiła
            {
                sold++;
                used[x*ileOsob[i]]=true;
                if(iBon[x*ileOsob[i]]==true)
                {
                    iWypisanie[wynik]=sold;
                    wynik++;
                }
            }

            else                                //jeśli ta liczba wystąpiła
            {
                y++;
                continue;
            }
        }
        guest[ileOsob[i]]=guest[ileOsob[i]]+ileOsob[i]+y;
        y=0;
    }
    
    //sortowanie osób z bonami
    sort(iWypisanie, iWypisanie+wynik);

    //wypisanie wyniku 
    printf("%d\n",wynik);
    for(int i=0;i<wynik;i++)
    {
        printf("%d\n",iWypisanie[i]);
    }
}