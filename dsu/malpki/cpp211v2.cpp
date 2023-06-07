#include <bits/stdc++.h>
using namespace std;

const int nak = 2e5 + 15;
const int mak = 4e5 + 15;

int n, m;
int trzyma[nak][2];
int unconnect[mak][2];

int czas[nak];
vector<int>G[mak];

void wczytanie()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> trzyma[i][0] >> trzyma[i][1];

        if(trzyma[i][0] != -1) trzyma[i][0]--;
        if(trzyma[i][1] != -1) trzyma[i][1]--;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        unconnect[i][0] = trzyma[--a][--b];
        unconnect[i][1] = a;
        trzyma[a][b] = -1;
    }
}

void ustawienie()
{
    for(int i = 0; i < n; i++)
    {
        for(int j: {0, 1})
        {
            if(trzyma[i][j] != -1)
            {
                G[trzyma[i][j]].push_back(i);
                G[i].push_back(trzyma[i][j]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        czas[i] = -2;
    }
}

void dfs(int v, int t)
{
    if(czas[v] != -2) return;

    czas[v] = t;
    for(auto u: G[v])
    {
        dfs(u, t);
    }
}

void liczenie()
{
    dfs(0, -1);

    for(int i = m - 1; i >= 0; i--)
    {
        int a = unconnect[i][0];
        int b = unconnect[i][1];

        if(czas[a] == -2 && czas[b] != -2) dfs(a, i);
        else if(czas[b] == -2 && czas[a] != -2) dfs(b, i);

        G[a].push_back(b);
        G[b].push_back(a);
    }
}

void wypisanie()
{
    for(int i = 0; i < n; i++)
    {
        cout << czas[i] << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    wczytanie();
    ustawienie();
    liczenie();
    wypisanie();
}