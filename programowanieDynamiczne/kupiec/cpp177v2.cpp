#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mak = 1e6 + 15;

int n;
int koszt[mak], travel[mak];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n; 
    for(int i = 1; i <= n; i++)
    {
        cin >> koszt[i];
    }
    for(int i = 1; i < n; i++)
    {
        cin >> travel[i];
    }

    ll best_sum = 0;
    ll current_sum = 0;

    int l = 1;
    ll droga = travel[1];
    for(int i = 1; i < n; i++)
    {
        ll x1 = koszt[i + 1] - koszt[i] - travel[i];
        ll x2 = koszt[i + 1] - koszt[l] - droga;

        if(x1 > x2 && x1 > 0)
        {
            l = i;
            droga = travel[i];
        }

        current_sum = max(x1, x2);
        best_sum = max(best_sum, current_sum);
    }

    current_sum = 0;
    int r = n;
    droga = travel[n - 1];
    for(int i = n; i > 1; i--)
    {
        ll x1 = koszt[i - 1] - koszt[i] - travel[i -  1];
        ll x2 = koszt[i - 1] - koszt[l] - droga;

        if(x1 >= x2 && x1 > 0)
        {
            r = i;
            droga = travel[i] - 1;
        }

        current_sum = max(x1, x2);
        best_sum = max(best_sum, current_sum);
    } 

    cout << best_sum << "\n";
}