#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;
int n, m;
int c = 1, color[mak];

vector<pair<int, int>>G[mak];
vector<pair<int, int>>OG[mak];
vector<pair<int, int>>CG[mak];
vector<int>kolejka;
vector<bool>odwiedzony(mak, false);

void dfs1(int v)
{
    odwiedzony[v] = true;
    for(auto u: G[v])
    {
        if(!odwiedzony[u.second])
        {
            dfs1(u.second);
        }
    }
    kolejka.push_back(v);
}

void dfs2(int v)
{
    color[v] = c;
    for(auto u: OG[v])
    {
        if(!color[u.second])
        {
            dfs2(u.second);
        }
    }
}

void wypisanie()
{
    for(int i = 1; i < c; i++)
    {
        cout<<i<<" ";
        for(auto u: CG[i])
        {
            cout<<"( "<<u.first<<" "<<u.second<<" ) ";
        }
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, s;
        cin>>a>>b>>s;
        G[a].push_back({-s, b});
        OG[b].push_back({-s, a});
    }

    for(int i = 1; i <= n; i++)
    {
        if(!odwiedzony[i])
        {
            dfs1(i);
        }
    }

    reverse(kolejka.begin(), kolejka.end());
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            dfs2(i);
            c++;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(auto u: G[i])
        {
            if(color[i] != color[u.second])
            {
                CG[color[i]].push_back({u.first, u.second});
            }
        }
    }

    wypisanie();
}