#include <bits/stdc++.h>
using namespace std;

const int mak = 1e5 + 15;

int n, t;
int book[mak];

int gosielnica()
{
	int l = 0, r = -1, sum = 0, ans = 0, wynik = 0;

	while(r < n - 1)
	{
		if(sum + book[r + 1] <= t)
		{
			r++;
			sum += book[r];

			wynik++;
			ans = max(ans, wynik);
		}
		else
		{
			sum -= book[l];
			l++;

			wynik--;
		}
	}

	return ans; 
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin>>n>>t;
	for(int i = 0; i < n; i++)
	{
		cin>>book[i];
	}

	cout<<gosielnica()<<"\n";
}