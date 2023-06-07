#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;

int n, m;
int odl[mak][mak];
char pole[mak][mak];

pair<int, int> r[8] = {
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1}
};

void bfs(int sx, int sy)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            odl[i][j] = -1;
        }
    }

    queue<pair<int, int>>q;
    q.push({sx, sy});

    odl[sx][sy] = 0;

    while(!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();

        for(int i = 0; i < 8; i++)
        {
            pair<int, int> przejscie;

            przejscie.first = v.first + r[i].first;
            przejscie.second = v.second + r[i].second;

            if(przejscie.first < 1 || przejscie.second < 1 || przejscie.first > n || przejscie.second > m) continue;
            if(pole[przejscie.first][przejscie.second] == 'x') continue;

            if(odl[przejscie.first][przejscie.second] == -1)
            {
                odl[przejscie.first][przejscie.second] = odl[v.first][v.second] + 1;
                q.push(przejscie);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    pair<int, int>start, koniec;

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> pole[i][j];
            if(pole[i][j] == 'z') start = {i, j};
            else if(pole[i][j] == 'n') koniec = {i, j};
        }
    }

    //liczenie
    bfs(start.first, start.second);

    //sprawdzenie
    if(odl[koniec.first][koniec.second] == -1) cout << "NIE\n";
    else cout << odl[koniec.first][koniec.second] << "\n";
}