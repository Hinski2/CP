#include <bits/stdc++.h>
using namespace std;

struct zapytanie 
{
    int dest;
    int dist;
    int index;
};

const int maksimum = 5015;
const int infinity = 1e9 + 15;

int liczbaPortow, liczbaKrawedzi, liczbaOpowiesci;
int result[maksimum][2];

vector<int>vec[maksimum];
vector<zapytanie>q[maksimum];

bool ans[1000015];

void bfs(int v)
{
    for(int i = 1; i <= liczbaPortow; i++)
    {
        result[i][0] = result[i][1] = infinity;
    }

    queue<pair<int, int>>k;
    k.push({v, 0});
    result[v][0] = vec[v].size() > 0 ? 0 : infinity;

    while(!k.empty())
    {
        auto p = k.front();
        k.pop();

        for(auto u: vec[p.first])
        {
            if(result[u][(p.second + 1) % 2] == infinity)
            {
                k.push({u, p.second + 1});
                result[u][(p.second + 1) % 2] = p.second + 1;
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &liczbaPortow, &liczbaKrawedzi, &liczbaOpowiesci);

    //wczytywanie krawędzi
    for(int i = 1; i <= liczbaKrawedzi; i++)
    {
        int x, y;
        scanf("%d%d",&x, &y);
        
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    for(int i = 0; i < liczbaOpowiesci; i++)
    {
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        q[a].push_back({b, x, i});
    }

    for(int i = 1; i <= liczbaPortow; i++)  
    {
        if(q[i].empty()) continue;
        bfs(i);

        for(zapytanie j: q[i])
        {
            ans[j.index] = (result[j.dest][j.dist % 2] <= j.dist);
        }
    }

    for(int i = 0; i < liczbaOpowiesci; i++)
    {
        printf("%s\n", ans[i] ? "TAK" : "NIE");
    }
}