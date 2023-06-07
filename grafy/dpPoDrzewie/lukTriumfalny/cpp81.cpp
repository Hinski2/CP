#include <bits/stdc++.h>
using namespace std;

const int maksimum=3e5+15;

int n, dp[maksimum],dodawanie;
vector<int>v[maksimum];

void dfs(int w, int rodzic=-1)
{
	dp[w]=1;

	for(auto i:v[w])
	{
		if(i!=rodzic)
		{
			dfs(i, w);
			dp[w]+=dp[i];
		}
	}

	dp[w]=max(1, dp[w]-dodawanie);
}

bool sprawdzenie(int mid)
{
	dodawanie=mid;
	dfs(1);
	return dp[1]==1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //magiczna linijka

	//wczytywanie danych
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a, b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	//wyszukiwanie binarne po wyniku
	int l=0, r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(sprawdzenie(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<(l+r)/2<<"\n";
}
