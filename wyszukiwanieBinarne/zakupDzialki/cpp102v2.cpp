#include <bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;

int n, q;
int dzialka[mak];

int nearest(int x)
{
	int ans = INT_MAX;
	int l = 1, r = n, mid;

	while(l <= r)
	{
		mid = (l + r) / 2;

		if(dzialka[mid] == x)
		{
			ans = 0;
			return ans;
		}
		else if(dzialka[mid] < x)
		{
			ans = min(ans, x - dzialka[mid]);
			l = mid + 1;
		}
		else
		{
			ans = min(ans, dzialka[mid] - x);
			r = mid - 1;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin>>n>>q;
	for(int i = 1; i <= n; i++)
	{
		cin>>dzialka[i];
	}

	while(q--)
	{
		int x;
		cin>>x;

		cout<<nearest(x)<<"\n";
	}
}