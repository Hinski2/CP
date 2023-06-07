#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

struct edge
{
    int u;
    int nr;
    bool dir;
};

int n, m;
int color[mak], c = 1;
bool ans[mak];

bool odwiedzony[mak], przejscie[mak];

vector<edge>G[mak];
vector<edge>DG[mak];
vector<edge>DOG[mak];

vector<int>kolejka;

void dfs1(int v, int peid = -1) 
{
    odwiedzony[v] = true;
    for(auto e: G[v])
    {
        if(e.nr != peid)
        {
            if(!przejscie[e.nr])
            {   
                przejscie[e.nr] = true;
                DG[v].push_back({e.u, e.nr, e.dir});
                DOG[e.u].push_back({v, e.nr, e.dir});
            }
            if(!odwiedzony[e.u])
            {
                dfs1(e.u, e.nr);
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

void dfs2(int v)
{
    odwiedzony[v] = true;
    for(auto e: DG[v])
    {
        if(!odwiedzony[e.u]) dfs2(e.u);
    }
    kolejka.push_back(v);
}

void dfs3(int v)
{
    color[v] = c;
    for(auto e: DOG[v])
    {
        if(!color[e.u]) dfs3(e.u);
    }
}
void sss()
{           
    czyszczenie();                  //czyszczenie tablicy odwiedzin
    for(int i = 1; i <= n; i++)     //pierwszy dfs
    {
        if(!odwiedzony[i])
        {
            dfs2(i);
        }
    }

    reverse(kolejka.begin(), kolejka.end());    //obracanie postordera

    for(auto u: kolejka)
    {
        if(!color[u])
        {
            dfs3(u);
            c++;
        }
    }
}

void anser()
{
    for(int i = 1; i <= n; i++)
    {
        for(auto e: DG[i])
        {
            ans[e.nr] = e.dir;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back({b, i, 0});
        G[b].push_back({a, i, 1});
    }

    //*liczenie
    //kierowanie
    for(int i = 1; i <= n; i++)
    {
        if(!odwiedzony[i]) dfs1(i);
    }
    //sss
    sss();
    //tworzenie tablicy ans
    anser();

    //*wypisywanie odpowiedzi
    cout<<c - 1<<"\n";
    for(int i = 1; i <= m; i++)
    {
        cout<<(ans[i] ? "<" : ">");
    }
}
