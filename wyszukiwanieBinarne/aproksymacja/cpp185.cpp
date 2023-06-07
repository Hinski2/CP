#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 5;
const double inf = 1e6; 
const double eps = 1e-6; 

int arr[mak];
int suf[mak];

bool check(int n, double mid)
{
    for(int i = 1; i <= n; i++)
    {
        if((double)suf[i] + (2 * mid) < arr[i]) return 0;
    }

    return 1;
}

double bs(int n)
{
    double l = 0, r = inf;

    while(r - l > eps)
    {
        double mid = (l + r) / 2;

        if(check(n, mid))
        {
            r = mid;
        }
        else
        {
            l = mid + eps;
        }
    }

    return l;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    int n;  
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    //liczenie
    suf[n] = arr[n];
    for(int i = n - 1; i >= 1; i--)
    {
        suf[i] = min(suf[i + 1], arr[i]);
    }

    double minimum = bs(n);
    cout << fixed << setprecision(5) << minimum << "\n";
    for(int i = 1; i <= n; i++)
    {
        cout << (double)suf[i] + minimum << "\n";
    }
}