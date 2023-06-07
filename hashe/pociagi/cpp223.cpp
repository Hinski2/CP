#include <bits/stdc++.h>
using namespace std;

const int max_pociagi = 1005;
const int max_wagony = 105;
const int max_zamiany = 1e5 + 5;

const int p = 37;
const int mod[]
{
    (long long)1e9 + 7,
    (long long)1e9 + 123
};

int power[max_wagony][2];
int hasz[max_pociagi][2];
map<pair<int, int>, unordered_set<int>>mapa;

int pociagi_liczba, wagony_liczba, zamiany_liczba;
char wagon[max_pociagi][max_wagony]; //pociąg, idx
int zamiany[max_zamiany][4];

int ans[max_pociagi];

void wczytanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> pociagi_liczba >> wagony_liczba >> zamiany_liczba;
    for(int i = 1; i <= pociagi_liczba; i++)
    {
        for(int j = 1; j <= wagony_liczba; j++)
        {
            cin >> wagon[i][j];
        }
    }

    for(int i = 1; i <= zamiany_liczba; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> zamiany[i][j];
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

void haszowanie_wstepne(int opt)
{
    for(int i = 1; i <= pociagi_liczba; i++)
    {
        hasz[i][opt] = wagon[i][1] - 'a' + 1;
        for(int j = 2; j < wagony_liczba; j++)
        {
            hasz[i][opt] = (hasz[i][opt] + 1LL * power[j - 1][opt] * (wagon[i][j] - 'a' + 1)) % mod[opt];
        }
    }
}

void mapowanie_wstepne()
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

void liczenie()
{
    for(int i = 1; i <= zamiany_liczba; i++)
    {
        int pociag1 = zamiany[i][0];
        int pociag2 = zamiany[i][2];
        int wagon1 = zamiany[i][1];
        int wagon2 = zamiany[i][3];

        //zamiana 1 pociągu
        auto it1 = mapa[{hasz[pociag1][0], hasz[pociag1][1]}].find(pociag1);
        mapa[{hasz[pociag1][0], hasz[pociag1][1]}].erase(it1);

        for(int opt = 0; opt < 2; opt++)
        {
            hasz[pociag1][opt] = (hasz[pociag1][opt] - ((1LL * power[wagon1 - 1][opt] * (wagon[pociag1][wagon1] - 'a' + 1)) % mod[opt]) + ((1LL * power[wagon1 - 1][opt] * (wagon[pociag2][wagon2] - 'a' + 1)) % mod[opt])) % mod[opt];
            if(hasz[pociag1][opt] < 0) hasz[pociag1][opt] += mod[opt];
        }

        mapa[{hasz[pociag1][0], hasz[pociag1][1]}].insert(pociag1);

        //zamiana 2 pociągu
        auto it2 = mapa[{hasz[pociag2][0], hasz[pociag2][1]}].find(pociag2);
        mapa[{hasz[pociag2][0], hasz[pociag2][1]}].erase(it2);

        for(int opt = 0; opt < 2; opt++)
        {
            hasz[pociag2][opt] = (hasz[pociag2][opt] - ((1LL * power[wagon2 - 1][opt] * (wagon[pociag2][wagon2] - 'a' + 1)) % mod[opt]) + ((1LL * power[wagon2 - 1][opt] * (wagon[pociag1][wagon1] - 'a' + 1)) % mod[opt])) % mod[opt];
            if(hasz[pociag2][opt] < 0) hasz[pociag2][opt] += mod[opt];
        }

        mapa[{hasz[pociag2][0], hasz[pociag2][1]}].insert(pociag2);

        swap(wagon[pociag1][wagon1], wagon[pociag2][wagon2]);

        //sprawdzenie czy wartość maksymala się nie zmieniła 
        //pociąg 1
        for(auto u: mapa[{hasz[pociag1][0], hasz[pociag1][1]}])
        {
            ans[u] = max(ans[u], (int)mapa[{hasz[pociag1][0], hasz[pociag1][1]}].size());
        }

        //pociąg 2
        for(auto u: mapa[{hasz[pociag2][0], hasz[pociag2][1]}])
        {
            ans[u] = max(ans[u], (int)mapa[{hasz[pociag2][0], hasz[pociag2][1]}].size());
        }
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
    //wczytywanie danych 
    wczytanie();

    //obliczenie potęg
    for(int i: {0, 1}) powerowanie(i);

    //wstępne haszowanie
    for(int i: {0, 1}) haszowanie_wstepne(i);

    //pierwsze wrzucenie waretości na mape
    mapowanie_wstepne();

    //normalne liczenie i zamienianie wagonów
    liczenie();

    //wypisywanie wyniku
    wypisanie();
}