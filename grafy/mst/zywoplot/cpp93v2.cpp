#include<bits/stdc++.h>
using namespace std;

const int maksimum = 1015;

int n, m;
int ans[2];

char V[maksimum][maksimum];
char H[maksimum][maksimum];

char ansV[maksimum][maksimum];
char ansH[maksimum][maksimum];

bool visited[maksimum][maksimum];


void wczytaj()
{   
    cin>>n>>m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            cin>>V[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>H[i][j];
        }
    }
}

inline int coord(int i, int j)
{
    return i*m + j;
}

//dziel i zwycieżaj 

int F[maksimum*maksimum];

void make_set(int id)
{
    F[id] = id;
}

int find(int id)
{
    if(F[id] == id)
    {
        return id;
    }

    F[id] = find(F[id]);
    return F[id];
}

void join(int id1, int id2)
{
    if(find(id1) != find(id2))
    {
        F[F[id1]] = F[id2]; 
    }
}

//koniec dzielenia i zwycięzania 

void solve()
{
    char step[] = {'T', 'C'};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            make_set(coord(i, j));
        }
    }

    for(int k = 0; k < 2; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m - 1; j++)
            {
                if(V[i][j] == step[k])
                {
                    int v = coord(i, j);
                    int u = coord(i, j + 1);

                    if(find(u) != find(v))
                    {
                        ansV[i][j] = '.';
                        join(u, v);
                    }
                    else
                    {
                        ans[k]++;
                        ansV[i][j] = 'Z';
                    }
                }
            }
        }

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(H[i][j] == step[k])
                {
                    int v = coord(i, j);
                    int u = coord(i + 1, j);

                    if(find(u) != find(v))
                    {
                        ansH[i][j] = '.';
                        join(u, v);
                    }
                    else
                    {
                        ans[k]++;
                        ansH[i][j] = 'Z';
                    }
                }
            }
        }
    }
}


void wypisz()
{ 
    cout<<ans[0] + ans[1]<<" "<<ans[1]<<"\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m - 1; j++)
        {
            cout<<ansV[i][j];
        }
        cout<<"\n";
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout<<ansH[i][j];
        }
        cout<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    wczytaj();
    solve();
    wypisz();
}