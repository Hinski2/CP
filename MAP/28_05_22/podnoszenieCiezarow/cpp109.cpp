#include <bits/stdc++.h>
using namespace std;

const int maks = 5e5 + 15;
int n;

long long arr[maks];
long long pre[maks], suf[maks];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }

    //liczenie pufikso-prefiksów
    pre[1] = arr[1];
    suf[n] = arr[n];

    for(int i = 2; i <= n; i++)
    {
        pre[i] = __gcd(pre[i - 1], arr[i]);
    }

    for(int i = n - 1; i >= 1; i--)
    {
        suf[i] = __gcd(suf[i + 1], arr[i]);
    }

    long long maksimum = suf[2];
    int idx = 1;

    for(int i = 2; i < n; i++)
    {
        long long nwd = __gcd(pre[i - 1], suf[i + 1]);
        if(nwd > maksimum)
        {
            maksimum = nwd;
            idx = i;
        }
    }

    if(pre[n - 1] > maksimum) idx = n;
    cout<<idx<<"\n";
}