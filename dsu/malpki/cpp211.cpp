#include <bits/stdc++.h>
using namespace std;

const int nak = 4e5 + 15;
const int mak = 2e5 + 15;

int n, m;
int naZiemi[mak];

pair<int, int>node[mak];

vector<int>G[mak];

int r[mak];
vector<int>zbior[mak];

void ustawienie()
{
    for(int i = 1; i <= n; i++)
    {
        r[i] = i;
        zbior[i].push_back(i);
        naZiemi[i] = -1;

        for(int j = 1; j <= 3; j++) G[i].push_back(0);
    }
}

void join(int a, int b, int nr)
{
    if(r[a] == r[b]) return;
    if(zbior[r[a]].size() < zbior[r[b]].size()) swap(a, b);

    if(r[a] == r[1])
    {
        for(auto u: zbior[r[b]])
        {
            naZiemi[u] = nr;
            zbior[r[a]].push_back(u);
            r[u] = r[a];
        }
    }
    else if(r[b] == r[1])
    {
        for(auto u: zbior[r[a]])
        {
            naZiemi[u] = nr;
        }

        for(auto u: zbior[r[b]])
        {
            zbior[r[a]].push_back(u);
            r[u] = r[a];
        }
    }
    else
    {
        for(auto u: zbior[r[b]])
        {
            zbior[r[a]].push_back(u);
            r[u] = r[a];
        }
    }
}

void oblicz(int v, int p = -1)
{
    for(auto u: G[v])
    {
        if(u && u != p)
        {
            if(naZiemi[v] == -1)
            {
                oblicz(u, v);
            }
            else
            {
                if(naZiemi[u] == -1) naZiemi[u] = naZiemi[v];
                else naZiemi[u] = min(naZiemi[u], naZiemi[v]);

                oblicz(u, v);
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytytwanie
    cin >> n >> m;
    ustawienie();

    for(int i = 1; i <= n; i++)
    {
        cin >> G[i][1] >> G[i][2];
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        node[i] = {a, b};
    }

    //licznie
    for(int i = m - 1; i >= 0; i--)
    {
        int a = node[i].first;
        int b = G[a][node[i].second];

        join(a, b, i);
    }

    oblicz(1);

    //wynikowanie
    for(int i = 1; i <= n; i++)
    {
        cout << naZiemi[i] << "\n";
    }
}