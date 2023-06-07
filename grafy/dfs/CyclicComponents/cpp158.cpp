#include <bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;

int n, m;
int color[mak], c = 1;
int ans;

bool znaleziony, liczba;

vector<int>G[mak];

void dfs(int v, int p = -1)
{
    color[v] = c;
    if(G[v].size() != 2) liczba = false;

    for(auto u: G[v])
    {
        if(!color[u])
        {
            dfs(u, v);
        }
        else if(u != p)
        {
            znaleziony = true;
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

    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            liczba = true;
            znaleziony = false;

            dfs(i);

            c++;
            if(znaleziony = true && liczba == true) ans++;
        }
    }

    cout<<ans<<"\n";
}