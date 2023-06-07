#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n, q;
int x[mak], y[mak];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n >> q;

    for(int i = 1; i <= n; i++) x[i] = i;
    for(int i = 1; i <= n; i++) y[i] = i;

    while(q--)
    {
        char c;
        cin >> c;

        if(c == 'W')
        {
            int a, b;
            cin >> a >> b;
            swap(x[a], x[b]);
        }
        else if(c == 'K')
        {
            int a, b;
            cin >> a >> b;
            swap(y[a], y[b]);
        }
        else
        {
            int a, b;
            cin >> a >> b;

            long long ans = 1LL * n * (x[a] - 1) + y[b];

            cout << ans << "\n";
        }
    }
}