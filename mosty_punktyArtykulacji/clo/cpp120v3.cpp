#include <bits/stdc++.h>
using namespace std;

const int mak = 100005;

int n, m, akt;
int pocz, kon;
int ans[mak];

int visited[mak];
bool znal;

vector<int>G[mak];

void dfs(int v, int p)
{
    visited[v] = akt;
    for(auto u: G[v])
    {
        if(u != p)
        {
            if(visited[u] == akt)
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
        if(ans[i] == 0)
        {
            znal = false;
            akt++;
            dfs(i, i);

            if(!znal)
            {
                cout<<"NIE\n";
                return 0;
            }
            else
            {   
                //usuwanie połaczenia
                for(int j = 0; j < G[pocz].size(); j++)
                {
                    if(G[pocz][j] == kon) swap(G[pocz][j], G[pocz].back());
                }
                for(int j = 0; j < G[kon].size(); j++)
                {
                    if(G[kon][j] == pocz) swap(G[kon][j], G[kon].back());
                }

                G[pocz].pop_back();
                G[kon].pop_back();

                ans[pocz] = kon;
                akt++;
                dfs(pocz, pocz);
            }
        }
    }
    cout<<"TAK\n";
    for(int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<"\n";
    }
}
