#include<bits/stdc++.h>
using namespace std;

const int maksimum = 100015;
const int inf = 1e7 + 15;
int n, m;


vector<pair<int, int>>G[maksimum];

vector<int>dist(maksimum, inf);
vector<int>dist2(maksimum, inf);

int wynik;

void dijkstra()
{
    vector<int>odwiedzony(maksimum, false);
    priority_queue<pair<int, int>>p;

    p.push({0, 1});

    while(!p.empty())
    {
        int s = p.top().first;
        int v = p.top().second;

        p.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;

            dist[v] = -s;

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])
                {
                    p.push({s + u.first, u.second});
                }
            }
        }
    }
}

void dijkstra2()
{
    vector<int>odwiedzony(maksimum, false);
    priority_queue<pair<int, int>>p;

    p.push({0, n});

    while(!p.empty())
    {
        int s = p.top().first;
        int v = p.top().second;

        p.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;

            dist2[v] = -s;

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])
                {
                    p.push({s + u.first, u.second});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, odl;
        cin>>a>>b>>odl;

        G[a].push_back({-odl, b});
        G[b].push_back({-odl, a});
    }

    dijkstra();
    dijkstra2();

    wynik = dist[n];

    for(int i = 1; i <= n; i++)
    {
        if(dist[i] + dist2[i] == wynik)
        {
            cout<<i<<"\n";
        }
    }
}