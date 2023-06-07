#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mak = 6e5 + 15;

int n;

ll podziel(vector<ll> &v, ll l, ll r)
{
    ll pivot = v[(l + r) / 2];
    ll a = l - 1;
    ll b = r + 1;

    while(true)
    {
        while(v[++a] < pivot);
        while(v[--b] > pivot);

        if(a >= b) break;

        swap(v[a], v[b]);
    }

    return b;
}

void sortowanie(vector<ll> &v, ll l, ll r)
{
    if(l >= r) return;

    ll mid = podziel(v, l, r);
    sortowanie(v, l, mid);
    sortowanie(v, mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    vector<ll>v;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sortowanie(v, 0, n - 1);

    for(auto u: v)
    {
        cout << u << " ";
    }
    cout << "\n";
}



