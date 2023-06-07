#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, t;
int arr[mak];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>t;

	for(int i = 1; i <= n; i++)
	{
		cin>>arr[i];
	}

	//gasielnica
	int r = 1, l = 1, suma = 0, ans = 0, wynik = 0;

	while(r <= n)
	{
		if(suma  + arr[r] <= t)
		{
			suma += arr[r];
			r++;
			wynik++;
			ans = max(ans, wynik);
		}
		else
		{
			suma -= arr[l];
			l++;
			wynik--;
		}
	}
	cout<<ans<<"\n";
}