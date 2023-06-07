#include <bits/stdc++.h>
using namespace std;

const int mak = 5e5 + 15;

int n, m;

vector<int>G[mak];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin>>a>>b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(G[i].size() == 0) cout<<"Wiewior sam!\n";
        else
        {
            sort(G[i].begin(), G[i].end());

            for(auto u: G[i])
            {
                cout<<u<<" ";
            }
            cout<<"\n";
        }
    }
}