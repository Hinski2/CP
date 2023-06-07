#include <bits/stdc++.h>
using namespace std;

const int Log = 17;
const int inf = 1e9 + 7;

int n, q;
int c;

vector<vector<int>>G, up, distToGcp;
vector<int>hi, nearest, Gcp;
vector<bool>ban;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	G.resize(n + 1);
	Gcp.resize(n + 1);
	ban.resize(n + 1);
	nearest.resize(n + 1, inf);
	hi.resize(n + 1);
	distToGcp.resize(n + 1, vector<int>(Log));
	up.resize(n + 1, vector<int>(Log));

	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void compute_hi(int v, int p = 0){
    hi[v] = 1;
	for(auto u: G[v])
		if(!ban[u] && u != p){
		     	compute_hi(u, v);
			    hi[v] += hi[u]; 
		}
}

void compute_hi2(int v, int p = 0){
	for(auto u: G[v])
		if(u != p){
			hi[u] = hi[v] + 1;
			compute_hi2(u, v);
		}
}

void find_c(int v, int prim, int p = 0){
	int naj = -1, ile = -1;
	for(auto u: G[v])
		if(!ban[u] && u != p)
			if(hi[u] > ile){
				ile = hi[u];
				naj = u;
			}

    if(naj == -1) return;
	if(ile <= (hi[prim] / 2)) c = v;
	else find_c(naj, prim, v);
}

void make_centroid(int v, int p = 0){
    int local_c = c = v;
	compute_hi(v);
	find_c(v, v);

    local_c = c;
	ban[local_c] = true;
	if(p) Gcp[local_c] = p;
	else Gcp[local_c] = local_c;

	for(auto u: G[local_c])
		if(!ban[u] && u != p)
			make_centroid(u, local_c);
}

void compute_up(int v, int p = 0){
	up[v][0] = p;
	for(int i = 1; i < Log; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for(auto u: G[v])
		if(u != p) compute_up(u, v);
}

int lca(int a, int b){
	if(hi[a] < hi[b]) swap(a, b);

	int k = hi[a] - hi[b];
	for(int i = Log - 1; i >= 0; i--) 
		if(k & (1 << i)) a = up[a][i];

	if(a == b) return hi[a];
	for(int i = Log - 1; i >= 0; i--)
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}

	a = up[a][0];
	b = up[b][0];

	return hi[a];
}

void precompute_dist(int v){
	int p = Gcp[v];
	for(int i = 0; i < Log; i++){
		distToGcp[v][i] = hi[v] + hi[p] - 2 * lca(v, p);
		p = Gcp[p];
	}
}

void paint(int v){
	int p = Gcp[v];
	nearest[v] = 0;
	for(int i = 0; i < Log; i++){
		nearest[p] = min(nearest[p], distToGcp[v][i]);
		p = Gcp[p];
	}
}

void update(int v){
    int p = Gcp[v];
    for(int i = 0; i < Log; i++){
        nearest[v] = min(nearest[v], distToGcp[v][i] + nearest[p]);
        p = Gcp[p];
    }
}

void querry(int v){
    update(v);
	if(nearest[v] != inf){
		cout << nearest[v] << '\n';
		return;
	}

	int p = Gcp[v], idx = 0;;
	while(nearest[p] == inf){
		p = Gcp[p];
        idx++;
    }

	cout << nearest[p] + distToGcp[v][idx] << '\n';
}

int main(){
	wczytaj();
	make_centroid(1);
	compute_up(1);

	hi[1] = 0;
	compute_hi2(1);

	for(int i = 1; i <= n; i++)
		precompute_dist(i);

	paint(1);
	while(q--){
		int typ, v;
		cin >> typ >> v;
		
		if(typ == 1) paint(v);
		else querry(v);
	}
}
