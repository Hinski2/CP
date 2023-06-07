#include <bits/stdc++.h>
using namespace std;

int ciagLength,ileSearch;
vector<int> pos[1000005];

void sprawdzenie()
{
    int length,pozycja=0;
    bool wypisanie=true;// może się przydać ale niekońecznie TODO: może potem usuń 

    scanf("%d",&length);
    for(int i=0;i<length;i++)//wykonuje się dla każdej liczby w 2 linijce
    {
        int num;
        scanf("%d",&num);
        auto x=lower_bound(pos[num].begin(),pos[num].end(),pozycja);
        if(x==pos[num].end())
        {
            wypisanie=false;
        }
        else
        {
            pozycja=*x+1;
        }
    }
    //wypisanie wyniku 
    if(wypisanie==false)printf("%s\n","NIE");
    else printf("%s\n","TAK");

}

int main()
{
    scanf("%d",&ciagLength);
    for(int i=0;i<ciagLength;i++)
    {
        int x;
        scanf("%d",&x);
        pos[x].push_back(i);
    }
    scanf("%d",&ileSearch);
    while(ileSearch--)
    {
        sprawdzenie();
    }
}