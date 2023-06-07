#include <bits/stdc++.h>
using namespace std;

struct trojka
{
    int a, b, dir;

    trojka(int x, int y, int z)
    {
        a = x;
        b = y;
        dir = z;
    }
};

const int maksimum = 315;
const int inf = 1e9 + 7;

int xLength, yLength;
int pole[maksimum][maksimum][8];    //pole na ruchy
char mapa[maksimum][maksimum];     //mapuje czy jest przejście czy go nie ma 


int xRuch[] = {-1,  0,  1, 1, 1, 0, -1, -1};
int yRuch[] = {-1, -1, -1, 0, 1, 1,  1,  0};

pair<int, int> kingPos, fridgePos; //pozycja króla, pozycja lodówki 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  //magiczna linijka
    cin >> xLength >> yLength;  //wczytywanie rozmiarów mapy

    //wczytywanie mapy
    for(int x = 1; x <= xLength; x++)
    {
        for(int y = 1; y <= yLength; y++)
        {
            cin>>mapa[x][y];
        }
    }

    queue<trojka>q;

    //ustawianie wartości
    for(int x = 1; x <= xLength; x++)
    {
        for(int y = 1; y <= yLength; y++)
        {
            for(int z = 0; z < 8; z++)
            {
                pole[x][y][z] = inf;

                if(mapa[x][y] == 'K')
                {
                    pole[x][y][z] = 0;
                    q.push({x, y, z});
                }
            }
        }
    }
    

    while(!q.empty())
    {
        int X = q.front().a;
        int Y = q.front().b;
        int Dir = q.front().dir;

        q.pop();
        
        if(mapa[X][Y] == 'S')
        {
            cout<<pole[X][Y][Dir]<<"\n";
            return 0;
        }

        for(int i = -1; i <= 1; i++)
        {
            int _dir = (Dir + i + 8) % 8;
            int _x = X + xRuch[_dir];
            int _y = Y + yRuch[_dir];

            if(mapa[_x][_y] == 'X')continue;

            if(pole[_x][_y][_dir] > pole[X][Y][Dir] + 1)
            {
                pole[_x][_y][_dir] = pole[X][Y][Dir] + 1;
                q.push({_x, _y, _dir});
            }
        }
    }
    cout<<"NIE\n";
}
