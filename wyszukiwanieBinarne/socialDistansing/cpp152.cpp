#include <bits/stdc++.h>
using namespace std;

const long long mak = 1LL * 1e18 + 16;
int n, m;

vector<pair<long long, long long>>space;

bool sprawdzenie(long long mid)
{
    long long count = 0, last = -mak;
    for(auto u: space)
    {
        long long a = u.first;
        long long b = u.second;

        if(a - last >= mid)
        {
            last = a;
            count++;

            if(count == n) return true;

        }
        while(last + mid <= b)
        {
            count++;
            last += mid;

            if(count == n) return true;
        }
    }

    return false;
}

long long bin_search()
{
    long long l = 1, r = mak, mid;
    long long ans = 0;

    while(l <= r)
    {
        mid = (l + r) / 2;

        bool s = sprawdzenie(mid);

        if(s)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    //wczytywanie
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        long long a, b;
        cin>>a>>b;

        space.push_back({a, b});
    }
    //liczenie
    sort(space.begin(), space.end());
    cout<<bin_search()<<"\n";
}