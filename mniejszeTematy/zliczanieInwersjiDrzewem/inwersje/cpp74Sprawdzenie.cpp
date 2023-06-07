#include <bits/stdc++.h>
using namespace std;

long long inwersje;
int n,liczba[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>liczba[i];
	}

	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			inwersje+=(liczba[i]>liczba[j]);
		}
	}

	sort(liczba, liczba+n+1);
	for(int i=1;i<=n;i++)
	{
		cout<<liczba[i]<<" ";
	}

	cout<<endl<<inwersje<<endl;
}