#include <bits/stdc++.h>
using namespace std;

const int mak = 8e6 + 15;

int n, m;
int lps[mak];
char wzorzec[mak], tekst[mak];

void wyznacz_lps()
{
    int len = 0, i = 1;
    lps[0] = 0;

    while(i < n)
    {
        if(wzorzec[i] == wzorzec[len])
        {
            lps[i++] = ++len;
        }
        else
        {
            if(len) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
}

void kmp()
{
    int i = 0, j = 0;
    while(i < m)
    {
        if(tekst[i] == wzorzec[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j) j = lps[j - 1];
            else i++;
        }

        if(j == n)
        {
            cout << i - j + 1<< "\n";
            j = lps[j - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> wzorzec[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> tekst[i];
    }

    //liczenie
    wyznacz_lps(); //lps - longest prefikso sufiks
    kmp();

}