#include <bits/stdc++.h>
using namespace std;

const int max_pociagi = 1005;
const int max_wagony = 105;
const int max_zamiany = 1e5 + 5;

const int p = 31;
const int mod[]
{
    (long long)1e9 + 7,
    (long long)1e9 + 9
};

int power[max_wagony][2];
int hasz[max_pociagi][2];

map<pair<int, int>, unordered_set<int>>mapa;

int pociagi_liczba, wagony_liczba, zamiany_liczba;
int wagon[max_pociagi][max_wagony]; //pociąg, idx

int ans[max_pociagi];

void wczytanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> pociagi_liczba >> wagony_liczba >> zamiany_liczba;
    for(int i = 1; i <= pociagi_liczba; i++)
    {
        for(int j = 1; j <= wagony_liczba; j++)
        {
            char x;
            cin >> x;

            wagon[i][j] = x - 'a' + 1;
        }
    }
}

void powerowanie(int opt)
{
    power[0][opt] = 1;
    for(int i = 1; i < max_wagony; i++)
    {
        power[i][opt] = (1LL * power[i - 1][opt] * p) % mod[opt];
    }
}

void haszowanie(int opt)
{   
    for(int i = 1; i <= pociagi_liczba; i++)
    {
        for(int j = 1; j <= wagony_liczba; j++)
        {
            hasz[i][opt] = (1LL * hasz[i][opt] + wagon[i][j] * power[j - 1][opt]) % mod[opt];
        }
    }
}

void mapowanie()
{
    for(int i = 1; i <= pociagi_liczba; i++)
    {
        mapa[{hasz[i][0], hasz[i][1]}].insert(i);
    }

    for(auto u: mapa)
    {
        for(auto w: u.second)
        {
            ans[w] = u.second.size();
        }
    }
}

void zamiana(int pociag_a, int wagon_a, int pociag_b, int wagon_b)
{
    int hasz0 = hasz[pociag_a][0]; 
    int hasz1 = hasz[pociag_a][1];

    auto it = mapa[{hasz0, hasz1}].find(pociag_a);
    mapa[{hasz0, hasz1}].erase(it);

    hasz0 = (hasz0 + ((1LL * power[wagon_a - 1][0] * (wagon_b - wagon_a)) % mod[0])) % mod[0];  
    hasz1 = (hasz1 + ((1LL * power[wagon_a - 1][1] * (wagon_b - wagon_a)) % mod[1])) % mod[1];

    if(hasz0 < 0) hasz0 += mod[0];  
    if(hasz1 < 0) hasz1 += mod[1];

    mapa[{hasz0, hasz1}].insert(pociag_a);  

    hasz[pociag_a][0] = hasz0;
    hasz[pociag_a][1] = hasz1;   
}

void liczenie()
{
    int pociag1, pociag2, wagon1, wagon2;
    cin >> pociag1 >> wagon1 >> pociag2 >> wagon2;

    zamiana(pociag1, wagon1, pociag2, wagon2);
    zamiana(pociag2, wagon2, pociag1, wagon1);

    swap(wagon[pociag1][wagon1], wagon[pociag2][wagon2]);

    for(auto u: mapa[{hasz[pociag1][0], hasz[pociag1][1]}])
    {
        ans[u] = max(ans[u], (int)mapa[{hasz[pociag1][0], hasz[pociag1][1]}].size());
    }

    for(auto u: mapa[{hasz[pociag2][0], hasz[pociag2][1]}])
    {
        ans[u] = max(ans[u], (int)mapa[{hasz[pociag2][0], hasz[pociag2][1]}].size());
    }
}

void wypisanie()
{
    for(int i = 1; i <= pociagi_liczba; i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    wczytanie();
    for(int i: {0, 1}) powerowanie(i);
    for(int i: {0, 1}) haszowanie(i);
    mapowanie();
    for(int i = 1; i <= zamiany_liczba; i++) liczenie();
    wypisanie();
}