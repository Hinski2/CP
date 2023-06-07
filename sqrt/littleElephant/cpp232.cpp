#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;
const int mak_sqr = 320;

int n, m;
int sqr;

int arr[mak];
int suma_sqr[mak_sqr][mak];

void wczytanie()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    sqr = sqrt(n);

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x > (int)1e5) continue;

        arr[i] = x;
        suma_sqr[i / sqr][arr[i]]++;
    }
}

void zapytanie(int l, int r)
{
    int wynik = 0;
    vector<int>suma(mak, 0);

    //dodanie środkowych wartosci;
    for(int i = l / sqr + 1; i < r / sqr; i++)
    {
        for(int j = 1; j < (int) 1e5; j++)
            suma[j] += suma_sqr[i][j];
    }

    //dodanie lewego przedzialu
    for(int i = l; i < min(r + 1, (l / sqr + 1) * sqr); i++)
    {
        suma[arr[i]]++;
    }

    //jeśli l i r są w róznych fragmentach
    if(l / sqr != r / sqr)
    {
        for(int i = r; i >= r / sqr * sqr; i--)
        {
            suma[arr[i]]++;
        }
    }

    //sprawdzenie
    for(int i = 1; i <= n; i++)
    {
        if(suma[i] == i) wynik++;
    }

    cout << wynik << "\n";
}

int main()
{
    wczytanie();
    while(m--)
    {
        int a, b;
        cin >> a >> b;

        zapytanie(a, b);
    }
}