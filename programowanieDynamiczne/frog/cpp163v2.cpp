#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n;
int arr[mak];
int cost[mak];

bool odwiedzony[mak];

int liczenie(int x)
{
    if(odwiedzony[x]) return cost[x];
    
    odwiedzony[x] = true;
    int case1 = liczenie(x - 1) + abs(arr[x] - arr[x - 1]);
    int case2 = liczenie(x - 2) + abs(arr[x] - arr[x - 2]);

    return cost[x] = min(case1, case2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

	//wczytywanie
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>arr[i];
	}

	//liczenie
    odwiedzony[1] = odwiedzony[2] = true;

	cost[1] = 0;
	cost[2] = abs(arr[1] - arr[2]);

    liczenie(n);
	cout << cost[n] << "\n";
}