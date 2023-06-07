#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, m;
int ans[mak];
int pre[mak], low[mak], idx = 1;

vector<int>G[mak];

int ile_spujnych;
bool find_v1, find_v2;
vector<int>v1;
vector<int>v2;

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
    if(!find_v1)
    {
        if(pre[v] > low[v])
        {
            v1.push_back(v);
            find_v1 = true;
        }
    }
    else if(!find_v2)
    {
        if(pre[v] > low[v])
        {
            v2.push_back(v);
            find_v2 = true;
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

void usuwanie()
{
    for(int i = 0; i < ile_spujnych; i++)
    {
        vector<int>::iterator position = find(G[v1[i]].begin(), G[v1[i]].end(), v2[i]);
        if(position != G[v1[i]].end())
        {
            G[v1[i]].erase(position);
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
    for(int i = 1; i <= n; i++) //orderowanie
    {
        if(!pre[i])
        {
            find_v1 = false;
            find_v2 = false;

            orderowanie(i);
            ile_spujnych++;
        }
    }
    if(v1.size() != ile_spujnych || v2.size() != ile_spujnych) //sprawdzanie
    {
        cout<<"NIE\n";
        return 0;
    }
    usuwanie(); //czyszczenie

    for(int i = 0; i < ile_spujnych; i++)
    {
        dfs(v1[i]);
        ans[v1[i]] = v2[i];
    }
    //wypisanie wyniku
    cout<<"TAK\n";
    for(int i = 1; i <= n; i++)
    {
        cout<<ans[i]<<"\n";
    }
}
