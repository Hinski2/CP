#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;

int n;
int ans;
pair<int, int>punkt[mak];

bool linked[mak];
priority_queue<pair<int, int>>dist;

void merge()
{
    linked[1] = true;
    for(int i = 2; i <= n; i++)
    {
        int odl = abs(punkt[1].first - punkt[i].first) + abs(punkt[1].second - punkt[i].second);
        dist.push({-odl, i});
    }

    while(!dist.empty())
    {
        int s = dist.top().first;
        int v = dist.top().second;

        dist.pop();

        if(!linked[v])
        {
            linked[v] = true;
            ans -= s;

            for(int i = 1; i <= n; i++)
            {
                if(i != v)
                {
                    int odl = abs(punkt[v].first - punkt[i].first) + abs(punkt[v].second - punkt[i].second);
                    dist.push({-odl, i});
                }
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin>>a>>b;

        punkt[i] = {a, b};
    }

    merge();

    cout << ans << endl;
}