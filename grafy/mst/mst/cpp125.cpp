#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6;
int n, m;

vector<pair<int, int>>G[mak];
vector<pair<int, int>>mG[mak];

priority_queue<pair<int, pair<int, int>>>q;

void mst()
{
    vector<bool>odwiedzony(mak, false);
    q.push({0, {1, 1}});

    while(!q.empty())
    {
        int s = q.top().first;
        int v = q.top().second.first;
        int od = q.top().second. second;
        q.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;

            mG[od].push_back({-s, v});
            mG[v].push_back({-s, od});

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])
                {
                    q.push({u.first, {u.second, v}});
                }
            } 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytanie
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, s;
        cin>>a>>b>>s;

        G[a].push_back({-s, b});
        G[b].push_back({-s, a});
    }

    //*liczenie
    mst();

    //usuwanie krawędzi z 1 od 1 dwukrotnie
    swap(mG[1][0], mG[1].back());
    mG[1].pop_back();
    swap(mG[1][1], mG[1].back());
    mG[1].pop_back();

    //*wypisanie
    for(int i = 1; i <= n; i++)
    {
        cout<<i;
        for(auto u: mG[i])
        {
            cout<<" "<<u.second;
        }
        cout<<endl;
    }
}