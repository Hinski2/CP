#include <bits/stdc++.h>
using namespace std;

const int mak = 185;

int n, m;
bool bialy[mak][mak], odwiedzony[mak][mak];
int ans[mak][mak];

int vy[] = {1, 0, -1, 0};
int vx[] = {0, 1, 0, -1};

queue<pair<pair<int, int>, int>>q;

void odleglosciowanie()
{
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int s = q.front().second;
        q.pop();

        if(!odwiedzony[x][y])
        {
            odwiedzony[x][y] = true;
            ans[x][y] = s;

            for(int i = 0; i < 4; i++)
            {
                if(x + vx[i] <= m && x + vx[i] > 0 && y + vy[i] <= n && y + vy[i] > 0 && !odwiedzony[x + vx[i]][y + vy[i]] && !bialy[x + vx[i]][y + vy[i]])
                {
                    q.push({{x + vx[i], y + vy[i]}, s + 1});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    cin >> n >> m;
    for(int y = 1; y <= n; y++)
    {
        for(int x = 1; x <= m; x++)
        {
            char c;
            cin >> c;
            if(c == '1')
            {
                bialy[x][y] == true;
                q.push({{x, y}, 0});
            }
        }
    }

    //liczenie odleglosci
    odleglosciowanie();

    //wypisanie wyniku
    for(int y = 1; y <= n; y++)
    {
        for(int x = 1; x <= m; x++)
        {
            cout << ans[x][y] << " ";
        }
        cout << "\n";
    }
}