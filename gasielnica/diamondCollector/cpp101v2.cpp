#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int n, k;
int arr[mak];
int pre[mak], suf[mak];

void gosielnica1()
{
	int l = 1, r = 0, length = 0;

	while(r < n)
	{
		if(length == 0 || arr[r + 1] - arr[l] <= k)
		{
			r++;
			length++;
			pre[r] = max(length, pre[r - 1]);
		}
		else
		{
			length--;
			l++; 
		}
	}

	length = 0;
	l = n + 1;
	r = n;

	while(l > 1)
	{
		if(length == 0 || arr[r] - arr[l - 1] <= k)
		{
			l--;
			length++;
			suf[l] = max(length, suf[l + 1]);
		}
		else
		{
			length--;
			r--;
		}
	}
}

int Merge()
{
	int ans = 0;

	for(int i = 0; i <= n; i++)
	{
		int akt = pre[i] + suf[i + 1];
		ans = max(ans, akt);
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	//wczytywanie
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
	{
		cin>>arr[i];
	}

	//liczenie
	sort(arr + 1, arr + n + 1);

	gosielnica1();

	cout<<Merge()<<"\n";
}