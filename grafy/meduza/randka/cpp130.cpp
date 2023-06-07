#include <bits/stdc++.h>
using namespace std;

const int mak = 5e5 + 15;
const int LOG = 19;

int n, m;
int x, y, ansx, ansy;
int colour[mak], c = 1;
int kolor_odwiedzenia[mak], kolor_cyklu[mak];
int odl[mak];
int idx, idx_w_cyklu[mak], rozmiar_cyklu[mak];
int up[mak][LOG];

bool visited[mak];

vector<int>G[mak];
vector<int>Gn[mak];

void kolorowanie(int v)
{
    colour[v] = c;
    for(auto u: Gn[v])
    {
        if(!colour[u])
        {
            kolorowanie(u);
        }
    }
}

void check_spojnosc()
{
    for(int i = 1; i <= n; i++)
    {
        if(!colour[i])
        {
            kolorowanie(i);
            c++;
        }
    }
}

int odwiedzenie(int v)
{
    kolor_odwiedzenia[v] = 1;
    for(auto u: G[v])
    {
        if(kolor_odwiedzenia[u] == 0)
        {
            int c = odwiedzenie(u);
            if(c)
            {
                if(c == v)
                {
                    kolor_cyklu[v] = c;
                    kolor_odwiedzenia[v] = 2;
                    idx_w_cyklu[v] = idx++;
                    return 0;
                }
                else
                {
                    kolor_cyklu[v] = c;
                    kolor_odwiedzenia[v] = 2;
                    idx_w_cyklu[v] = idx++;
                    return c;
                }
            }
        }
        else if(kolor_odwiedzenia[u] == 1)
        {
            kolor_cyklu[v] = u;
            kolor_odwiedzenia[v] = 2;
            idx_w_cyklu[v] = idx++;
            return u;
        }
    }
    kolor_odwiedzenia[v] = 2;
    return false;
}

void find_cykle()
{
    for(int i = 1; i <= n; i++)
    {
        idx = 0;
        if(!kolor_odwiedzenia[i]) odwiedzenie(i);
    }

    for(int i = 1; i <= n; i++)
    {
        if(kolor_cyklu[i]) rozmiar_cyklu[kolor_cyklu[i]]++;
    }
}

void dp(int v)
{
    for(int i = 1; i < LOG; i++)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
}

void dfs(int v, int p = 0)
{
    visited[v] = true;

    up[v][0] = p;
    dp(v);

    for(auto u: Gn[v])
    {
        if(kolor_cyklu[u])
        {
            if(!visited[u])
            {
                dfs(u, p);
            }
        }
        else
        {
            if(!visited[u])
            {
                odl[u] = odl[v] + 1;
                dfs(u, v);
            }
        }

    }
}

void find_odl_od_cyklu()
{
    for(int i = 1; i <= n; i++)
    {
        if(kolor_cyklu[i] && !visited[i])
        {
            dfs(i);
        }
    }
}

void na_cyklu()
{
    int ix = idx_w_cyklu[x];
    int iy = idx_w_cyklu[y];

    int dx = 0;
    int dy = 0;

    if(ix < iy)
    {
        dx = rozmiar_cyklu[x] - iy;
        dy = iy - ix;
    }
    else if(ix > iy)
    {
        dy = rozmiar_cyklu[x] - ix;
        dx = ix - iy;
    }

    if(dx < dy)
    {
        ansx += dx;
    }
    else
    {
        ansy += dy;
    }
}

int lca()
{
    for(int i = LOG - 1; i >= 0; i--)
    {
        if(up[x][i] != up[y][i])
        {
            x = up[x][i];
            y = up[y][i];
        }
    }

    if(up[x][0] == 0)
    {
        return x;
    }
    else
    {
        return up[x][0];
    }

    return 0;
}

int zapytanie(int a, int b)
{
    ansx = 0, ansy = 0;

    if(colour[x] != colour[y])
    {
        cout<<"-1 -1\n";
        return 0;
    }
    else
    {
        if(kolor_cyklu[x] && kolor_cyklu[y]) //oba wierzchołki są na cyklu
        {
            na_cyklu();
            cout<<ansx<<" "<<ansy<<"\n";
            return 0;
        }
        else if(kolor_cyklu[x])             //tyklo x jest na cyklu
        {
            //idze y na cykl
            ansy += odl[y];
            int r = odl[y];
            for(int i = LOG - 1; i >= 0; i--)
            {
                if(r & (1 << i)) y = up[y][i];
            }

            //idzie x do y
            int ix = idx_w_cyklu[x];
            int iy = idx_w_cyklu[y];

            if(ix < iy)
            {
                ansx = rozmiar_cyklu[x] - iy;
            }
            else if(ix > iy)
            {
                ansx = ix - iy;
            }

            cout<<ansx<<" "<<ansy<<"\n";
            return 0;
        }
        else if(kolor_cyklu[y])             //tylko y jest na cyklu
        {
            //idze x na cykl
            ansx += odl[x];
            int r = odl[x];
            for(int i = LOG - 1; i >= 0; i--)
            {
                if(r & (1 << i)) x = up[x][i];
            }

            //idzie y do x
            int ix = idx_w_cyklu[x];
            int iy = idx_w_cyklu[y];

            if(ix < iy)
            {
                ansy = iy - ix;
            }
            else if(ix > iy)
            {
                ansy = rozmiar_cyklu[x] - ix;
            }

            cout<<ansx<<" "<<ansy<<"\n";
            return 0;    
        }
        else                                //wierzchołki nie są na cyklu
        {
            // idzie na ten sam poziom
            if(odl[x] > odl[y])
            {
                int r = odl[x] - odl[y];

                for(int i = LOG - 1; i >= 0; i--)
                {
                    if(r & (1 << i)) x = up[x][i];
                }

                ansx += r;
                
            }
            else if(odl[x] < odl[y])
            {
                int r = odl[y] - odl[x];

                for(int i = LOG - 1; i >= 0; i--)
                {
                    if(r & (1 << i)) y = up[y][i];
                }

                ansy += r;
            }

            //jeśli x == y
            if(x == y)
            {
            cout<<ansx<<" "<<ansy<<"\n";
            return 0;
            }

            a = x;
            b = y;

            // szukanie lca
            int l = lca();
            if(kolor_cyklu[l])//lca jest na cyklu
            {
                ansx += odl[a];
                ansy += odl[b];

                na_cyklu();
            }
            else //lca jest w jednym z poprzedników
            {
                ansx += odl[x] - odl[l];
                ansy += odl[y] - odl[l];
            }

            cout<<ansx<<" "<<ansy<<"\n";
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n>>m;
    for(int a = 1; a <= n; a++)
    {
        int b;
        cin>>b;

        G[a].push_back(b);
        Gn[a].push_back(b);
        Gn[b].push_back(a);
    }

    //*preProcesing
    check_spojnosc();
    find_cykle();
    find_odl_od_cyklu();

    //*odpowiadanie na zapytania
    while(m--)
    {
        cin>>x>>y;
        zapytanie(x, y);
    }
}