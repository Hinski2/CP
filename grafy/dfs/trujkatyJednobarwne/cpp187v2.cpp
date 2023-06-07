#include <bits/stdc++.h>
using namespace std;

const int mak = 1005;

int n, m;
int red[mak];
int black;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        red[a]++;
        red[b]++;
    }

    for(int i = 1; i <= n; i++)
    {
        black += red[i] * (n - 1 - red[i]);
    }

    black /= 2;

    int wszystkie = (n * (n - 1) * (n - 2)) / 6;

    cout << wszystkie - black << "\n";
}