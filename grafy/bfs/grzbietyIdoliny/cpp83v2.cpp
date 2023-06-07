#include <bits/stdc++.h>
using namespace std;

const int maksimum=1015;
int n, pole[maksimum][maksimum];
int value, maxPrim, minPrim;

bool odwiedzone[maksimum][maksimum];

int xAdd[] = {-1, 0, 1, -1, 1, -1, 0, 1};   //tablica dla ułatwienia obliczeń 
int yAdd[] = {1, 1, 1, 0, 0, -1, -1, -1};   //tablica dla ułatwienia obliczeń 

bool check(int _x, int _y) //sprawdza czy współrzędne się nadają 
{
    return 1 <= _x && _x <= n && 1<= _y && _y <=n;
}

bool sprawdzenie(int _x, int _y)
{
    if(pole[_x][_y] == value) return true;
    else
    {
        minPrim = min(minPrim, pole[_x][_y]);
        maxPrim = max(maxPrim, pole[_x][_y]);
    }

    return false;
}

void bfs(int &_x, int &_y)
{
    odwiedzone[_x][_y] = true;  //ustawianie aktualniego pola jako odwiedzone

    //kolejka wierzchołków do sprawdzenia
    queue<pair<int, int>>k; 
    k.push({_x, _y});

    while(!k.empty())   //dopuki nie sprawdzi wszystkich mozliwości 
    {
        int xFront = k.front().first;
        int yFront = k.front().second;

        k.pop();

        odwiedzone[xFront][yFront] = true;

        for(int i = 0; i < 8; i++)
        {
            if(check(xFront + xAdd[i], yFront + yAdd[i]))   //wstpnie sprawdza czy współżędne są możliwe
            {
                if(sprawdzenie(xFront + xAdd[i], yFront + yAdd[i])) //sprawdzenie pola
                {
                    if(!odwiedzone[xFront + xAdd[i]][yFront + yAdd[i]]) //jeśli nie odwiedzone
                    {
                        odwiedzone[xFront + xAdd[i]][yFront + yAdd[i]] = true;
                        k.push({xFront + xAdd[i], yFront + yAdd[i]});   //dodaje pole na kolejke do sprawdzenia
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);     //wczytanie wielkości mapy

    for(int y=1; y<=n; y++) //wczytywanie mapy       
    {
        for(int x=1; x<=n; x++)
        {
            scanf("%d", &pole[x][y]);
        }
    }

    //koniec wczytywania
    int wzgurza=0, doliny=0;

    for(int y=1;y<=n;y++)
    {
        for(int x=1;x<=n;x++)
        {
            if(!odwiedzone[x][y])   //jeśli nieOdwiedzony
            {
                value=pole[x][y];   //ustawianie aktualniego pola
                minPrim=pole[x][y]; //ustawianie minimalnej wartości pola 
                maxPrim=pole[x][y]; //ustawianie maksumalniej wartości pola

                bfs(x, y);

                if(minPrim==value)doliny++;     //jeśli nie znalazło mniejszego pola
                if(maxPrim==value)wzgurza++;    //jeśli nie znalazło większego pola
            }
        }
    }

    printf("%d %d\n", wzgurza, doliny); //wypisanie wyniku
}