#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, k;
int arr[mak];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    while(k--)
    {
        int od, ile, co_ile;
        cin>>od>>ile>>co_ile;

        int dod = od;
        for(int i = 1; i <= ile; i++)
        {
            arr[dod]++;
            dod += co_ile;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
}