#include <bits/stdc++.h>
using namespace std;

const int mak = 505;
const int inf = INT_MAX;

int n, m;
long long odl[mak][mak];

void make_macierz()
{
    for(int i = 1; i <= n; i++) //tworzenie macierzy z wszystkimi krawędziami == inf
    {
        for(int j = 1; j <= n; j++)
        {
            odl[i][j] = inf;
        }
    }

    for(int i = 1; i <= n; i++) //zapisywanie że odl(i, i) = 0 bo to ten sam wierzchołek
    {
        odl[i][i] = 0;
    }

    for(int i = 1; i <= m; i++)//wczytywanie odl pomiędzy krawędziami 
    {
        int a, b, s;
        cin>>a>>b>>s;

        odl[a][b] = s;
        odl[b][a] = s; //nieskierowany
    }
}

void liczenie()
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(odl[i][j] > odl[i][k] + odl[k][j])
                {
                    odl[i][j] = odl[i][k] + odl[k][j];
                }
            }
        }
    }
}


void wypisanie()
{
    for(int i = 1; i <= n; i++)
    {
        printf("\n%d: ", i);
        for(int j = 1; j <= n; j++)
        {
            if(odl[i][j] == inf)
            {
                printf("%d:inf, ", j);
            }
            else
            {
                printf("%d:%lld, ", j, odl[i][j]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //* wczytanie
    cin>>n>>m;
    make_macierz();

    //* liczenie
    liczenie();

    //* wypisanie wyniku
    wypisanie();
}