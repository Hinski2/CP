#include <bits/stdc++.h>
using namespace std;

const int liczba=(1<<10)-1;
bitset<10>primeSet(liczba);
int n,m;
int acces;

void setowanie(string str,int dlugosc)
{
    bitset<10>subSet(0);

    for(int i=1;i<=dlugosc;i++)
    {
        subSet[str[i]-48]=true;    //zapisanie jakie liczby byłu użyte 
    }
    primeSet&=subSet;           //aktualizacja cyfr
}

int rozmiar(string str,int dlugosc)
{
    for(int i=0;i<primeSet.size();i++)                  //sprawdzenie jaki cyfry są dostępne 
    {
        if(primeSet[i]) acces++;
    }

    return acces;
}

int generowanie(int wilekosc)
{
    int ans=0;

    for(int i=wilekosc; i>0; i--)
    {
        vector<int>warstwy[4];

        warstwy[1].push_back(i);

        for(int level=2; level<4; level++)//dla poziomów 2 i 3 
        {
            for(int j=0;j<warstwy[level-1].size();j++)
            {
                for(int add=warstwy[level-1][j];add>=1;add--)
                {
                    warstwy[level].push_back(add);
                }
            }
        }
        //zliczanie wyniku
        for(int i=0;i<warstwy[3].size();i++)
        {
            ans+=warstwy[3][i];
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  //magiczna linijka

    string s;                   


    cin>>n;                     //wczytanie ilości ciągów 
    for(int i=0; i<n; i++)      //dla każdego ciągu
    {
        cin>>m;                 //wczytanie długości ciągu
        getline(cin,s);         //wczytanie ciągu

        setowanie(s,m);         //sprawdzenie jakie liczby są w ciągu
    }

    cout<<generowanie(rozmiar(s,m))<<"\n"; 
}