#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;
const int mak_p = 21;

int n, m, q;
int up[mak][mak_p];

vector<int>G[mak];

void dfs(int v, int p = 0)
{
    up[v][0] = p;

    for(auto u: G[v])
    {
        if(u != p)
        {
            dfs(u, v);
        }
    }
}

int zapytanie(int v, int ile)
{
    int node = v; 
    int idx = mak_p;

    for(int bit = (1 << mak_p); bit > 0; (bit >>= 1))
    {
        if(bit & ile)
        {
            node = up[node][idx];
        }
        idx--;
    }
    return node;
}


int main()
{
    //*wczytywanie
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        G[a].push_back(b);
        G[b].push_back(a);
    }

    //*liczenie
    dfs(1);
    for(int i = 1; i < mak_p; i++)
    {
        for(int v = 1; v <= n; v++)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
    }

    while(q--)
    {
        int quest_ile, quest_v;
        scanf("%d%d", &quest_v, &quest_ile);
        cout<<zapytanie(quest_v, quest_ile)<<"\n";
    }    
}

// 29 28 1
// 1 2
// 1 3
// 2 4
// 4 5 
// 4 6
// 4 7
// 5 8
// 5 9
// 6 10
// 7 11
// 8 12 
// 8 13
// 8 14
// 10 15
// 10 16
// 11 17
// 15 18
// 15 19
// 16 20
// 17 21
// 18 22
// 19 23
// 19 24
// 21 25
// 21 26
// 21 27 
// 23 28
// 26 29