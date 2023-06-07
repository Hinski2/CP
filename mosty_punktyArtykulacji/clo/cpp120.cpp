#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, m;
int ans[mak];
int pre[mak], low[mak], idx = 1;

int v1, v2;
vector<int>G[mak];

void orderowanie(int v, int p = -1)
{
    pre[v] = idx++;
    low[v] = pre[v];

    for(auto u: G[v])
    {
        if(u != p)
        {
            if(pre[u])
            {
                low[v] = min(low[v], pre[u]);
            }
            else
            {
                orderowanie(u, v);
                low[v] = min(low[v], low[u]);
            }
        }
    }
    if(!v1)
    {
        if(pre[v] > low[v])
        {
            v1 = v;
        }
    }
    else if(!v2)
    {
        if(pre[v] > low[v])
        {
            v2 = v;
        }
    }
}

void dfs(int v, int p = -1)
{
    for(auto u: G[v])
    {
        if(!ans[u])
        {
            ans[u] = v;
            dfs(u, v);
        }        
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin>>n>>m;
    if(m < n) //nie może byc mniej dróg niż miast 
    {
        cout<<"NIE\n";
        return 0;
    }

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    //liczenie
    orderowanie(1);
    
    //usuwanie
    vector<int>::iterator position = find(G[v1].begin(), G[v1].end(), v2);
    if(position != G[v1].end())
    {
        G[v1].erase(position);
    }

    dfs(v1);
    ans[v1] = v2;
    //wypisanie wyniku
    cout<<"TAK\n";
    for(int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<"\n";
    }
}
