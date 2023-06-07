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

int wzorzec_hsh;
int power[mak];
int pref[mak];

int wzorzec_len, tekst_len;
char wzorzec[mak], tekst[mak];
vector<bool>dobry(mak, true);


void wczytywanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> wzorzec_len >> tekst_len;
    for(int i = 0; i < wzorzec_len; i++)
    {
        cin >> wzorzec[i];
    }
    for(int i = 0; i < tekst_len; i++)
    {
        cin >> tekst[i];
    }
}

void wyznaczanie_poteg(int opt, int j)
{
    power[0] = 1;
    for(int i = 1; i < mak; i++)
    {
        power[i] = (1LL * power[i - 1] * j) % mod[opt];
    }
}

void haszowanie_wzorca(int opt, int j)
{
    wzorzec_hsh = (wzorzec[0] - 'a' + 1);
    for(int i = 1; i < wzorzec_len; i++)
    {
        wzorzec_hsh = (1LL *wzorzec_hsh * j + (wzorzec[i] - 'a' + 1)) % mod[opt];
    }
}

void haszowanie_tekstu(int opt, int j)
{
    pref[0] = tekst[0] - 'a' + 1;
    for(int i = 1; i < tekst_len; i++)
    {
        pref[i] = (1LL * pref[i - 1] * j + (tekst[i] - 'a' + 1)) % mod[opt];
    }
}

void liczenie(int opt)
{
    int l = wzorzec_len;
    for(int i = l; i < tekst_len; i++)
    {
        ll hsh = 1LL * pref[i] - ((1LL * pref[i - l] * power[l]) % mod[opt]);
        if(hsh < 0) hsh += mod[opt];
        if(hsh != wzorzec_hsh) dobry[i - l + 1] = false;
    }

    if(1LL * pref[l - 1] != wzorzec_hsh) dobry[0] = false;
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
    for(int i = 0; i < 4; i++)
    {
        wyznaczanie_poteg(i, 37);
        haszowanie_wzorca(i, 37);
        haszowanie_tekstu(i, 37);
        liczenie(i);
    }

    //wypisanie wyniku
    wypisanie();
}