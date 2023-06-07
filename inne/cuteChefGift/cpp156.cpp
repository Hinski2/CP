#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int q;
bool odwiedzony[mak];

vector<int>pierwsze[mak];

void sito()
{
    for(int i = 2; i <= mak; i++)
    {
        if(!odwiedzony[i])
        {
            for(int j = i; j <= mak; j += i)
            {
                pierwsze[j].push_back(i);
                odwiedzony[j] = true;
            }
        }
    }
}

int wyznaczanie()
{
    int n;
    int arr[mak];

    pair<int, int> pos[mak];

    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        int v;
        cin>>v;

        for(auto u: pierwsze[v])
        {
            if(pos[u].first)
            {
                arr[pos[u].second + 1]++;
                pos[u].second = i;
                arr[pos[u].second + 1]--;
            }
            else
            {
                pos[u].first = i;
                arr[pos[u].first]++;

                pos[u].second = i;
                arr[pos[u].second + 1]--;
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += arr[i];
        if(sum == 0) return i;
    }

    return n;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //preprocesing
    sito();

    //wczytywanie
    cin>>q;
    while(q--)
    {
        cout<<wyznaczanie()<<"\n";
    }
}