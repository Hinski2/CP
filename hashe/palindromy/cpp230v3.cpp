#include <bits/stdc++.h>
using namespace std;

const int mak = 205;

int n;
string str;
bool znaleziony = false;

int odwiedzony[mak];

vector<pair<int, int>>G[mak];
vector<int>wynik1, wynik2;

void wczytanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> str;
    n = str.size();
}

void make_nodes()
{
    for(int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        int k = 0;
        while(str[i - k] == str[j + k])
        {
            G[i - k].push_back({j + k - (i - k), j + k});
            k++;
            if(i - k < 0 || j + k > n - 1) break;
        }
    }
}

void max_dystans()
{
    pair<int, int>odl[mak];

    for(int i = 1; i <= n; i++)
    {
        odl[i] = {mak, mak};
    }

    for(int i = 0; i < n; i++)
    {
        for(auto u: G[i])
        {
            if(odl[u.second + 1].first > odl[i].first + 1)
            {
                odl[u.second + 1].first = odl[i].first + 1;
                odl[u.second + 1].second = i;
            }
        }
    }

    if(odl[n].first == mak)
    {
        cout << "NIE\n";
        exit(0);
    }

    int v = odl[n].second;
    while(v)
    {
        wynik1.push_back(v);
        v = odl[v].second;
    }

    reverse(wynik1.begin(), wynik1.end());
}

void min_dystans()
{
    pair<int, int>odl[mak];

    for(int i = 0; i < n; i++)
    {
        for(auto u: G[i])
        {
            if(odl[u.second + 1].first < odl[i].first + 1)
            {
                odl[u.second + 1].first = odl[i].first + 1;
                odl[u.second + 1].second = i;
            }
        }
    }

    int v = odl[n].second;
    while(v)
    {
        wynik2.push_back(v);
        v = odl[v].second;
    }

    reverse(wynik2.begin(), wynik2.end());
}

void wypisz()
{
    wynik1.push_back(n);
    wynik2.push_back(n);
    int j = 0;
    for(auto u: wynik1)
    {
        while(j < u && j < n) cout << str[j++];
        cout << " ";
    }
    cout << "\n";
    
    j = 0;
    for(auto u: wynik2)
    {
        while(j < u && j < n) cout << str[j++];
        cout << " ";
    }
    cout << "\n";
}

int main()
{
    wczytanie();
    make_nodes();
    max_dystans();
    min_dystans();

    wypisz();
}