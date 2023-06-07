#include <bits/stdc++.h>
using namespace std;

const int mak = 205;

int n;
string str;
bool znaleziony = false;

int odl_max[mak], odl_min[mak];
int odwiedzony[mak];

vector<int>v_min;
vector<vector<int>>wynik_max;
vector<pair<int, int>>G[mak];

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

void dystans_max(int v, vector<int>vec)
{
    if(v == n)
    {
        wynik_max.push_back(vec);
    }

    vec.push_back(v);

    for(auto u: G[v])
    {
        dystans_max(u.second + 1, vec);
    }
}

void dystans_min()
{
    priority_queue<pair<int, int>>q;

    q.push({0, 0});
    while(!q.empty())
    {
        int s = q.top().first;
        int v = q.top().second;

        q.pop();
        if(odwiedzony[v] != 2)
        {
            odwiedzony[v] = 2;
            odl_min[v] = -s;
            v_min.push_back(v);

            for(auto u: G[v])
            {
                if(odwiedzony[u.second] != 2)
                {
                    q.push({s - u.first, u.second + 1});
                }
            }
        }
    }
}

void wypisanie_max()
{
    vector<int>wynik;
    int minimum = mak;

    for(auto u: wynik_max)
    {
        if(minimum > u.size())
        {
            minimum = u.size();
            wynik = u;
        }
    }

    wynik.push_back(n);
    int j = 0;

    for(int i = 1; i < wynik.size(); i++)
    {
        while(j < wynik[i])
        {
            cout << str[j++];
        }
        cout << " ";
    }
}

void wypisanie_min()
{
    cout << endl;
    int j = 0;
    v_min.push_back(n);

    for(int i = 1; i < v_min.size(); i++)
    {
        while(j < v_min[i])
        {
            cout << str[j++];
        }
        cout << " ";
    }
}

int main()
{
    wczytanie();
    make_nodes();
    dystans_min();
    vector<int>pusty_vector;

    dystans_max(0, pusty_vector);

    if(odl_min[n] == 0)
    {
        cout << "NIE\n";
        return 0;
    }

    wypisanie_max();
    wypisanie_min();
}