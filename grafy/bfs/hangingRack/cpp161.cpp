#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mak = 1e6 + 15;

long long n;
long long ans;
long long k;

long long dp[mak];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n >> k;

	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = (dp[i - 1] * 2) % mod;
	}

	k--;
	while(n)
	{
		if(k % 2 == 1)
		{
			ans = (ans + dp[n - 1]) % mod;
		}

		n--;
		k >>= 1;
	}

	ans = (ans + 1) % mod;

	cout << ans << "\n";
}