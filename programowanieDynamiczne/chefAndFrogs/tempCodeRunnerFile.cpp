#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    long long n, r, q;
    cin >> n >> r >> q;

    vector<pair<long long, long long>>para(n);

    for(long long i = 0; i < n; i++)
    {
        cin >> para[i].first;
        para[i].second = i;
    }

    //liczenie
    sort(para.begin(), para.end());

    unordered_map<long long, long long>newPos;

    for(long long i = 0; i < n; i++)
    {
        newPos[para[i].second] = i;
    }

    vector<long long>dp(n, 0);

    for(long long i = 1; i < n; i++)
    {
        if(para[i].first - para[i - 1].first <= r)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 0;
        }
    }

    while(q--)
    {
        long long a, b;
        cin >> a >> b;

        a--;
        b--;

        a = newPos[a];
        b = newPos[b];

            if(a > b) swap(a, b);

            if(b - a <= dp[b]) cout << "YES\n";
            else cout << "NO\n";

    }
}