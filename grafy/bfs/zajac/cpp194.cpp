#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;

int vx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int vy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int n, m;
bool pole[mak][mak];
pair<int, int>start, koniec;

void bfs()
{
    queue<pair<int, pair<int, int>>>q;

    q.push({0, {start.first, start.second}});

    while(!q.empty())
    {
        int s = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(pole[x][y])
        {
            pole[x][y] = false;
            if(x == koniec.first && y == koniec.second)
            {
                cout << s << "\n";
                return;
            }

            for(int i = 0; i < 8; i++)
            {
                if((x + vx[i] >= 0 && x + vx[i] < n) && (y + vy[i] >= 0 && y + vy[i] < m) && pole[x +vx[i]][y + vy[i]])
                {
                    q.push({s + 1, {x + vx[i], y + vy[i]}});
                }
            }
        }
    }

    cout << "NIE\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if(c == '.')
            {
                pole[i][j] = true;
            }
            else if(c == 'x')
            {
                pole[i][j] = false;
            }
            else if(c == 'z')
            {
                pole[i][j] = true;
                start = {i, j};
            }
            else
            {
                pole[i][j] = true;
                koniec = {i, j};
            }
        }
    }

    //liczenie
    bfs();
}