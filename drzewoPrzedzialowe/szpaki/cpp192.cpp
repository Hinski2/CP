#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int base = 1 << 18;
vector<ll>tree(base << 1, 1);

int q, mod;

void naworzenie(int a, int b, int x)
{
    a += base;
    b += base;

    tree[a] = (tree[a] * x) % mod;
    if(a != b) tree[b] = (tree[b] * x) % mod;

    while(a >> 1 != b >> 1)
    {
        if(a % 2 == 0) tree[a + 1] = (tree[a + 1] * x) % mod;
        if(b % 2 == 1) tree[b - 1] = (tree[b - 1] * x) % mod;

        a >>= 1;
        b >>= 1;
    }
}

void sprawdzenie(int v)
{
    v += base;
    ll wynik = 1;

    while(v)
    {
        wynik = (wynik * tree[v]) % mod;
        v >>= 1;
    }

    if(wynik == 0) cout << "TAK\n";
    else cout << "NIE\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> q >> mod;
    while(q--)
    {
        char c;
        cin >> c;

        if(c == 'N')
        {
            int a, b, x;
            cin >> a >> b >> x;

            naworzenie(a, b, x);
        }
        else
        {
            int v;
            cin >> v;

            sprawdzenie(v);
        }
    }
}