#include <bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;
const int mod[]
{
    (long long)1e9 + 7,
    (long long)1e9 + 9,
};

int n;
int arr[mak];

int p = 2e5 + 3, power[mak][2];

int hsh_l[mak][2];
int hsh_r[mak][2];

int wynik[mak];
int najwiekszy_wynik;

void wczytywanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}

void powerowanie(int opt)
{
    power[0][opt] = 1;
    for(int i = 1; i < mak; i++)
    {
        power[i][opt] = (1LL * power[i - 1][opt] * p) % mod[opt];
    }
}

void haszowanie_od_lewej(int opt)
{
    hsh_l[1][opt] = arr[1];
    for(int i = 2; i <= n; i++)
    {
        hsh_l[i][opt] = (1LL * hsh_l[i - 1][opt] * p + arr[i]) % mod[opt];
    }
}

void haszowanie_od_prawej(int opt)
{
    hsh_r[n][opt] = arr[n];
    for(int i = n - 1; i >= 1; i--)
    {
        hsh_r[i][opt] = (1LL * hsh_r[i + 1][opt] * p + arr[i]) % mod[opt];
    }
}

void liczenie(int k)
{
    set<pair<int, int>>s;
    set<pair<int, int>>::iterator it1, it2;

    for(int i = 1; i + k - 1 <= n; i += k)
    {   
        //robienie lewych haszy
        int haszLewy[]
        {
            (int)(hsh_l[i + k - 1][0] - ((1LL * hsh_l[i - 1][0] * power[k][0]) % mod[0])),
            (int)(hsh_l[i + k - 1][1] - ((1LL * hsh_l[i - 1][1] * power[k][1]) % mod[1]))
        };

        for(int j: {0, 1})
        {
            if(haszLewy[j] < 0) haszLewy[j] += mod[j];
        }

        //robienie prawych haszy
        int haszPrawy[]
        {
            (int)(hsh_r[i][0] - ((1LL * hsh_r[i + k][0] * power[k][0]) % mod[0])),
            (int)(hsh_r[i][1] - ((1LL * hsh_r[i + k][1] * power[k][1]) % mod[1]))
        };

        for(int j: {0, 1})
        {
            if(haszPrawy[j] < 0) haszPrawy[j] += mod[j];
        }

        //sprawdzanie
        it1 = s.find({haszLewy[0], haszLewy[1]});
        it2 = s.find({haszPrawy[0], haszPrawy[1]});

        if(it1 == s.end() && it2 == s.end())
        {
            wynik[k]++;
            s.insert({haszLewy[0], haszLewy[1]});
            s.insert({haszPrawy[0], haszPrawy[1]});
        }
    }

    najwiekszy_wynik = max(najwiekszy_wynik, wynik[k]);
}

void wypisanie()
{
    vector<int>ans;
    for(int i = 1; i <= n; i++)
    {
        if(najwiekszy_wynik == wynik[i]) ans.push_back(i);
    }

    cout << najwiekszy_wynik << " " << ans.size() << "\n";
    for(auto u: ans) cout << u << " ";
    cout << "\n";
}

int main()
{
    //wczytywanie
    wczytywanie();

    //obliczanie potęg
    for(int i: {0, 1}) powerowanie(i);

    //haszowanie 
    for(int i: {0, 1}) haszowanie_od_lewej(i);
    for(int i: {0, 1}) haszowanie_od_prawej(i);

    //liczenie
    for(int k = 1; k <= n; k++)
    {
        liczenie(k);
    }

    //wypisanie wyniku
    wypisanie();
}