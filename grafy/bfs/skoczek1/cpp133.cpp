#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;

int n, m;
int a, b;
pair<int, int> start, koniec;

int vx[8];
int vy[8];

bool pole[mak][mak];
bool odwiedzone[mak][mak];

void ustawienie()
{
    vx[0] = -a; 
    vx[1] = -a; 
    vx[2] = a;
    vx[3] = a;
    vx[4] = -b;
    vx[5] = -b;
    vx[6] = b;
    vx[7] = b;

    vy[0] = -b;
    vy[1] = b;
    vy[2] = b;
    vy[3] = -b;
    vy[4] = -a;
    vy[5] = a;
    vy[6] = a;
    vy[7] = -a;
}

int bfs()
{
    queue<pair<pair<int, int>, int>>q;
    q.push({{start.first, start.second}, 0});

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int s = q.front().second;

        q.pop();

        if(!odwiedzone[x][y])
        {
            odwiedzone[x][y] = true;
            if(x == koniec.first && y == koniec.second)
            {
                return s;
            }

            for(int i = 0; i <= 7; i++)
            {
                if((x + vx[i] >= 1 && x + vx[i] <= m) && (y + vy[i] >= 1 && y + vy[i] <= n) && !odwiedzone[x + vx[i]][y + vy[i]] && pole[x + vx[i]][y + vy[i]])
                {
                    q.push({{x + vx[i], y + vy[i]}, s + 1});
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n>>m>>a>>b;
    ustawienie(); //ustawienie skoków
    for(int y = 1; y <= n; y++) //wczytanie mapy
    {
        for(int x = 1; x <= m; x++)
        {
            char c;
            cin>>c;

            if(c == '.')
            {
                pole[x][y] = true;
            }
            else if(c == 'X')
            {
                pole[x][y] = false;
            }
            else if(c == 'S')
            {
                pole[x][y] = true;
                start = {x, y};
            }
            else
            {
                pole[x][y] = true;
                koniec = {x, y};
            }
        }
    }

    //*liczenie
    int ans = bfs();

    //*wypisanie wyniku
    if(ans)
    {
        cout<<ans<<"\n";
    }
    else
    {
        cout<<"NIE\n";
    }
}