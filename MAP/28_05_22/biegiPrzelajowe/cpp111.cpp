#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n, m, ile_stacji, ile_q;
long long odl[mak][2];

vector<pair<long long,int>>G[mak];
bool stacja[mak], odwiedzony[mak][2];
priority_queue<pair<pair<long long, int>, bool>>q;

void dijkstra()
{
    q.push({{(long long)0, 1}, stacja[1]});

    while(!q.empty())
    {
        long long s = q.top().first.first;
        int v = q.top().first.second;
        bool c = (q.top().second || stacja[v]);
        q.pop();

        if(!odwiedzony[v][c])
        {
            odwiedzony[v][c] = true;
            odl[v][c] = -s;

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second][c])
                {
                    q.push({{s + u.first, u.second}, c});
                }
            }
        }

    }
}

void zapytanie()
{
    int quest;
    cin>>quest;
    cout<<odl[quest][1]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m>>ile_stacji>>ile_q;

    for(int i = 0; i < ile_stacji; i++)
    {
        int x;
        cin>>x;
        stacja[x] = true;
        
    }

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        long long s;

        cin>>a>>b>>s;
        G[a].push_back({-s, b});
        G[b].push_back({-s, a});
    }

    dijkstra();
    while(ile_q--)
    {
        zapytanie();
    }
}
