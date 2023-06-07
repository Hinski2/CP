#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;
int n, m;
int dp[mak], lvl[mak];

vector<int>G[mak];
vector<int>T;

void sortowanie()
{
    queue<int>q;
    for(int i = 1; i <= n; i++)
    {
        if(lvl[i] == 0)
        {
            q.push(i);
            T.push_back(i);
        }
    }

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto u: G[v])
        {
            lvl[u]--;
            if(lvl[u] == 0)
            {
                q.push(u);
                T.push_back(u);
            }
        }
    }
}

void dynamik(int v)
{
    for(auto u: G[v])
    {
        if(dp[u] == 0)
        {
            dynamik(u);
        }
    }
    for(auto u: G[v])
    {
        dp[v] = max(dp[v], dp[u]);
    }
    dp[v]++;
}

void liczenie_odleglosci()
{
    for(int i = 0; i < n; i++)
    {
        if(dp[T[i]] == 0)
        {
            dynamik(T[i]);
        }
    }
}

void wypisywanie()
{
    for(auto u: T)
    {
        cout<<u<<" ";
    }
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<dp[T[i]]<<" ";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        lvl[b]++;
    }

    sortowanie();
    liczenie_odleglosci();

    wypisywanie();
    int ans = 0;
    for(auto u: T)
    {
        ans = max(ans, dp[T[u]]);
    }
    cout<<ans<<endl;
}