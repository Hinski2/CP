#include <bits/stdc++.h>
using namespace std;

const int maksimum = 5e5 + 15;

int n, m;
int kolor[maksimum], k; //SSS

bool odwiedzony[maksimum];

vector<int>G[maksimum];
vector<int>OG[maksimum];

vector<int>kolejka;

set<int>SSS[maksimum];
vector<int>OSSS[maksimum];
int deg[maksimum];

void dfs(int v)
{
    odwiedzony[v] = true;

    for(auto u: G[v])
    {
        if(!odwiedzony[u])
        {
            dfs(u);
        }
    }

    kolejka.push_back(v); //postorder 
}

void make_SCC(int idx, int c)
{
    kolor[idx] = c;

    for(auto u: OG[idx])
    {
        if(!kolor[u])
        {
            make_SCC(u, c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie danych 
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin>>a>>b;

        G[a].push_back(b); //dnie nieparzyste
        OG[b].push_back(a);  //dnie parzyste
    }

    //tworzenie kolejki 
    for(int i = 1; i <= n; i++)
    {
        if(!odwiedzony[i])
        {
            dfs(i);
        }
    }

    //tworzenie SSS
    for(int i = n - 1; i >= 0; i--)
    {
        if(!kolor[kolejka[i]])
        {
            make_SCC(kolejka[i], ++k);
        }
    }

    //ustawianie połączeń pomiędzy SSS
    for(int i = 1; i <= n; i++) 
    {
        for(auto u: G[i])
        {
            if(kolor[i] != kolor[u]) //czy jest to wierzchołek styczny do SSS
            {
                if(SSS[kolor[u]].count(kolor[i]) == 0) //sprawdzanie czy już wierzchołek styczny nie został policzony
                {
                    SSS[kolor[i]].insert(kolor[u]);     //dodanie połączenia
                    OSSS[kolor[u]].push_back(kolor[i]);
                    deg[kolor[u]]++;                    //zwiększenie ilości sąsiadów
                }
            }
        }
    }

    //sortowanie topologiczne
    queue<int>q;

    for(int i = 1; i <= k; i++) //dodawanie na kolejke wierzchołków o stoniu wejściowym == 0
    {
        if(deg[i] == 0)
        {
            q.push(i);
        }
    }

    //sortowanie topologiczne
    int processed = 0;
    set<int>a;
    set<int>result;

    while(!q.empty())
    {
        int rozmiar = q.size();

        if(rozmiar == 1)
        {
            for(auto u: OSSS[q.front()])
            {
                a.insert(u);
            }

            if(a.size() == processed)
            {
                result.insert(q.front());
            }
        }

        while(rozmiar--)
        {
            int f = q.front();
            q.pop();

            for(auto u: OSSS[f])
            {
                a.insert(u);
            }

            for(auto u:SSS[f])
            {
                deg[u]--;

                if(deg[u] == 0)
                {
                    q.push(u);
                }
            }
            processed++;  
        }
    }

    vector<int>ans;

    for(int i = 1; i <= n; i++)
    {
        if(result.count(kolor[i])) ans.push_back(i);
    }

    //wypisywanie wyniku
    cout<<ans.size()<<"\n";

    for(auto u: ans)
    {
        cout<<u<<" ";
    }
    cout<<"\n";
}