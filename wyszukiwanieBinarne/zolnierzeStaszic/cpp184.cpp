#include <bits/stdc++.h>
using namespace std;

const int mak = 1e9 + 15;
const int maks = 500'005;

int arr[maks];

bool check(int n, int mid)
{
    int akt_liczba = 0;
    int akt_rzad = 1;

    for(int i = 1; i <= n; i++)
    {
        if(arr[i] > mid) return 0;

        if(akt_liczba + arr[i] <= mid) akt_liczba += arr[i];
        else
        {
            akt_rzad++;
            akt_liczba = arr[i];
        }
    }

    return (akt_rzad <= mid);
}

int wyszukiwanie(int n)
{
    int l = 1, r = mak;

    while(l < r)
    {
        int mid = (l + r) / 2;

        if(check(n, mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return r;
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

    cout << wyszukiwanie(n) << "\n";
}