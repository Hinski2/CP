#include <bits/stdc++.h>
using namespace std;

const int maks = 1e5 + 15;

int n, q;
int k[maks][4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    cin>>n>>q;

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;

        k[i][1] = k[i - 1][1];
        k[i][2] = k[i - 1][2];
        k[i][3] = k[i - 1][3];

        k[i][x]++;
    }


    for(int i = 1; i <= q; i++)
    {
        int a, b;
        cin>>a>>b;

        cout<<k[b][1] - k[a - 1][1] <<" "<< k[b][2] - k[a - 1][2] <<" "<< k[b][3] - k[a - 1][3] << "\n";
    }
}