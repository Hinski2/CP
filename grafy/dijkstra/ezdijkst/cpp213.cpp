#include <bits/stdc++.h>
using namespace std;

const int mak = 10005;

void liczenie()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>>G[n + 1];
    vector<int>odl(n + 1, 0);
    vector<bool>odwiedzony(n + 1, false);
    
    for(int i = 1; i <= m; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;

        G[a].push_back({b, -s});
    }

    int a, b;
    cin >> a >> b;
    
    //dijkstra
    priority_queue<pair<int, int>>q;
    q.push({0, a});

    while(!q.empty())
    {
        int s = q.top().first;
        int v = q.top().second;
        q.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;
            odl[v] = -s;
            for(auto u: G[v])
            {
                if(!odwiedzony[u.first])
                {
                    q.push({s + u.second, u.first});
                }
            }
        }
    }

    if(odwiedzony[b])
    {
        cout << odl[b] << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        liczenie();
    }
}