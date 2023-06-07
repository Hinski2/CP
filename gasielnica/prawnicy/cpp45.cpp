//niedokończone
#include <bits/stdc++.h>
using namespace std;

int ilePracuje,ilePotrzeba,iUsuwanie[1000005];
vector<pair<int,int>>prawnik[1000005];//pokazuke od której godziny zaczyna się przerwa i o której siękończy

void sprawdzenie()
{

    int wynik=0,lewo=0,prawo=0;
    for(int i=1;i<=ilePotrzeba;i++)//wczytuje pierwszy zestaw
    {
        lewo=max(lewo,prawnik[i].first);//najwalej wysunięta na prawo lewa pozycja 
        prawo=min(prawo,prawnik[i].second);//najdalej wysunięta na lewo pozycja
    }
    for(int i=ilePotrzeba;i<ilePracuje-ilePotrzeba;i++)//sprawdza zestawy
    {
        if(prawo-lewo>wynik)//sprawdza czy zestaw ma największy wynik 
        {
            //zapisuje ten wynik oraz liczby dla których się wydażył 
            wynik=prawo-lewo;

        }


    }
}
int main()
{
    scanf("%d%d",&ilePracuje,&ilePotrzeba);//wczytuje ile jest w firmie prawników i ile potrzeba do spotkania

    for(int i=1;i<=ilePracuje;i++)//wczytywanie dostępności w i-tej godzinie
    {   int start,stop;
        scanf("%d%d",&start,&stop);
        iUsuwanie[i]=stop;
        prawnik[i].push_back({start,stop});
    }
    sort(iUsuwanie+1,iUsuwanie+ilePracuje);//sortuje w kojeności co najpierw lpowinno usunąć
    cout<<sprawdzenie()<<endl;//funkcja rozwiązująca zadanie
}