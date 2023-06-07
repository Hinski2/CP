#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mak = 1'000'000'005;

ll ans;
void wyszukiwanie(ll szukana)
{
	ll l = 0, r = mak;

	while(l <= r)
	{
		ll mid = (l + r) / 2;

		if(mid * mid > szukana)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	ll n;
	cin >> n;

	//liczenie
	wyszukiwanie(n);

	//wypisywanie wyniku
	cout << ans << "\n";
}