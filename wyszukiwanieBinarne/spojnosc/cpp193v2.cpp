#include <bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;

int n, m;
int czas;

bool odwiedzony[mak];

vector<pair<int, int>>G[mak];
priority_queue<pair<int, int>>q;



void liczenie()
{
    int licznik = 1;
    int maks = 1;

    odwiedzony[1] = true;
    for(auto u: G[1])
    {
        q.push({u.first, u.second});
    }

    while(!q.empty())
    {
        int v = q.top().second;
        int s = q.top().first;

        q.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;
            maks = max(-s, maks);
            licznik++;

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])
                {
                    q.push({u.first, u.second});
                }
            }
        }
    }

    if(licznik != n) cout << "NIE ISTNIEJE\n";
    else cout << maks << "\n";
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

        G[a].push_back({-i, b});
        G[b].push_back({-i, a});
    }

    //liczenie
    if(n == 1)
    {
        cout << "0\n";
        return 0;
    }

    liczenie();
}