#include <bits/stdc++.h>
using namespace std;

int autostrada[50005],ileCity;
long long ans;

long long dystans(int mniejszy ,int wiekszy)
{
    if(mniejszy>wiekszy) swap(mniejszy,wiekszy);//sprawia że zminenna mniejszy jest zawsze mniejsza
    //zwraca mniejsząz liczb podziału 
    return min(autostrada[wiekszy]-autostrada[mniejszy],autostrada[ileCity-1]-(autostrada[wiekszy]-autostrada[mniejszy]));
}
    
int main()
{
    // wczytywanie ilości autostrad
    scanf("%d",&ileCity);
    //wczytywaniue długości każdej autostrady 
    for(int i=0;i<ileCity;i++)
    {
        scanf("%d",&autostrada[i]);
        if(i)// jeśli i>0
        {
            autostrada[i]+=autostrada[i-1];
        }   
    }
    
    int j=0;//zmnienna pomocnicza

    for(int i=0;i<ileCity;i++)
    {
        while(dystans(i,j)<dystans(i,(j+1)%ileCity))j=(j+1)%ileCity;//szuka najlepszego podziału 
        ans=max(ans,dystans(i,j));
    }
    cout<<ans<<endl;//wypisuje wynik 
}
