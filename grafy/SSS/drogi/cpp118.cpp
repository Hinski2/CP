#include <bits/stdc++.h>
using namespace std;

const int mak = 10015;

int n, m;
int color[mak], c = 1;
int In, o, IN[mak], OUT[mak];

bool odwiedzone[mak];

vector<int>G[mak];
vector<int>OG[mak];
vector<int>order;

void dfs1(int v)
{
    odwiedzone[v] = true;
    for(auto u: G[v])
    {
        if(!odwiedzone[u])
        {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v)
{
    color[v] = c;
    for(auto u: OG[v])
    {
        if(!color[u])
        {
            dfs2(u);
        }
    }
}

void sss()
{   
    //tworzenie kolejności 
    for(int i = 1; i <= n; i++)
    {
        if(!odwiedzone[i])
        {
            dfs1(i);
        }
    }

    //odwracanie kolejności 
    reverse(order.begin(), order.end());

    //kolorowanie
    for(auto u: order)
    {
        if(!color[u])
        {
            dfs2(u);
            c++;
        }
    }
}

void stick()
{
    //łączenie
    for(int i = 1; i <= n; i++)
    {
        for(auto u: G[i])
        {
            if(color[i] != color[u])
            {
                OUT[color[i]]++;
                IN[color[u]]++;
            }
        }
    }

    //zliczanie zer
    for(int i = 1; i < c; i++)
    {
        if(OUT[i] == 0) o++;
        if(IN[i] == 0) In++;
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
        OG[b].push_back(a);
    }


    //liczenie
    sss();
    stick();

    //wypisywanie wyniku
    if(c == 2)
    {
        cout<<"0\n";
    }
    else
    {
        cout<<(In > o ? In : o )<<"\n";
    }
}
