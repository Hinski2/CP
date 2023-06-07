#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, q;
int sum[mak][4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    //*wczytywanie
    cin>>n>>q;

    sum[0][1] = 0;
    sum[0][2] = 0;
    sum[0][3] = 0;

    for(int i = 1; i <= n; i++)
    {
        sum[i][1] = sum[i - 1][1];
        sum[i][2] = sum[i - 1][2];
        sum[i][3] = sum[i - 1][3];

        int x;
        cin>>x;
        sum[i][x]++;
    }

    while(q--)
    {
        int l, r;
        cin>>l>>r;

        int a1 = sum[r][1] - sum[l - 1][1];
        int a2 = sum[r][2] - sum[l - 1][2];
        int a3 = sum[r][3] - sum[l - 1][3];

        cout<<a1<<" "<<a2<<" "<<a3<<"\n";
    }
}