#include<bits/stdc++.h>
using namespace std;

const int maksimum = 10015;
const int infinity = 1e7;

int n, m;

int dijkstra()
{
    priority_queue<pair<int, int>>p;
    vector<pair<int, int>>G[maksimum];

    vector<int>dist(n + 1, infinity); 
    vector<int>odwiedzony(n + 1, false);

    for(int i = 1; i <= m; i++)
    {
        int a, b, odl;
        cin>>a>>b>>odl;
        G[a].push_back({-odl, b});
    }


    int a, b;
    cin>>a>>b;

    //liczenie
    p.push({0, a}); //zerowy dystans do a

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

    return dist[b] == infinity? 0 : dist[b];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ile;
    cin>>ile;
    while(ile--)
    {
        cin>>n>>m;
        int d = dijkstra();

        if(d)
        {
            cout<<d<<"\n";
        }
        else
        {
            cout<<"NIE\n";
        }
    }
}