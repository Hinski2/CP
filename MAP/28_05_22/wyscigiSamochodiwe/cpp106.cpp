#include <bits/stdc++.h>
using namespace std;

const int maks = 1e6 + 15;
const int inf = 1e9 + 15;

int n, w;
int wynik[maks], wynik2[maks];

vector<pair<int, int>>G[maks];

void dijkstra1()
{
    priority_queue<pair<int, int>>q;
    vector<int>odwiedzony(maks, false);

    q.push({0, 1});
    while(!q.empty())
    {
        int s = q.top().first;
        int v = q.top().second;
        q.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;
            wynik[v] = s;

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])
                {
                    q.push({u.first + s, u.second});
                }
            }
        }
    }
}

void dijkstra2()
{
    priority_queue<pair<int, int>>q;
    vector<int>odwiedzony(maks, false);

    q.push({0, 2});
    while(!q.empty())
    {
        int s = q.top().first;
        int v = q.top().second;
        q.pop();

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;
            wynik2[v] = s;

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])
                {
                    q.push({u.first + s, u.second});
                }
            }
        }
    }
}

void zapytanie(int a, int b)
{
    int k1 = max(wynik[2 * b - 1], wynik[2 * b]);
    int k2 = max(wynik2[2 * b - 1], wynik2[2 * b]);
    int s1 = max(wynik[2 * a - 1], wynik[2 * a]);
    int s2 = max(wynik2[2 * a - 1], wynik2[2 * a]);

    int ans = max(k1 - s1, k2 - s2);
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>w;

    for(int i = 1; i < n; i++)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        G[2 * i - 1].push_back({a, 2 * i + 1});
        G[2 * i - 1].push_back({b, 2 * i + 2});
        G[2 * i].push_back({c, 2 * i + 1}); 
        G[2 * i].push_back({d, 2 * i + 2}); 
    }
    
    //liczenie odległości 
    dijkstra1();
    dijkstra2();

    //odpowiadanie na zapytania
    while(w--)
    {
        int a, b;
        cin>>a>>b;

        zapytanie(a, b);
    }
}