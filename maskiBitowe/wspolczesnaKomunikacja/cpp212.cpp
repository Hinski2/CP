#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll wynik;

unordered_map<bitset<13>, int>mapa;

void wczytywanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        bitset<13>x;
        cin >> x;
        mapa[x]++;
    }
}

void liczenie()
{   
    // it1 = mapa.begin();
    // for(; it1 != mapa.end(); it1++)
    // {
    //     unordered_map<bitset<13>, int>::iterator it2 = it1;
    //     it2++;

    //     for(; it2 != mapa.end(); it2++)
    //     {
    //         if((it1 -> first) & (it2 -> first))
    //         {
    //             wynik += (1LL * (it1 -> second) * ((it1 -> second) + 1)) / 2;
    //         }
    //     }
    // }

    for(auto u: mapa)
    {
        for(auto w: mapa)
        {
            if(u.first != w.first)
            {
                if(u.first.to_ulong() & w.first.to_ulong())
                {
                    wynik += (1LL * u.second * (w.second + 1)) / 2;
                }
            }
        }
    }

    wynik /= 2;
}

int main()
{
    wczytywanie();
    liczenie();
    cout << wynik << "\n"; 
}