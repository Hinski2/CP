#include<bits/stdc++.h>
using namespace std;

const int maksimum = 100015;
const int inf = 1000007;

int n, m;
int wysokosc[maksimum];     //wysokości wierzchołków

bool odwiedzony[maksimum];  //do sprawdzania czy wierzchołek został odwiedzony 

vector<pair<int, int>>G[maksimum];  //vector połączeń
vector<int>maks(maksimum, inf);     //vector trzymający minimalną wysokośc dla każdego punktu 

priority_queue<pair<int, int>>p;    //trzyma -wysokość, nr wierzchołka  

void dijkstra()
{
    p.push({wysokosc[1], 1});   //wysokość wierzchołka startowego, wierzchołek startowy

    while(!p.empty())
    {
        int m = p.top().first;  //wysokość
        int v = p.top().second; //id wierzchołka

        p.pop();   

        if(!odwiedzony[v])
        {
            odwiedzony[v] = true;
            maks[v] = -m;   // minus ponieważ na koejce trzymam ujemne wartoścu

            for(auto u: G[v])
            {
                if(!odwiedzony[u.second])   //jeśli wierzchołek nie był odwiedzony
                {
                    p.push({min(m, u.first), u.second});    //min ponieważ trzymam wartości ujemne 
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;

    for(int i = 1; i <= n; i++)
    {
        cin>>wysokosc[i];
    }

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin>>a>>b;

        //-wysokość ponieważ na kolejce priorytetowaj trzymam wartości ujemne 
        G[a].push_back({-wysokosc[b], b});  
        G[b].push_back({-wysokosc[a], a});
    }

    dijkstra();

    //wypisanie odpowiedzi
    cout<<maks[n]<<endl;
    return 0;
}