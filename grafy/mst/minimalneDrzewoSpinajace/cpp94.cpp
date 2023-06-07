#include<bits/stdc++.h>
using namespace std;

const int maksimum = 1e6 + 15;
int ile;

vector<pair<int, int>>G[maksimum];

void oblicz()
{
    int n, m;
    char c;
    int ans = 0;

    priority_queue<pair<int, int>>q;

    vector<bool>odwiedzony(maksimum, false);

    cin>>c>>c>>n>>c>>c>>c>>m;

    for(int i = 0; i < m; i++)
    {
        int a, b, s;
        cin>>c>>a>>c>>b>>c>>s;
        G[a].push_back({-s, b});
        G[b].push_back({-s, a});
    }

    q.push({0, 1});

    while(!q.empty())
    {
        int s = q.top().first;
        int v = q.top().second;

        q.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;
            ans -= s;

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])
                {
                    q.push({u.first, u.second});
                }
            }
        }
    }
    cout<<ans<<"\n";
}

void czyszczenie()
{
    for(int i = 0; i < maksimum; i++)
    {
        G[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>ile;
    while(ile--)
    {
        oblicz();
        czyszczenie();
    }
}