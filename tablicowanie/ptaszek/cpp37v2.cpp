#include <bits/stdc++.h>
using namespace std;

int ileDrzew,ilePtakow,czakraPtaka,high[1000005],indeks;

list <pair <int, int> > lista[1000005];

int move(int i)
{
    while(true)
    {
        while(lista[indeks].size()>0 && lista[indeks].front().second<i-czakraPtaka)
        {
            lista[indeks].pop_front();
        }
        if(!lista[indeks].empty())break;
        indeks++;
    }
    return lista[indeks].front().first;
}

void add(int w,int i)
{
    int wysokosc=high[i];

    while(lista[w].size()>0 && lista[w].back().first<=wysokosc)
    {
        lista[w].pop_back();
    }

    lista[w].push_back({wysokosc,i});
}

int solve()
{
    int answer;
    indeks=0;

    for(int i=0;i<=ileDrzew;i++)
    {
        lista[i].clear();
    }

    add(0,1);

    for(int i=2;i<=ileDrzew;i++)
    {
        int x=move(i);
        int wynik=indeks+(x<=high[i]);
        add(wynik,i);

        if(i==ileDrzew)answer=wynik;
    }
    return answer;
}

int main()
{
    scanf("%d", &ileDrzew);

    for(int i=1;i<=ileDrzew;i++)
    {
        scanf("%d", &high[i]);
    }
    scanf("%d",&ilePtakow);
    while(ilePtakow--)
    {
        scanf("%d",&czakraPtaka);
        printf("%d\n", solve()); 
    }
}