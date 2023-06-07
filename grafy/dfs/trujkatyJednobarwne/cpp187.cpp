#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;

int n, m;
bool ban[mak][mak];

long long wynik;

vector<int>Gr[mak];
vector<int>Gb[mak];

void dfs_red(int v, int Find, int steps_left, int p)
{
    if(steps_left == 1)
    {
        for(auto u: Gr[v])
        {
            if(u == Find && u != p) wynik++;
        }
    }

    else if(steps_left == 2)
    {
        for(auto u: Gr[v])
        {
            if(u != p)
            {
                dfs_red(u, Find, 1, v);
            }
        }
    }
}

void dfs_black(int v, int Find, int steps_left, int p)
{
    if(steps_left == 1)
    {
        for(auto u: Gb[v])
        {
            if(u == Find && u != p) wynik++;
        }
    }

    else if(steps_left == 2)
    {
        for(auto u: Gb[v])
        {
            if(u != p)
            {
                dfs_black(u, Find, 1, v);
            }
        }
    }
}

void szukanie()
{
    for(int i = 1; i <= n; i++)
    {
        for(auto u: Gr[i])
        {
            dfs_red(u, i, 2, i);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(auto u: Gb[i])
        {
            dfs_black(u, i, 2, i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> m;
    for(int i = 1; i <= m; i++) //red graph
    {
        int a, b;
        cin >> a >> b;

        Gr[a].push_back(b);
        Gr[b].push_back(a);

        ban[a][b] = true;
        ban[b][a] = true;
    }

    for(int i = 1; i <= n; i++) //black graph
    {
        for(int j = 1; j <= n; j++)
        {
            if(!ban[i][j] && i != j)
            {
                Gb[i].push_back(j);
            }
        }
    }

    //liczenie
    szukanie();

    //wypisywanie wyniku
    cout << (wynik / 6) << "\n"; 
}