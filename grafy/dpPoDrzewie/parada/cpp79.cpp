#include <bits/stdc++.h>
using namespace std;

const int maksimum=2e5+15;

int ans[maksimum], n, dp[maksimum];

vector<int>v[maksimum];

void dfs(int wierzcholek, int rodzic=-1)
{
	int ileWierzcholkow=0;
	int w1=0, w2=0;

	for(int i=0;i<v[wierzcholek].size();i++)
	{
		if(v[wierzcholek][i]!=rodzic)
		{
			ileWierzcholkow++;
			dfs(v[wierzcholek][i], wierzcholek);

			if(w1<dp[v[wierzcholek][i]])
			{
				w2=w1;
				w1=dp[v[wierzcholek][i]];
			}
			else if(w2<dp[v[wierzcholek][i]])
			{
				w2=dp[v[wierzcholek][i]];
			}
		}
	}

	dp[wierzcholek]=max(ileWierzcholkow, ileWierzcholkow-1+w1);
	ans[wierzcholek]=ileWierzcholkow-1+w1;
	if(ileWierzcholkow>=2)
	{
		ans[wierzcholek]=max(ans[wierzcholek], w1+w2+ileWierzcholkow-2);
	}
	if(wierzcholek!=1)ans[wierzcholek]++;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 	//magiczna linijka

	//wczytywanie danych
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a, b;
		cin>>a>>b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	cout<<(*max_element(ans+1, ans+n+1))<<"\n";

}