#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n, m, idx = 1;
int preOrder[mak], low[mak];

bool odwiedzony[mak];
vector<int>G[mak];

void orderowanie(int v, int p = -1)
{
    odwiedzony[v] = true;

    preOrder[v] = idx++;
    low[v] = preOrder[v];

    for(auto u: G[v])
    {
        if(u != p)
        {
            if(odwiedzony[u])
            {
                low[v] = min(low[v], preOrder[u]);
            }
            else
            {
                orderowanie(u, v);
                low[v] = min(low[v], low[u]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //liczenie
    for(int i = 1; i <= n; i++)
    {
        if(!odwiedzony[i])
        {
            orderowanie(i);
        }
    }

    //wypisywanie
    for(int i = 1; i <= n; i++)
    {
        cout<<i<<" "<<preOrder[i]<<" "<<low[i]<<endl;
    }
}
