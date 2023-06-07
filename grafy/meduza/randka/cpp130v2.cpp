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
    bool Swap = false;
    int ix, iy, dx, dy;

    if(idx_w_cyklu[x] < idx_w_cyklu[y])
    {
        swap(x, y);
        Swap = true;
    }

    ix = idx_w_cyklu[x];
    iy = idx_w_cyklu[y];

    dx = ix - iy;
    dy = rozmiar_cyklu[kolor_cyklu[y]] - dx;

    if(Swap)
    {
        swap(x, y);
        swap(dx, dy);
    }

    int do_x = ansx + dx;
    int do_y = ansy + dy;

    if(do_x == do_y)
    {
        if(ansy == ansx)
        {
            ansx += dx;
        }
        else if(ansy < ansx)
        {
            ansx += dx;
        }
        else
        {
            ansy += dy;
        }
    }
    else if(do_x < do_y)
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
    //przejście na tą samą wyskokość 
    bool Swap = false;

    if(odl[x] < odl[y])
    {
        swap(x, y);
        Swap = true;
    }

    int r = odl[x] - odl[y];
    for(int i = LOG - 1; i >= 0; i--)
    {
        if(r & (1 << i))x = up[x][i];
    }

    if(x == y)
    {
        if(Swap)swap(x, y);
        return x;
    }

    for(int i = LOG - 1; i >= 0; i--)
    {
        if(up[x][i]  != up[y][i])
        {
            x = up[x][i];
            y = up[y][i];
        }
    }

    if(!kolor_cyklu[x])
    {
        x = up[x][0];
        y = up[y][0];
    }


    if(x == y)
    {
        if(Swap)swap(x, y);
        return x;
    }
    else
    {
        if(Swap)swap(x, y);
        return 0;
    }
}

int zapytanie(int a, int b)
{
    ansx = 0;
    ansy = 0;

    if(colour[a] != colour[b])
    {
        cout<<"-1 -1\n";
        return 0;
    }

    int l = lca();
    if(l == 0)
    {
        ansx += odl[a];
        ansy += odl[b];

        na_cyklu();

        cout<<ansx<<" "<<ansy<<"\n";
        return 0;
    }
    else
    {
        ansx = odl[a] - odl[l];
        ansy = odl[b] - odl[l];

        cout<<ansx<<" "<<ansy<<"\n";
        return 0;
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