#include <bits/stdc++.h>
using namespace std;

const int mak = 5e5 + 15;

int n;
list<int>::iterator itr[mak];

list<int>l;
vector<int>kolejnosc;

void oblicz(int u)
{
    cout << *prev(itr[u]) << " ";
    cout << *next(itr[u]) << "\n";

    l.erase(itr[u]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        kolejnosc.push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        l.push_back(i);
    }

    list<int>::iterator it;
    int idx = 1;

    for(it = l.begin(); it != l.end(); it++)
    {
        itr[idx++] = it;
    }

    l.push_front(-1);
    l.push_back(-1);

    for(auto u: kolejnosc)
    {
        oblicz(u);
    }
}