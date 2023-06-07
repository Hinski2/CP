#include <bits/stdc++.h>
using namespace std;

const int maksimum=5e5+15;
int liczbaPracownikow, maxRebel;

int podRobole[maksimum], x[maksimum];
double morale[maksimum];
double wynik;

vector<int>pracownik[maksimum];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<fixed<<setprecision(8);

	cin>>liczbaPracownikow>>maxRebel;

	for(int i=2;i<=liczbaPracownikow;i++)
	{
		int x;
		cin>>x;

		pracownik[x].push_back(i);
	}

	for(int i=liczbaPracownikow;i>=1;i--)
	{
		x[i]=1;

		morale[i]=(pracownik[i].size()==0 ? 1 : 0);

		for(auto y:pracownik[i])
		{
			x[i]+=x[y];
		}

		for(auto y:pracownik[i])
		{
			morale[i]=max(morale[i], min(morale[y], double(x[y]) / (x[i]-1) ));
		}

		if(x[i]>maxRebel)
		{
			wynik=max(wynik, morale[i]);
		}
	}

	cout<<wynik<<"\n";
}