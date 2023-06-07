#include <bits/stdc++.h>
using namespace std;

const int mak = 60005;
const int mak2 = 1e9;
const double eps = 0.000000001;

int n;
int speed[mak], pos[mak];

double sprawdzenie(double mid)
{
	double MAX = 0;

	for(int i = 1; i <= n; i++)
	{
		double s = abs(pos[i] - mid);
		double t = s / speed[i];

		MAX = max(MAX, t);
	}

	return MAX;
}

int wyznaczanie()
{
	double ans = mak2;
	double l = 1, r = mak2, mid = (l + r) / 2;
	
	while(r - l > eps)
	{
		double t1 = sprawdzenie((l + mid) / 2);
		double t2 = sprawdzenie((r + mid) / 2);

		if(t1 < t2)
		{
			r = mid;
			ans = t1; 
			mid = (l + mid) / 2;
		}
		else
		{
			l = mid;
			ans = t2;
			mid = (r + mid) / 2;
		}
	}

	cout<<ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<fixed<<setprecision(10);

	//wczytywanie
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>pos[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin>>speed[i];
	}

	cout<<wyznaczanie()<<"\n";
} 