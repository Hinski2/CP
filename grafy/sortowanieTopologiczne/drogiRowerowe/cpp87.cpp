#include <bits/stdc++.h>
using namespace std;

const int maksimum = 50015;

int n, m;
int c[maksimum];
int deg[maksimum];
int cSss[maksimum];
int cPaths[maksimum];

vector<int> v[maksimum];
vector<int> ov[maksimum];
vector<int> order;

set<int>SSS[maksimum];


void dfs(int f)
{
    c[f] = true;

    for(int u: v[f])
    {
        if(!c[u])
        {
            dfs(u);
        }
    }

    order.push_back(f); //odwrucona kolejność 
}

void sss(int f, int id)
{
    c[f] = id;
    cSss[id]++;

    for(int u: ov[f])
    {
        if(!c[u])
        {
            sss(u, id);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //magiczna linikja 

    //wczytywanie danych 
    cin>>n>>m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);  //zwykły vector
        ov[b].push_back(a); //vector z odwróconymi drogami
    }

    for(int i = 1; i <= n; i++)
    {
        if(!c[i])
        {
            dfs(i);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        c[i] = 0;
    }

    int idx = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(!c[order[i]])
        {
            sss(order[i], ++idx);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int u: v[i])
        {
            if(c[i] != c[u])
            {
                if(SSS[c[u]].count(c[i]) == 0)
                {
                    SSS[c[u]].insert(c[i]);
                    deg[c[i]]++;
                }
            }
        }
    }

    queue<int>q;

    for(int i = 1; i <= idx; i++)
    {
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty())
    {
        int f = q.front();
        q.pop();

        for(int u: SSS[f])
        {
            deg[u]--;
            cPaths[u] += cPaths[f] + cSss[f];

            if(deg[u] == 0) q.push(u); 
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout<<cSss[c[i]] + cPaths[c[i]] - 1<<"\n";
    }
}