#include <bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;

int n, m, t;
int preOrder[mak], colour[mak], idx = 0;
int dp[mak];

bool odwiedzony[mak];
vector<int>G[mak];

void orderowanie(int v, int p = -1)
{
    odwiedzony[v] = true;

    preOrder[v] = idx++;
    colour[v] = preOrder[v];

    for(auto u: G[v])
    {
        if(u != p)
        {
            if(odwiedzony[u])
            {
                colour[v] = min(colour[v], preOrder[u]);
            }
            else
            {
                orderowanie(u, v);
                colour[v] = min(colour[v], colour[u]);
            }
        }
    }
}

void czyszczenie()
{
    for(int i = 1; i <= n; i++)
    {
        odwiedzony[i] = false;
    } 
}

void dfs(int v, int p = 0)
{
    odwiedzony[v] = true;
    if(colour[v] != colour[p])
    {
        dp[v] = dp[p] + 1;
    }
    else
    {
        dp[v] = dp[p];
    }

    for(auto u: G[v])
    {
        if(!odwiedzony[u])
        {
            dfs(u, v);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin>>n>>m>>t;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //liczenie
    orderowanie(t);
    czyszczenie();
    dfs(t);

    //wypisywanie
    for(int i = 1; i <= n; i++)
    {
        cout<<dp[i]<<" ";
    }
}