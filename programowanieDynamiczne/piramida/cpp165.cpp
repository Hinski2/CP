#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n, mod;
bool bezpiecznie[mak];

int dp[mak];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n >> mod;
	for(int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;

		if(c == '1') bezpiecznie[i] = true;
	}

	//liczenie
	dp[1] = 1;

	for(int i = 1; i <= n; i++)
	{
		if(bezpiecznie[i])
		{
			for(int j = 1; j <= 6; j++)
			{
				if(bezpiecznie[i + j]) dp[i + j] = (dp[i + j] + dp[i]) % mod;
			}
		}
	}

	cout << dp[n] << "\n";
}