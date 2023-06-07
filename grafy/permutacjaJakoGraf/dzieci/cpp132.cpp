#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n;
int wsk[mak];
int liczba_spojnych;

bool visited[mak];

void dfs(int v)
{
    visited[v] = true;
    if(!visited[wsk[v]]) dfs(wsk[v]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>wsk[i];
    }

    //*liczenie
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            liczba_spojnych++;
        }
    }

    cout<<liczba_spojnych - 1<<"\n";
}
