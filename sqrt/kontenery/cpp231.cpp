#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 500;
const int mak_sqrt = 320;

int n, k;
int sqr;
int wynik[mak];
int arr[mak_sqrt][mak];

void brut(int od, int ile, int co_ile)
{
    int gdzie = od;
    for(int i = 1; i <= ile; i++)
    {
        wynik[gdzie]++;
        gdzie += co_ile;
    }
}

void na_potem(int od, int ile, int co_ile)
{
    arr[co_ile][od]++;
    arr[co_ile][ile * co_ile + od]--;
}

void oblicz(int co_ile)
{
    for(int i = 1; i <= n; i++)
    {
        arr[co_ile][i + co_ile] += arr[co_ile][i];
        wynik[i] += arr[co_ile][i];
    }
}

void wypisanie()
{
    for(int i = 1; i <= n; i++)
    {
        cout << wynik[i] << " ";
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	sqr = sqrt(n);

	for(int i = 1; i <= k; i++)
    {
		int od, ile, co_ile;
		cin >> od >> ile >> co_ile;

		if(co_ile >= sqr) brut(od, ile, co_ile);
        else na_potem(od, ile, co_ile);
    }

    for(int i = 1; i < sqr; i++)
    {
        oblicz(i);
    }

    wypisanie();
}
