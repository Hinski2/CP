#include <bits/stdc++.h>
using namespace std;

int n, k;
unordered_map<long long, long long>mapa;

void wczytanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        bitset<13>b;
        cin >> b;

        mapa[b.to_ulong()]++;
    }
}

long long policzenie()
{
    long long wynik = 0;
    unordered_map<long long, long long>::iterator u;

    for(u = mapa.begin(); u != mapa.end(); u++)
    {
        unordered_map<long long, long long>::iterator w = u;

        while(++w != mapa.end())
        {
            if(u -> first & w -> first)
            {
                wynik += (long long)u -> second * w -> second; 
            }
        }
    }

    for(u = mapa.begin(); u != mapa.end(); u++)
    {
        if(u -> first) wynik += (long long)(u -> second * (u -> second - 1)) / 2;
    }

    return wynik;
}

int main()
{
    wczytanie();
    cout << policzenie() << "\n";
}