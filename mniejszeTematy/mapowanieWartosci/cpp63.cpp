#include <bits/stdc++.h>
using namespace std;

const int maks=1000*1000+15;
int n,stole,arr[maks];

void mapowanie()
{
    map<int,int>mapka;//mapa

    for(int i=1;i<=n;i++)//dodawanie wartości do mapy
    {
        mapka[arr[i]]=1;
    }

    int idx=1;
    for(auto i: mapka)
    {
        
        mapka[i.first]=idx++;
    }

    for(int i=1;i<=n;i++)
    {
        arr[i]=mapka[arr[i]];
    }
}

bool sprawdzenie(int Mid) //gąsielnica "na sterydach" XD 
{
    vector<int>count(1000005,0);
    int Maks=0;

    for(int i=1;i<=Mid;i++)
    {
        count[arr[i]]++;
        Maks=max(Maks,count[arr[i]]);
    }

    if(Mid-Maks<=stole) return true;//odległość - maksXWystąpień <= extraMiejsca 

    for(int i=Mid+1;i<=n;i++)
    {
        count[arr[i]]++;
        count[arr[i-Mid]]--;

        if(Mid-count[arr[i]]<=stole) return true;
    }

    return false;
}

int main()
{
    //wczytywanie
    ios_base::sync_with_stdio(0);//magiczna linijka 

    cin>>n>>stole;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    //zamiana liczb z wielkich na małe
    mapowanie();

    //wyszukiwanie binarne po wyniku
    int l=0,r=n,ans;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(sprawdzenie(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<(l+r+1)/2<<"\n";
}