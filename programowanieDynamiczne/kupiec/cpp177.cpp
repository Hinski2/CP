#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mak = 1e6 + 15;

int n;
int cost[mak], travelCost[mak];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }

    for(int i = 1; i < n; i++)
    {
        cin >> travelCost[i];
    }

    //liczenie
    if(n == 1)
    {
        cout << "0\n";
        return 0;
    }

    int l = 1;
    ll kosztPodruzy = 0;
    ll local_max = 0;
    ll global_max1 = 0;

    for(int i = 1; i < n; i++)
    {
        kosztPodruzy += travelCost[i];
        local_max = cost[i + 1] - cost[l] - kosztPodruzy;

        ll pojedynczy = cost[i + 1] - cost[i] - travelCost[i];
        if(pojedynczy > local_max)
        {
            local_max = pojedynczy;
            kosztPodruzy = cost[i];
            l = i;
        }

        global_max1 = max(global_max1, local_max);
    }

    int r = n;
    kosztPodruzy = 0;
    local_max = 0;
    ll global_max2 = 0;

    for(int i = n; i > 1; i--)
    {
        kosztPodruzy += travelCost[i - 1];
        local_max = cost[i - 1] - cost[r] - kosztPodruzy;

        ll pojedynczy = cost[i - 1] - cost[i] - travelCost[i - 1];
        if(pojedynczy > local_max)
        {
            local_max = pojedynczy;
            kosztPodruzy = travelCost[i - 1];
            r = i;
        }

        global_max2 = max(global_max2, local_max);
    }

    //wypisanie wyniku

    cout << max(global_max1, global_max2) << "\n";
}