#include <bits/stdc++.h>
using namespace std;

const int mak = 305;

int n, m, counter;
int vi[] = {0, 1, 0, -1};
int vj[] = {-1, 0, 1, 0};

bool G[mak][mak];
bool visited[mak][mak];

void dfs(int i, int j)
{
    visited[i][j] = true;
    for(int k = 0; k < 4; k++)
    {
        if((i + vi[k] >= 1 && i + vi[k] <= n) && (j + vj[k] >= 1 && j + vj[k] <= m) && !visited[i + vi[k]][j + vj[k]] && G[i + vi[k]][j + vj[k]])
        {
            dfs(i + vi[k], j + vj[k]);
        }
    }
}

void liczenie()
{
   for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!visited[i][j])
            {
                visited[i][j] = true;

                if(G[i][j])
                {
                    dfs(i, j);
                    counter++;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>G[i][j];
        }
    }

    liczenie();

    cout<<counter<<"\n";
}
