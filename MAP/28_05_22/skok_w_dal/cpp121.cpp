#include <bits/stdc++.h>
using namespace std;

const int mak = 2e6 + 15;
const int base = 1 << 21;
const int m = 1 << 22;


int n;
long long dict[mak];
int tree[m + 15];


vector<pair<char, long long>>q;
vector<long long>liczby;

unordered_map<long long, int> mapa;

void mapowanie()
{
    int idx = 0;
    for(auto u: liczby)
    {
        mapa[u] = idx++;
    }

    for(auto u: mapa)
    {
        dict[u.second] = u.first;
    }
}

void dodaj(int x)
{
    x += base;
    tree[x]++;
    x /= 2;

    while(x)
    {
        tree[x] = tree[2 * x] + tree[2 * x + 1];
        x /= 2;
    }
}

void usun(int x)
{
    x += base;
    tree[x]--;
    x /= 2;

    while(x)
    {
        tree[x] = tree[2 * x] + tree[2 * x + 1];
        x /= 2;
    }
}

long long querry(int x)
{
    int idx = 1;
    while(idx < base)
    {
        if(tree[2 * idx] >= x)
        {
            idx *= 2;
        }
        else
        {
            idx = idx * 2 + 1;
            x -= tree[idx - 1];
        }
    }

    idx -= base;
    return dict[idx];
}
void liczenie()
{
    for(auto u: q)
    {
        if(u.first == 'A')
        {
            dodaj(mapa[u.second]);
        }
        else if(u.first == 'R')
        {
            usun(mapa[u.second]);
        }
        else
        {
            cout<<querry(u.second)<<"\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //*wczytywanie
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        char a;
        long long b;

        cin>>a>>b;

        if(a == 'A')
        {
            q.push_back({a, b});
            liczby.push_back(b);
        }
        else
        {
            q.push_back({a, b});
        }
    }

    //*liczenie
    sort(liczby.begin(), liczby.end(), greater<long long>());
    mapowanie();
    liczenie();
}