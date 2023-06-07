#include <bits/stdc++.h>
using namespace std;

int ileDrzew,ilePtakow,czakra[25],maxx;
long long int hight[1000010];

vector<pair<int,int>>wynik[1000005];

void check(int drzewo,int ile)
{
    int minn=-1;
    
    int x=0;
    if(drzewo==1)x=1;
    else x=min(ile,drzewo-1);

    if(ile==1)
    {
        return build(drzewo-1,ile)+sprawdzenie(drzewo);
    }
    else
    {
        for(int i=0;i<ile;i++)
        {
            minn=min(build(drzewo-1,x)+sprawdzenie(drzewo),minn)
        }
        return minn;
    }
}

void sprawdzenie(int x)
{
    if(hight[x-1]<=hight[x]) return 1;
    else return 0;
}

int build(int drzewo,int ile)
{
    if(drzewo==1) return 0;
    if(wynik[drzewo][ile]!=-1) return wynik[drzewo][ile];
    else return wynik[drzewo][ile]=c(drzewo,ile);
}

int main()
{
    scanf("%d", &ileDrzew);//skanuje ilość drzew
    for(int i=0;i<ileDrzew;i++)
    {
        scanf("%lld", &hight[i]);//przypisuje do każdego drzewa jego wysokość
    }
    scanf("%d",&ilePtakow);//skanuje iliość ptaków
    for(int i=0;i<ilePtakow;i++)
    {
        scanf("%d",&czakra[i]);//przyppisuje ilośc siły każdemu ptaku 
        maxx=max(czakra[i],maxx); 
    }

    //koniec skanowania początek liczenia
    for(int x=1;x<=ileDrzew;x++)
    {
        for(int y=1;y<=min(x,maxx);y++)
        {
            wynik[x].push_back(y,-1);
        }
    }
    //budowanie
    for(int i=1;i<=maxx;i++)
    {
        build(ileDrzew,i);
    }
    //wypisywanie
    for(int i=0;i<ilePtakow;i++)
    {
        cout<<wynik[ileDrzew][czakra[i]]<<"\n";
    }
}