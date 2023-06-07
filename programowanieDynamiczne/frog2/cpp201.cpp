#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, k;
int h[mak];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}

	//liczenie
	vector<int>dp(n + 1, INT_MAX);
	dp[1] = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(i + j > n) break;
			dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
		}
	}

	//wypisywanie
	cout << dp[n] << "\n";
	// for(int i = 1; i <= n; i++) cout << dp[i] << endl;
}