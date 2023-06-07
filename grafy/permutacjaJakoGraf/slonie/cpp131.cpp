#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n;
int masa[mak], arr1[mak], arr2[mak];
int Minimum, Rozmiar, total_min = INT_MAX;
int wsk[mak];

long long ans, Masa_calkowita;

bool odwiedzony[mak];

void dfs(int v)
{
    odwiedzony[v] = true;
    Minimum = min(Minimum, masa[v]);
    Rozmiar++;
    Masa_calkowita += masa[v];
    
    if(!odwiedzony[wsk[v]])
    {
       dfs(wsk[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>masa[i];
        total_min = min(total_min, masa[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        cin>>arr1[i];
    }

    for(int i = 1;i <= n; i++)
    {
        cin>>arr2[i];
    }

    //tworzenie grafu
    for(int i = 1; i <= n; i++)
    {
        wsk[arr1[i]] = arr2[i];
    }

    //*liczenie
    for(int i = 1; i <= n; i++)
    {
        Minimum = INT_MAX;
        Masa_calkowita = 0;
        Rozmiar = 0;

        if(!odwiedzony[i])
        {
            dfs(i);
            if(Rozmiar != 1)
            {
                long long opcja1 = 1LL * (Masa_calkowita - Minimum) + 1LL * ((Rozmiar - 1) * Minimum);
                long long opcja2 = 1LL * (Minimum + total_min) + 1LL * (Rozmiar * total_min + Masa_calkowita);
                ans += min(opcja1, opcja2);
            }
        }
    }

    cout<<ans<<"\n";
}