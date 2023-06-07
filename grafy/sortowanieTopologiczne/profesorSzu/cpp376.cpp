#include<bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;
const int inf = 36500;

int n, m;
int max_ans = -1;

vector<int>G[mak];
vector<int>in, vis, ways;
vector<bool>in_stack;

void dfs1(int v, int idx){
	in_stack[v] = true;
	vis[v]++;

	for(auto u: G[v]){
		if(vis[u] < idx){
			dfs1(u, idx);
		}
		else if(in_stack[u]){
			max_ans = inf;
			vis[v] = idx + 1;
		}
	}

	in_stack[v] = false;
}

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		G[b].push_back(a);
	}
}

int main(){
	//wczytanie
	wczytaj();

	//liczenie
	in_stack.resize(n + 2);
	vis.resize(n + 2);

	dfs1(n + 1, 1);
	for(int i = 1; i <= n + 1; i++)
		if(vis[i] == 2)
			dfs1(i, 2);

	in_stack.clear();
	in_stack.shrink_to_fit();

	ways.resize(n + 2);
	for(int i = 1; i <= n; i++){
		if(vis[i] >= 2)
			ways[i] = inf;
		else if(!vis[i])
			ways[i] = -1;
	}

	vis.clear();
	vis.shrink_to_fit();

	in.resize(n + 2);
	for(int i = 1; i <= n + 1; i++)
		if(ways[i] == 0)
			for(auto u: G[i])
				in[u]++;

	if(ways[n + 1] != inf){
		queue<int>kolejka;
		kolejka.push(n + 1);

		ways[n + 1] = 1;
		while(!kolejka.empty()){
			int v = kolejka.front();
			kolejka.pop();

			for(auto u: G[v]){
				in[u]--;
				if(!in[u]) kolejka.push(u);

				ways[u] = min(inf, ways[u] + ways[v]);
				max_ans = max(max_ans, ways[u]);
			}
		}
	}

	int ans_sajz = 0;
	for(int i = 1; i <= n; i++)
		if(ways[i] >= max_ans) ans_sajz++;

	if(max_ans == inf) cout << "zawsze\n";
	else cout << max_ans << '\n';		

	cout << ans_sajz << '\n';
	for(int i = 1; i <= n; i++)
		if(ways[i] >= max_ans) cout << i << ' ';
	cout << '\n';
}






