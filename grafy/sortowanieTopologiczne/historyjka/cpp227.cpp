#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;
const int mak = 1e6 + 5;

int n, m;
int poczatek, koniec;

int lvl[mak];
vector<int>G[mak];

int dp[mak];
vector<int>order;

void wczytanie()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> poczatek >> koniec;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        lvl[b]++;
        G[a].push_back(b);
    }
}

void sortowanie_topologiczne()
{
    queue<int>q;

    for(int i = 1; i <= n; i++)
    {
        if(lvl[i] == 0)
        {
            q.push(i);
            order.push_back(i);
        }
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto u: G[v])
        {
            lvl[u]--;
            if(lvl[u] == 0)
            {
                q.push(u);
                order.push_back(u);
            }
        }
    }
}

void liczenie()
{
    dp[poczatek]++;
    for(auto u: order)
    {
        for(auto w: G[u])
        {
            dp[w] = (dp[w] + dp[u]) % mod;
        }
    }
}

void wypisanie()
{
    cout << dp[koniec] << "\n";
}

int main()
{
    wczytanie();
    sortowanie_topologiczne();
    liczenie();
    wypisanie();
}