#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

const long long mod = 1e9 + 7;
const long long mak = 5005;

ll factorial[mak] = {1};
ll inverse_factorial[mak] = {1};

ll power(ll i, ll x)
{
    ll wynik = 1;

    while(x > 0)
    {
        if(x % 2 == 1)
        {
            wynik = (wynik * i) % mod;
        }

        i = (i * i) % mod;
        x /= 2;
    }

    return wynik;
}

ll modulo_inverse(ll x)
{
    return power(x, mod - 2);
}

void silowanie()
{
    for(ll i = 1; i <= 5000; i++)
    {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }

    for(ll i = 1; i <= 5000; i++)
    {
        inverse_factorial[i] = modulo_inverse(factorial[i]);
    }
}

void obliczanie(ll n, ll k)
{
    ll l1 = k / 2;
    ll l2 = (k - 1) / 2;

    ll w1 = (factorial[n - 2] * ((inverse_factorial[l1] * inverse_factorial[n - 2 - l1]) % mod)) % mod;
    ll w2 = (factorial[n - 2] * ((inverse_factorial[l2] * inverse_factorial[n - 2 - l2]) % mod)) % mod;

    ll wynik = (w1 * w2 * 2) % mod;

    cout << wynik << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //pre procesing
    silowanie();
    
    //wczytywanie i leczenie
    ll n, k;

    while(cin >> n >> k && n)
    {
        obliczanie(n, k);
    }
}