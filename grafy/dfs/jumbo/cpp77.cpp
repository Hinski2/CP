#include <bits/stdc++.h>
using namespace std;

const int maksimum=1e5+15;
int ileSloni, idx=1;
int in[maksimum], out[maksimum];

bool visited[maksimum];

vector<int>fan[maksimum];

void dfs(int wierzcholek)
{
	visited[wierzcholek]=true;
	in[wierzcholek]=idx++;

	for(int i=0;i<fan[wierzcholek].size();i++)
	{
		if(!visited[fan[wierzcholek][i]])
		{
			dfs(fan[wierzcholek][i]);
		}
	}

	out[wierzcholek]=idx++;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>ileSloni;

	for(int i=1;i<ileSloni;i++)
	{
		int x;
		cin>>x;
		fan[x].push_back(i);
		fan[i].push_back(x);
	}

	dfs(0);

	int a, b;
	while(1)
	{
		cin>>a;
		if(a==-1)return 0;
		cin>>b;

		if(in[a]<in[b] && out[a]>out[b])
		{
			cout<<"TAK"<<"\n";
		}
		else
		{
			cout<<"NIE"<<"\n";
		}
	}

	return 0;
}