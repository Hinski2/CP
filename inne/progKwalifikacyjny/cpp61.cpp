#include <bits/stdc++.h>
using namespace std;

long long ileZadan,zad[200015],ileSnow;
vector<pair<long long,long long>>sen(200015);
long long ans[200015];

int main()
{
    //skanowanie zadań 
    scanf("%lld",&ileZadan);
    for(int i=0;i<ileZadan;i++)
    {
        scanf("%lld",&zad[i]);
    }

    //skanowanie snów
    scanf("%lld",&ileSnow);
    for(int i=0;i<ileSnow;i++)
    {
        long long x;
        scanf("%lld",&x);
        sen[i]={x,i};
    }

    //liczenie
    sort(zad,zad+ileZadan,greater<long long>());
    sort(sen.begin(),sen.begin()+ileSnow);

    long long wynik = 0;
    long long ile = 0;

    for(int i=0;i<ileSnow;i++)
    {
        while(wynik < sen[i].first)
        {
            wynik+=zad[ile];
            ile++;
        }
        ans[sen[i].second]=ile;
    }
    //sypisanie
    for(int i=0;i<ileSnow;i++)
    {
        printf("%lld\n",ans[i]);
    }
}