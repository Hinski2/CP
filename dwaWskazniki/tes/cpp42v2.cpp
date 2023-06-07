#include <bits/stdc++.h>
using namespace std;

int ileDostepne,dostepne[1000005],ileWierszy;

string sprawdzenie()
{
    int dlugosc,szukaj;
    scanf("%d",&dlugosc);
    int i=0;

    for(int x=0;x<dlugosc;x++)               //wykonuje się dla każdej liczby którą szukamy
    {
        scanf("%d",&szukaj);                 //wczytuje szukaną liczbę
        for(;i<ileDostepne;i++)              //przechodzi po tablicy 
        {
            if(szukaj==dostepne[i])
            {
                if(x+1==dlugosc)return "TAK";//znalazł ostatnią liczbę
                else break;                  //jeszcze są liczby do znalezienia
            }
        }
        if(i+1==ileDostepne)return "NIE";
    }
    return "NIE";
}
int main()
{
    scanf("%d",&ileDostepne);
    for(int i=0;i<ileDostepne;i++)
    {
        scanf("%d",&dostepne[i]);
    }

    scanf("%d",&ileWierszy);
    for(int x=0;x<ileWierszy;x++)
    {
        cout<<sprawdzenie()<<endl;
    }
}