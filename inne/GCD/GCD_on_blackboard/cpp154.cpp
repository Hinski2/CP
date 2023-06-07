#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n;
int arr[mak];
int pre[mak], suf[mak];

int bez[mak];

void prefiksowanie(int i, int a, int b)
{
    pre[i] = __gcd(a, b);
}

void sufiksowanie(int i, int a, int b)
{
    suf[i] = __gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }

    //liczenie
    pre[1] = arr[1];
    suf[n] = arr[n];

    for(int i = 2; i <= n; i++)
    {
        prefiksowanie(i, pre[i - 1], arr[i]);
    }
    for(int i = n - 1; i >= 1; i--)
    {
        sufiksowanie(i, arr[i], suf[i + 1]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
        {
            bez[i] = suf[i + 1];
        }
        else if(i == n)
        {
            bez[i] = pre[i - 1];
        }
        else
        {
            bez[i] = __gcd(pre[i - 1], suf[i + 1]);
        }

        ans = max(ans, bez[i]);
    }

    //wypisywanie wyniku
    cout<<ans<<"\n";
}