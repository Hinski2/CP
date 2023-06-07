#include <bits/stdc++.h>
using namespace std;

const int mak = 4e5 + 15;

int n, m, q;
int sumaWiarsz[mak], sumaKolumna[mak];
int itr[mak];

bool przejscie[mak];

vector<pair<int, int>>wypisanie;
vector<pair<int, int>>G[mak];

bool sprawdzenieSum()
{
    for(int i = 1; i <= n; i++)
    {
        if(sumaWiarsz[i] % 2 == 1) return 0;
        if(sumaKolumna[i] % 2 == 1) return 0;
    }

    return 1;
}

void wyznacz(int v)
{
    while(itr[v] < G[v].size())
    {
        int u = G[v][itr[v]].first;
        int nr = G[v][itr[v]].second;
        
        itr[v]++;
        if(!przejscie[nr])
        {
            przejscie[nr] = true;
            wyznacz(u);

            if(u > n)
            {
                wypisanie.push_back({nr, 1});
            }
            else
            {
                wypisanie.push_back({nr, -1});
            }
        }
    }
}


void wyznacz_eulera()
{
    for(int i = 1; i <= n; i++)
    {
        if((int)G[i].size()) wyznacz(i);
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> m >> q;
    for(int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;

        sumaWiarsz[a]++;
        sumaKolumna[b]++;

        G[a].push_back({b + n, i});
        G[b + n].push_back({a, i});
    }

    //liczenie
    if(!sprawdzenieSum())
    {
        cout << "NIE\n";
        return 0;
    }
    else cout << "TAK\n";

    //wyznaczanie ścieżki eulera
    wyznacz_eulera();

    //wypisanie
    sort(wypisanie.begin(), wypisanie.end());

    for(auto u: wypisanie)
    {
        cout << u.second << "\n";
    }

}