#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mak = 8e6 + 15;
const long long mod[]
{
    (long long)1e9 + 7,
    (long long)1e9 + 9,
    (long long)1e9 + 123,
    (long long)1e9 + 321
};

ll wzorzec_hsh[4];
ll power[mak][4];
ll pref[mak][4];

int wzorzec_len, tekst_len;
string wzorzec, tekst;
vector<bool>dobry(mak, true);


void wczytywanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> wzorzec_len >> tekst_len;
    cin >> wzorzec >> tekst;
}

void wyznaczanie_poteg(int opt, int j)
{
    power[0][opt] = 1;
    for(int i = 1; i < mak; i++)
    {
        power[i][opt] = (power[i - 1][opt] * j) % mod[opt];
    }
}

void haszowanie_wzorca(int opt, int j)
{
    wzorzec_hsh[opt] = (wzorzec[0] - 'a' + 1);
    for(int i = 1; i < wzorzec_len; i++)
    {
        wzorzec_hsh[opt] = (wzorzec_hsh[opt] * j + (wzorzec[i] - 'a' + 1)) % mod[opt];
    }
}

void haszowanie_tekstu(int opt, int j)
{
    pref[0][opt] = tekst[0] - 'a' + 1;
    for(int i = 1; i < tekst_len; i++)
    {
        pref[i][opt] = (pref[i - 1][opt] * j + (tekst[i] - 'a' + 1)) % mod[opt];
    }
}


void liczenie(int opt)
{
    int l = wzorzec_len;
    for(int i = l; i < tekst_len; i++)
    {
        ll hsh = pref[i][opt] - ((pref[i - l][opt] * power[l][opt]) % mod[opt]);
        if(hsh < 0) hsh += mod[opt];
        if(hsh != wzorzec_hsh[opt]) dobry[i - l + 1] = false;
    }

    if(1LL * pref[l - 1][opt] != wzorzec_hsh[opt]) dobry[0] = false;
}

void wypisanie()
{
    for(int i = 0; i <= tekst_len - wzorzec_len; i++)
    {
        if(dobry[i]) cout << i + 1 << "\n"; 
    }
}

int main()
{
    //wczytanie danych
    wczytywanie();

    //pre procesing
    for(int i = 0; i < 4; i++) wyznaczanie_poteg(i, 37);

    //haszowanie wzorca
    for(int i = 0; i < 4; i++) haszowanie_wzorca(i, 37);

    //haszowanie tekstu
    for(int i = 0; i < 4; i++) haszowanie_tekstu(i, 37);

    //wyznaczanie przedziałów
    for(int i = 0; i < 4; i++) liczenie(i);

    //wypisanie wyniku
    wypisanie();
}