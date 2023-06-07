#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mak = 5015;
const int inf = 1e9 + 7; 

int n, m;
int cena_metalu[mak];
int cena_zamiany[mak], cena_odmiamy[mak];

vector<pair<int, int>>G[mak];
vector<pair<int, int>>Gt[mak];

void wczytywanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> cena_metalu[i];
    }

    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;

        G[a].push_back({b, -s});
        Gt[b].push_back({a, -s});
    }

    for(int i = 1; i <= n; i++)
    {
        cena_zamiany[i] = inf;
        cena_odmiamy[i] = inf;
    }
}

void liczenie_zamiany()
{
    priority_queue<pair<int, int>>q;
    vector<bool>odwiedzony(mak, false);

    q.push({0, 1});
    while(!q.empty())
    {
        int s = q.top().first;
        int v = q.top().second;
        q.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;
            cena_zamiany[v] = -s;

            for(auto u: G[v])
            {
                if(!odwiedzony[u.first])
                {
                    q.push({s + u.second, u.first});
                }
            }
        }
    }
}

void liczenie_odmiany()
{
    priority_queue<pair<int, int>>q;
    vector<bool>odwiedzony(mak, false);

    q.push({0, 1});
    while(!q.empty())
    {
        int s = q.top().first;
        int v = q.top().second;
        q.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;
            cena_odmiamy[v] = -s;

            for(auto u: Gt[v])
            {
                if(!odwiedzony[u.first])
                {
                    q.push({s + u.second, u.first});
                }
            }
        }
    }
}

ll wyznaczenie_wyniku()
{
    ll wynik = inf;
    for(int i = 1; i <= n; i++)
    {
        ll porownanie = 1LL * cena_zamiany[i] + cena_odmiamy[i] + (cena_metalu[i] / 2);
        wynik = min(wynik, porownanie);
    }

    return wynik;
}

int main()
{
    wczytywanie();
    liczenie_zamiany();
    liczenie_odmiany();
    cout << wyznaczenie_wyniku() << "\n";
}