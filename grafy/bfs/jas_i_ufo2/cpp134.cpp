#include <bits/stdc++.h>
using namespace std;

const int mak = 305;

int n, t;
int pole[mak][mak];
int visited[mak][mak];
int suma[mak][mak];

int vx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int vy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void liczenieSum(int c)
{
    for(int y = 1; y <= n; y++)
    {
        for(int x = 1; x <= n; x++)
        {
            if(pole[x][y] == c)
            {
                suma[x][y] = suma[x - 1][y] + suma[x][y - 1] - suma[x - 1][y - 1] + 1;
            }
            else
            {
                suma[x][y] = suma[x - 1][y] + suma[x][y - 1] - suma[x - 1][y - 1];
            }
        }
    }
}

int bfs(int _x, int _y, int c)
{
    int maks = 0;
    queue<pair<pair<int, int>, int>>q;

    q.push({{_x, _y}, 0});

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int s = q.front().second;

        q.pop();
        if(visited[x][y] != c)
        {
            visited[x][y] = c;
            maks = max(maks, s);

            for(int i = 1; i < 8; i++)
            {
                if((x + vx[i] <= n && x + vx[i] >= 1) && (y + vy[i] <= n && y + vy[i] >= 1) && visited[x + vx[i]][y + vy[i]] != c && pole[x + vx[i]][y + vy[i]] == c)
                {
                    q.push({{x + vx[i], y + vy[i]}, s + 1});
                }
            }
        }
    }
    
    return maks;
}

bool liczenie(int c)
{
    for(int y = 1; y <= n; y++)
    {
        for(int x = 1; x <= n; x++)
        {
            if(pole[x][y] == c)
            {
                int s = bfs(x, y, c);
                s--;

                if(x + s > n || y + s > n)
                {
                    return 0;
                }
                if(suma[x + s][y + s] - suma[x + s][y - 1] - suma[x - 1][y + s] + suma[x - 1][y - 1] != (s + 1) * (s + 1))
                {
                    return 0;
                }
            }           
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>t;
    for(int c = 1; c <= t; c++)
    {
        cin>>n;
        for(int y = 1; y <= n; y++)
        {
            for(int x = 1; x <= n; x++)
            {
                char ch;
                cin>>ch;

                if(ch == '.')
                {
                    pole[x][y] = c;
                }
                else
                {
                    pole[x][y] = 0;
                }
            }
        }

        liczenieSum(c);
        if(liczenie(c))
        {
            cout<<"UFO\n";
        }
        else
        {
            cout<<"Janusz\n";
        }
    }
}
