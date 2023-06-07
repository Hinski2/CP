#include <bits/stdc++.h>
using namespace std;

const int mak = 105;

int n, m;
int ans;

bool pole[mak][mak];
int odwiedzony[mak][mak];

int vx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int vy[] = {1, 1, 0, -1, -1, -1, 0, 1};

queue<pair<int, int>>q;

int bfs2(int _x, int _y, int c)
{
    queue<pair<pair<int, int>, int>>sq;
    int maks = 0;

    sq.push({{_x, _y}, 1});

    while(!sq.empty())
    {
        int x = sq.front().first.first;
        int y = sq.front().first.second;
        int s = sq.front().second;
        sq.pop();

        if(odwiedzony[x][y] != c)
        {
            maks = max(maks, s);
            odwiedzony[x][y] = c;

            for(int i = 0; i < 8; i++)
            {
                if((x + vx[i] >= 1 && x + vx[i] <= n) && (y + vy[i] >= 1 && y + vy[i] <= n) && odwiedzony[x + vx[i]][y + vy[i]] != c)
                {
                    if(pole[x + vx[i]][y + vy[i]])
                    {
                        sq.push({{x + vx[i], y + vy[i]}, s + 1});
                    }
                    else
                    {
                        q.push({x + vx[i], y + vy[i]});
                    }
                }
            }
        }
    }

    return maks;
}

void liczenie(int c)
{
    int maks = 0;

    q.push({1, 1});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(odwiedzony[x][y] != c)
        {
            if(pole[x][y])
            {
                maks = max(maks, bfs2(x, y, c));
            }
            else
            {
                odwiedzony[x][y] = c;

                for(int i = 0; i < 8; i++)
                {
                    if((x + vx[i] >= 1 && x + vx[i] <= n) && (y + vy[i] >= 1 && y + vy[i] <= n) && odwiedzony[x + vx[i]][y + vy[i]] != c)
                    {
                        q.push({x + vx[i], y + vy[i]});
                    }
                }
            }
        }
    }

    cout<<maks * maks<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //*wczytywanie
    cin>>m;
    for(int c = 1; c <= m; c++)
    {
        cin>>n;

        for(int y = 1; y <= n; y++)
        {
            for(int x = 1; x <= n; x++ )
            {
                char ch;
                cin>>ch;

                if(ch == '.')
                {
                    pole[x][y] = true;
                }
                else
                {
                    pole[x][y] = false;
                }
            }
        }

        liczenie(c);
    }
}