#include <bits/stdc++.h>
using namespace std;

const int maksimum = 1e6 + 15;
const int inf = 36500;

int liczbaDomkow, liczbaDrog;
int nax = -1;

vector<int>v[maksimum];
vector<int>inStack;
vector<int>deg;
vector<int>visited;
vector<int>ways;

void dfs(int f, int id)
{
    inStack[f] = true;
    visited[f]++;

    for(int u: v[f])
    {
        if(visited[u] < id)
        {
            dfs(u, id);
        }
        else if(inStack[u])
        {
            visited[u] = id + 1;
            nax = inf;
        }
    }
    inStack[f] = false;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>liczbaDomkow>>liczbaDrog;
    for(int i = 1; i <= liczbaDrog; i++)
    {
        int a, b;
        cin>>a>>b;

        v[b].push_back(a);
    }

    visited.assign(liczbaDomkow + 2, 0);
    inStack.assign(liczbaDomkow + 2, 0);

    int id = 1;

    dfs(liczbaDomkow + 1, 1);

    for(int i = 1; i <= liczbaDomkow + 1; i++)
    {
        if(visited[i] == 2)
        {
            dfs(i, 2);
        }
    }

    inStack.clear();
    inStack.shrink_to_fit(); //funkcja cudo 
    
    ways.assign(liczbaDomkow + 2, 0);

    for(int i = 1; i <= liczbaDomkow; i++)
    {
        if(visited[i] >= 2)
        {
            ways[i] = inf;
        }
        else if(visited[i] == 0)
        {
            ways[i] = -1;
        }
    }

    visited.clear();
    visited.shrink_to_fit();

    deg.assign(liczbaDomkow + 2, 0);

    for(int i = 1; i <= liczbaDomkow + 1; i++)
    {
        if(ways[i] == 0)
        {
            for(int u: v[i])
            {
                deg[u]++;
            }
        }
    }

    if(ways[liczbaDomkow + 1] != inf)
    {
        queue<int>q;

        q.push(liczbaDomkow + 1);
        ways[liczbaDomkow + 1] = 1;

        while(!q.empty())
        {
            int f = q.front();
            q.pop();

            for(int u: v[f])
            {
                ways[u] = min(inf, ways[u] + ways[f]);
                nax = max(nax, ways[u]);
                deg[u]--;

                if(deg[u] == 0) q.push(u);
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= liczbaDomkow; i++)
    {
        if(ways[i] >= nax)
        {
            ans++;
        }
    }

    if(nax != inf) cout<<nax<<"\n";
    else cout<<"zawsze\n";

    cout<<ans<<"\n";

    for(int i = 1; i <= liczbaDomkow; i++)
    {
        if(ways[i] >= nax)
        {
            cout<<i<<" ";
        }
    }
}