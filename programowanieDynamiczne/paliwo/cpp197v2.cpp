#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int pojemnosc_baku, ilosc_stacji;
int cena[mak], odl[mak];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
    cin >> pojemnosc_baku >> ilosc_stacji;
    for(int i = 1; i <= ilosc_stacji; i++)
    {
        cin >> cena[i] >> odl[i];
    }

    //liczenie
    int cena_paliwa = 0;
    int ilosc_paliwa = 0;
    long long koszt = 0;

    for(int i = 1; i <= ilosc_stacji + 1; i++)
    {
        if(ilosc_paliwa == 0)
        {
            cena_paliwa = cena[i];
            koszt += 1LL * pojemnosc_baku * cena[i];
            ilosc_paliwa = pojemnosc_baku;
        }
        if(cena_paliwa >= cena[i]) // sprzedajemy
        {
            koszt -= 1LL * cena_paliwa * ilosc_paliwa;
            koszt += 1LL * cena[i] * pojemnosc_baku;
            ilosc_paliwa = pojemnosc_baku;
            cena_paliwa = cena[i];
        }
        if(ilosc_paliwa < odl[i])
        {
            koszt += 1LL * cena[i] * (pojemnosc_baku - ilosc_paliwa);
            ilosc_paliwa = pojemnosc_baku;
            cena_paliwa = cena[i];
        }
        ilosc_paliwa -= odl[i];
    }

    cout << koszt << "\n";
}