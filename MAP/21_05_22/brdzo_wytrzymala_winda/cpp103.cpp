#include <bits/stdc++.h>
using namespace std;

const int maks = 315; 
int n, q;

vector<int>G[maks];
vector<int>kolejka;

int wynik[maks];
int wartosc[maks];
int wchodzi[maks];

void top_sort()
{
    queue<int>q;

    q.push(0);
    kolejka.push_back(0);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto u: G[v])
        {
            wartosc[u]--;
            if(wartosc[u] == 0)
            {
                q.push(wartosc[u]);
                kolejka.push_back(wartosc[u]);
            }
        }
    }
}

void liczenie(int v)
{
    if(wynik[v] == 0)
    {
        for(auto u: G[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>q;

    for(int i = 1; i <= n; i++)
    {
        cin>>wchodzi[i];
        for(int j = 1; j <= wchodzi[i]; j++)
        {
            int x;
            G[i].push_back(x);
        }
        G[0].push_back(i);
    }

    for(int i = 1; i <= n; i++)
    {
        cin>>wartosc[i];
    }

    //sortowanie topologiczne
    top_sort();
    liczenie(0);
}