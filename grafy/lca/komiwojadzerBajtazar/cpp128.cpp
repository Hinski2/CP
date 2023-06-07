#include <bits/stdc++.h>
using namespace std;

const int mak = 30015;
const int LOG  =  15;

int n, m;
int up[mak][LOG], dist[mak], lca_dist;

int odl;

vector<int>G[mak];

void dp(int v)
{
    for(int i = 1; i < LOG; i++)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
}

void dfs(int v, int p = 0)
{
    up[v][0] = p;
    dp(v);

    for(auto u: G[v])
    {
        if(u != p)
        {
            dist[u] = dist[v] + 1;
            dfs(u, v);
        }
    }
}

int lca(int a, int b)
{
    if(dist[a] < dist[b]) swap(a, b);

    //sprowadzanie na ten sam poziom
    int k = dist[a] - dist[b];
    for(int i = LOG - 1; i >=0; i--)
    {
        if(k & (1 << i)) a = up[a][i];
    }

    if(a == b)return dist[a];

    for(int i = LOG - 1; i >= 0; i--)
    {
        if(up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        } 
    }
    return dist[up[a][0]];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie 
    cin>>n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //*liczenie
    dfs(1);

    //wczytywanie zapytań
    cin>>m;
    int a = 1, b = 1;

    while(m--)
    {
        a = b;
        cin>>b;

        lca_dist = lca(a, b);

        odl += dist[a] + dist[b] - 2 * lca_dist;
    }

    //wypisanie rozwiazania
    cout<<odl<<"\n";
}