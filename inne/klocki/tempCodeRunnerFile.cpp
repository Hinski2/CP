#include <bits/stdc++.h>
using namespace std;

int liczba_klockow;
int maksymalna_liczba_klockow;
int maksymalna_masa_pudelka;

bitset<1000 * 1000 + 1>b[12];
vector<int>liczby[13];
vector<int>klocki;

void wczytywanie()
{
    cin >> liczba_klockow >> maksymalna_liczba_klockow >> maksymalna_masa_pudelka;

    int x;
    for(int i = 1; i <= liczba_klockow; i++)
    {
        cin >> x;
        klocki.push_back(x);
    }

}

int liczenie()
{
    liczby[0].push_back(0);
    for(auto u: klocki)
    {
        for(int poziom = maksymalna_liczba_klockow - 1; poziom >= 0; poziom--)
        {
            vector<int>dodaj;

            for(auto w: liczby[poziom])
            {
                if(w + u > maksymalna_masa_pudelka) continue;
                if(!b[poziom + 1][w + u]) dodaj.push_back(w + u);
            }

            for(auto w: dodaj)
            {
                liczby[poziom + 1].push_back(w);
                b[poziom + 1][w] = 1;
            }
        }
    }

    int ans = 0;
    for(int poziom = 1; poziom <= maksymalna_liczba_klockow; poziom++)
    {
        for(auto u: liczby[poziom])
        {
            ans = max(ans, u);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    wczytywanie();
    cout << liczenie() << "\n";

}