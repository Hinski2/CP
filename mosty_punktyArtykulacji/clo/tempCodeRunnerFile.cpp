#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, m, akt;
int pocz, kon;
int ans[mak];

int visited[mak];
bool znal, rozwiazanie = true;

vector<int>G[mak];

void dfs(int v, int p = -1)
{
    visited[v] = akt;
    for(auto u: G[v])
    {
        if(visited[u] = akt)
        {
            pocz = v;
            kon = u;
            znal = true;
        }
        else
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
        if(!ans[i])
        {
            znal = false;
            akt++;
            dfs(i);

            if(!znal)
            {
                cout<<"NIE\n";
                return 0;
            }
            else
            {   
                //usuwanie połaczenia
                for(auto u: G[pocz])
                {
                    if(u == kon) swap(u, G[pocz].back());
                }
                for(auto u: G[kon])
                {
                    if(u == pocz) swap(u, G[kon].back());
                }
                G[pocz].pop_back();
                G[kon].pop_back();

                ans[pocz] = kon;
                akt++;
                dfs(pocz);
            }
        }
    }
    cout<<"TAK\n";
    for(int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<"\n";
    }
}
