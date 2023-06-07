#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, liczbaDni, pamieta;
int conajmniej[mak], lvl[mak];
int ans[mak];

vector<pair<int, int>>G[mak];

void sortowanie_topologiczne()
{
    queue<int>q;

    for(int i = 1; i <= n; i++)
    {
        if(lvl[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto u: G[v])
        {
            ans[u.first] = max(ans[u.first], ans[v] + u.second);

            lvl[u.first]--;
            if(lvl[u.first] == 0) q.push(u.first);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    //wczytywanie
    cin >> n >> liczbaDni >> pamieta;
    for(int i = 1; i <= n; i++)
    {
        cin >> conajmniej[i];
        ans[i] = conajmniej[i];
    }

    for(int i = 1; i <= pamieta; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;

        G[a].push_back({b, s});
        lvl[b]++;
    }

    //liczenie
    sortowanie_topologiczne();

    //wypisanie wyniku
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << "\n";
    }

}