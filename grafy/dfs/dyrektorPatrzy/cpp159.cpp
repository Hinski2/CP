#include <bits/stdc++.h>
using namespace std;

const int mak = 5e5 + 15;

int n, q;
int idx = 1, pre[mak], post[mak];

vector<int>G[mak];

void orderowanie(int v, int p = -1)
{
	pre[v] = idx++;
	for(auto u: G[v])
	{
		if(u != p)
		{
			orderowanie(u, v);
		}
	}
	post[v] = idx++;
}

void sprawdzenie(int a, int b, int ban)
{	
	//a i b jest zbanowane
	if((pre[ban] < pre[a] && pre[a] < post[ban]) && (pre[ban] < pre[b] && pre[b] < post[ban]))
	{
		cout<<"Dyrektor patrzy\n";
	}

	//a jest zbanowane
	else if(pre[ban] < pre[a] && pre[a] < post[ban]) 
	{
		cout<<"Tylko B\n";
	}

	//b jest zbanowae
	else if(pre[ban] < pre[b] && pre[b] < post[ban])
	{
		cout<<"Tylko A\n";
	}

	//nikt nie jest zbanowany
	else
	{
		cout<<"Droga wolna\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin>>n>>q;
	for(int b = 2; b <= n; b++)
	{
		int a;
		cin>>a;

		G[a].push_back(b);
	}

	//liczenie
	orderowanie(1);

	//odpowaidanie na zapytania
	while(q--)
	{
		int a, b, ban;
		cin>>a>>b>>ban;
		
		sprawdzenie(a, b, ban);
	}
}