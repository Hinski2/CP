#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n;
int arr[mak];
int cost[mak];

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
	cost[1] = 0;
	cost[2] = abs(arr[1] - arr[2]);

	for(int i = 3; i <= n; i++)
	{
		cost[i] = min(cost[i - 1] + abs(arr[i - 1] - arr[i]), cost[i - 2] + abs(arr[i - 2] - arr[i]));
	}

	cout << cost[n] << "\n";
}