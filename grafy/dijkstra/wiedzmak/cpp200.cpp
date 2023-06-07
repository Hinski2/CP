#include <bits/stdc++.h>
using namespace std;

const int nak = 205;

int n, m;
int liczba_kowali, liczba_gatunkow;
int kowal[nak];

bool odwiedzony[nak][1 << 14];
vector<pair<int, pair<int, int>>>G[nak];

void wczytywanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wcztytwanie
    cin >> n >> m >> liczba_gatunkow >> liczba_kowali;

    //wczytywanie kowali
    for(int i = 1; i <= liczba_kowali; i++)
    {
        int miejscowosc, liczba;
        cin >> miejscowosc >> liczba;
        for(int j = 1; j <= liczba; j++)
        {
            int rodzaj_miecza;
            cin >> rodzaj_miecza;

            kowal[miejscowosc] |= (1 << rodzaj_miecza);
        }
    }

    //wcczytywanie dróg
    for(int i = 1; i <= m; i++)
    {
        int a, b, s, liczba_potworow;
        cin >> a >> b >> s >> liczba_potworow;

        int maska = 0;
        for(int j = 1; j <= liczba_potworow; j++)
        {
            int potwor;
            cin >> potwor;
            maska |= (1 << potwor);
        }

        G[a].push_back({-s, {b, maska}});
        G[b].push_back({-s, {a, maska}});
    }
}

int liczenie()
{
    priority_queue<pair<int, pair<int, int>>>q; //{czas, {gdzie, maska}}

    q.push({0, {1, 0}});
    while(!q.empty())
    {
        int czas = q.top().first;
        int v = q.top().second.first;
        int maska = q.top().second.second;
        q.pop();

        if(!odwiedzony[v][maska])
        {
            odwiedzony[v][maska] = true;

            //jeśli dotarliśmy do bajtogrodu
            if(v == n)
            {
                return -czas;
            }

            //jeśli w wiosce jest kowal - uzupełnienie mieczy
            maska |= kowal[v];

            //dalsza podróż
            for(auto u: G[v])
            {
                if(!odwiedzony[u.second.first][maska] && (maska & u.second.second) == u.second.second)
                {
                    q.push({czas + u.first, {u.second.first, maska}});
                }
            }

        }
    }

    return -1;
}

int main()
{
    wczytywanie();
    cout << liczenie() << "\n";
}