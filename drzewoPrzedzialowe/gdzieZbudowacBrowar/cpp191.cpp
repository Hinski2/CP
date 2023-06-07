#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mak = 10'005;

int n;
ll zapotzebowanie_miasta[mak], odleglosc[mak];

int l, r;
ll total_zapotrzebowanie_l, total_zapotrzebowanie_r;
ll dystans_do_l, dystans_do_r;

ll koszt, koszt_minimalny;

void popraw_granice()
{
    while(dystans_do_r + odleglosc[r] < dystans_do_l)
    {
        koszt += zapotzebowanie_miasta[l] * (dystans_do_r + odleglosc[r]);
        koszt -= zapotzebowanie_miasta[l] * dystans_do_l;

        total_zapotrzebowanie_r += zapotzebowanie_miasta[l];
        total_zapotrzebowanie_l -= zapotzebowanie_miasta[l];

        dystans_do_r += odleglosc[r];
        dystans_do_l -= odleglosc[l];

        r = (r % n) + 1;
        l = (l % n) + 1;
    }
}

void pre_procesing()
{
    r = 1;
    l = 2;

    for(int i = n; i >= 2; i--)
    {
        dystans_do_l += odleglosc[i];
        total_zapotrzebowanie_l += zapotzebowanie_miasta[i];

        koszt += dystans_do_l * zapotzebowanie_miasta[i];
    }

    popraw_granice();

    koszt_minimalny = koszt;
}

void liczenie()
{
    for(int i = 2; i <= n; i++)
    {
        int dystans = odleglosc[i - 1];

        koszt += (total_zapotrzebowanie_l + zapotzebowanie_miasta[i - 1]) * dystans;
        koszt -= total_zapotrzebowanie_r * dystans;

        total_zapotrzebowanie_r -= zapotzebowanie_miasta[i];
        total_zapotrzebowanie_l += zapotzebowanie_miasta[i - 1];

        dystans_do_r -= dystans;
        dystans_do_l += dystans;

        popraw_granice();

        koszt_minimalny = min(koszt, koszt_minimalny);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> zapotzebowanie_miasta[i] >> odleglosc[i];
    }

    //pre procesing
    pre_procesing();
    liczenie();

    cout << koszt_minimalny << "\n";
}