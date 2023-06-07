#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 19;
const int mak = 250 * 1000 + 15;

int n, m;
int tree[base << 1];
int idx = 0, nr[mak], nrMax[mak]; 
int dist[mak];

vector<int>G[mak];

void orderowanie(int v, int p = -1)
{
    nr[v] = nrMax[v] = idx++;

    for(auto u: G[v])
    {
        if(u != p)
        {
            dist[u] = dist[v] + 1;

            orderowanie(u, v);
            nrMax[v] = max(nrMax[v], nrMax[u]);
        }
    }
}

void autostradowanie(int a, int b)
{
    a += base;
    b += base;

    tree[a]--;
    if(a != b) tree[b]--;

    while(a >> 1 != b >> 1)
    {
        if(a % 2 == 0) tree[a + 1]--;
        if(b % 2 == 1) tree[b - 1]--;

        a >>= 1;
        b >>= 1;
    }
}

int querry(int v)
{
    v += base;

    int ans = 0;
    while(v)
    {
        ans += tree[v];
        v >>= 1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin>>a>>b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    orderowanie(1);

    cin>>m;
    m += n - 1;

    while(m--)
    {
        char c;
        cin>>c;

        if(c == 'W')
        {
            int v;
            cin>>v;
            cout<<querry(nr[v]) + dist[v]<<endl;
        }
        else
        {
            int a, b;
            cin>>a>>b;
            autostradowanie(nr[b], nrMax[b]);
        }
    }

}