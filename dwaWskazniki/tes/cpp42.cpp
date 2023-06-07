#include <bits/stdc++.h>
using namespace std;

int ileDostepne,dostepne[1000005],ileWierszy;
string sprawdzenie()
{
    int ileLiczb;
    int a,b,usun=0; 
    scanf("%d",&ileLiczb);
    for(int i=0;i<=ileLiczb;i++)
    {
        if(i==ileLiczb)
        {
            if(dostepne[a]<usun)return "NIE";
            else return "TAk";
        }
        scanf("%d",&b);
        if(i==0)a=b;

        if(a==b)usun++;
        else
        {
            if(dostepne[a]<usun)//do usunięcia jest więcej liczb niz jest dostępnych
            {
                usun=1;
                return "NIE";
            }
            else//do usunuięcia jest mniej lub tyle samo liczb co dostepnych
            {
                usun=1;
                a=b;
                continue;
            }
        }
    }
    return "TAk";
}
int main()
{
    int liczba;
    scanf("%d",&ileDostepne);
    for(int i=0;i<ileDostepne;i++)
    {
        scanf("%d",&liczba);
        dostepne[liczba]++;
    }

    scanf("%d",&ileWierszy);
    for(int x=0;x<ileWierszy;x++)
    {
        cout<<sprawdzenie()<<endl;
    }
}