#include <bits/stdc++.h>
using namespace std;

const int pojemnosc = 1024;
const int mak = 15;

int n, s;
int licznik;
int szklanka[mak][mak];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //*wczytywanie
    cin>>n>>s;

    s *= pojemnosc;

    szklanka[1][1] += s;

    for(int poziom = 1; poziom <= n; poziom++)
    {
        for(int idx = 1; idx <= 10; idx++)
        {
            if(szklanka[poziom][idx] >= pojemnosc)
            {

                licznik++;

                szklanka[poziom][idx] -= pojemnosc;
                szklanka[poziom][idx] /= 2;

                szklanka[poziom + 1][idx] += szklanka[poziom][idx];
                szklanka[poziom + 1][idx + 1] += szklanka[poziom][idx];
            }
        }
    }

    cout<<licznik<<"\n";
}   