#include <bits/stdc++.h>
using namespace std;

const int mak = 105; 

int n;
int arr[mak];
int cOne;
int cMax, gMax;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    //wczytywanie
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cOne += arr[i];

        if(arr[i]) arr[i] = -1;
        else arr[i] = 1;
    }

    if(cOne == n)
    {
        cout << n - 1 << "\n"; 
        return 0 ;
    }

    for(int i = 1; i <= n; i++)
    {
        cMax = max(arr[i], cMax + arr[i]);
        gMax = max(gMax, cMax);
    }

    cout << gMax + cOne << "\n";
}
