#include<bits/stdc++.h>
using namespace std;

const int maksimum = 5015;
const int inf = 1e9 + 15;

int n, m;
int waga[maksimum];
int dist[maksimum], oDist[maksimum];	//dystans od 1 do wierzchołka, dystans od wierzchołka do 1

bool odwiedzony[maksimum];	

vector<pair<int, int>> G[maksimum];		//normalny graf
vector<pair<int, int>> Og[maksimum];	//graf transponowany

priority_queue<pair<int, int>> p;	//kolejka priorytetowa do zwykłego grafu
priority_queue<pair<int, int>> op;	//kolejka priorytetowa do grafu transponowanego


void dijkstra() //dijkstra na normalnym grafie
{
	p.push({0, 1}); //odległośc do wierzchołka, wierzchołek 

	while(!p.empty())
	{
		int odl = p.top().first;	//odleglosć do wierzchołka 
		int v = p.top().second;		//wierzchołek 

		p.pop();

		if(!odwiedzony[v])
		{
			odwiedzony[v] = true;
			dist[v] = -odl; //minus ponieważ kolejka priorytetowa trzyma wartości ujemne 

			for(auto u: G[v])
			{
				if(!odwiedzony[u.second])
				{
					p.push({odl + u.first, u.second});
				}
			}
		}
	}

}

void oDijkstra() //dijkstra na grafie transponowanym
{
	op.push({0, 1}); //odległośc do wierzchołka, wierzchołek 

	while(!op.empty())
	{
		int odl = op.top().first;	//odleglosć do wierzchołka 
		int v = op.top().second;		//wierzchołek 

		op.pop();

		if(!odwiedzony[v])
		{
			odwiedzony[v] = true;
			oDist[v] = -odl;

			for(auto u: Og[v])
			{
				if(!odwiedzony[u.second])
				{
					op.push({odl + u.first, u.second});
				}
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>waga[i];
	}
	cin>>m;
	for(int i = 1; i <= m; i++)
	{
		int a, b, dystans;
		cin>>a>>b>>dystans;

		G[a].push_back({-dystans, b});	//graf normalny
		Og[b].push_back({-dystans, a}); 	//graf transponowany
	}

	for(int i = 1; i <= 5000; i++)
	{
		dist[i] = inf;
		oDist[i] = inf;
	}

	dist[1] = 0;
	oDist[1] = 0;

	dijkstra();

	for(int i = 0; i <= 5005; i++)	//czyszczenie tablicy odwiedzeń 
	{
		odwiedzony[i] = 0;
	}

	oDijkstra();

	//liczenie odpowiedzi
	long long ans = inf;
	for(int i = 1; i <= n; i++)
	{
		ans = min(ans, (long long)(dist[i] + oDist[i] + waga[i]/2));
	}

	cout<<ans<<"\n";
}