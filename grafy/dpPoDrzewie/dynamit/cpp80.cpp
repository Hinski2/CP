#include <bits/stdc++.h>
using namespace std;

const int maksimum=3e5+15; 
const int infinity=1e9; 

int n,m, dp[maksimum];
int dlugosc, licznik;
bool zamontowany[maksimum];

vector<int>jaskinia[maksimum];

void dfs(int wierzcholek, int rodzic=-1)
{
	int MIN=infinity, MAX=-infinity;

	for(auto i:jaskinia[wierzcholek])
	{
		if(i!=rodzic)
		{
			dfs(i,wierzcholek);
			MIN=min(MIN, dp[i]);
			MAX=max(MAX, dp[i]);
		}
	}

	if(MIN!=infinity && MIN+MAX>0)
	{
		dp[wierzcholek]=MAX-1;
	}
	else
	{
		if(MIN<0)
		{
			dp[wierzcholek]=MIN-1;
		}
		else
		{
			dp[wierzcholek]= zamontowany[wierzcholek] ? -1 : 0;
		}
	}

	if(dp[wierzcholek]==-(dlugosc+1))
	{
		dp[wierzcholek]=dlugosc;
		licznik++;
	}
}

bool sprawdzenie(int mid)
{
	licznik=0;
	dlugosc=mid;

	dfs(1);

	if(dp[1]<0)licznik++;

	return licznik<=m;
}



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	//magiczna linijka 

	//wczytywanie
	cin>>n>>m;		

	for(int i=1;i<=n;i++)
	{
		cin>>zamontowany[i];
	}

	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;

		jaskinia[a].push_back(b);
		jaskinia[b].push_back(a);
	}

	//koniec wczytywanie początek liczenia 
	int low=0, high=n;

	while(low<high)
	{
		int mid=(low+high)/2;

		if(sprawdzenie(mid))
		{
			high=mid;
		}
		
		else
		{
			low=mid+1;
		}
	}

	cout<<(low+high)/2<<"\n";
}
