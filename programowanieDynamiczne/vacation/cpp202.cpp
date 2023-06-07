#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n;
int dp[mak][3], points[mak][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> points[i][0] >> points[i][1] >> points[i][2]; 
	}

	//liczenie
	dp[1][0] = points[1][0];
	dp[1][1] = points[1][1];
	dp[1][2] = points[1][2];

	for(int i = 2; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][1] + points[i][0], dp[i - 1][2] + points[i][0]);
		dp[i][1] = max(dp[i - 1][0] + points[i][1], dp[i - 1][2] + points[i][1]);
		dp[i][2] = max(dp[i - 1][0] + points[i][2], dp[i - 1][1] + points[i][2]);
	}

	int ans = max(dp[n][0], dp[n][1]);
	ans = max(ans, dp[n][2]);

	//wypisywanie wyniku
	cout << ans << "\n";

}