#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n, m;
int lvl[mak];

vector<int>G[mak];
list<int>ans;

void wczytanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        lvl[b]++;
        G[a].push_back(b);
    }
}

void sortowanie_topologiczne()
{
    queue<int>q;

    for(int i = 1; i <= n; i++)
    {
        if(lvl[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto u: G[v])
        {
            lvl[u]--;
            if(lvl[u] == 0)
            {
                q.push(u);
                ans.push_back(u);
            }
        }
    }
}

void wypisanie()
{
    for(auto u: ans)
    {
        cout << u << " ";
    }
}

int main()
{
    wczytanie();
    sortowanie_topologiczne();
    wypisanie();
}
