#include <bits/stdc++.h>
using namespace std;

const int mak = 2005;

int n;
int matrix[mak][mak];

bool visited[mak];
bool zgodnosc = true;

vector<pair<int, int>>G[mak];
vector<pair<int, int>>Gm[mak];

priority_queue<pair<int, pair<int, int>>>q;


bool valid_matrix()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                if(matrix[i][j] != 0)return 0;
                
            }
            else
            {
                if(matrix[i][j])
                {
                    G[i].push_back({-matrix[i][j], j});
                }
            }
        }
    }
    return true;
}

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

            Gm[od].push_back({-s, v});
            Gm[v].push_back({-s, od});

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])
                {
                    q.push({u.first, {u.second, v}});
                }
            } 
        }
    }

    //usuwanie krawędzi z 1 od 1 dwukrotnie
    swap(Gm[1][0], Gm[1].back());
    Gm[1].pop_back();
    swap(Gm[1][1], Gm[1].back());
    Gm[1].pop_back();

}

void dfs(int prime, int v, int dist, int p = -1)
{
    for(auto u: Gm[v])
    {
        if(u.second != p)
        {
            if(matrix[prime][u.second] != dist + u.first) zgodnosc = false;
            dfs(prime, u.second, dist + u.first, v);
        }
    }
}

void kolorowanie(int v)
{
    visited[v] = true;
    for(auto u: Gm[v])
    {
        if(!visited[u.second])
        {
            kolorowanie(u.second);
        }
    }
}

bool spojny()
{
    kolorowanie(1);
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i]) return false;
    }
    return true;
}

bool valid_graph()
{
    if(!spojny()) return false;
    for(int i = 1; i <= n; i++)
    {
        dfs(i, i, 0);
        if(!zgodnosc) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytanie
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    //*liczenie
    if(!valid_matrix())
    {
        cout<<"NO\n";
        return 0;
    }

    mst();

    if(!valid_graph())
    {
        cout<<"NO\n";
        return 0;
    }

    //wszystko się zgadza
    cout<<"YES\n";
}