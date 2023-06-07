#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, m;
int lvl[mak], dp[mak];

vector<int>G[mak];
vector<int>order;

void sortowanie_topologiczne()
{
    queue<int>q;
    for(int i = 1; i <= n; i++)
    {
        if(!lvl[i])
        {
            q.push(i);
            order.push_back(i);
        }
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto u: G[v])
        {
            lvl[u]--;
            if(!lvl[u])
            {
                q.push(u);
                order.push_back(u);
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        lvl[b]++;
    }

    //liczenie
    sortowanie_topologiczne();

    //dp'owanie
    for(auto v: order)
    {
        for(auto u: G[v])
        {
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }

    //szukanie wyniku
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);

    //wypisanie wyniku
    cout << ans << "\n";
}