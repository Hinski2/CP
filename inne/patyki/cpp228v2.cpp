#include <bits/stdc++.h>
using namespace std;

const int mak = 51;

int liczba_kolorow;
int liczba_patykow_koloru[mak];

vector<int>patyki_koloru[mak];
vector<pair<int, int>>liczby;

void wczytaj()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> liczba_kolorow;
    for(int i = 1; i <= liczba_kolorow; i++)
    {
        cin >> liczba_patykow_koloru[i];
        for(int j = 1; j <= liczba_patykow_koloru[i]; j++)
        {
            int x;
            cin >> x;

            patyki_koloru[i].push_back(x);
            liczby.push_back({x, i});
        }
    }
}

void liczenie()
{
    sort(liczby.begin(), liczby.end());

    //pierwsze wybranie patyków
    pair<int, int> p1 = {0, 0}, p2 = {0, 0}, p3 = {0, 0}, p;
    for(int i = 0; i < liczby.size(); i++)
    {
        p = liczby[i];
        if(p.first != p1.first && p.first != p2.first)
        {
            p3 = p2;
            p2 = p1;
            p1 = p;
        }
        else if(p.first == p2.first)
        {
            p2 = p1;
            p1 = p;
        }
        else if(p.first == p1.first)
        {
            p1 = p;
        }

        //sprawdzenie poprawnosci p'ów
        if(p1.second != p2.second && p1.second != p3.second && p2.second != p3.second && p3.first + p2.first > p1.first)
        {
            printf("%d %d %d %d %d %d\n", p1.second, p1.first, p2.second, p2.first, p3.second, p3.first);
            return;
        }
    }  

    cout << "NIE\n";
}

int main()
{
    wczytaj();
    liczenie();
}