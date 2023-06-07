#include<bits/stdc++.h>
using namespace std;

const int LOG = 16;

int n, q, ans;

vector<vector<int>>G, up;
vector<int>depth;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	G.resize(n + 1);
	up.resize(n + 1, vector<int>(LOG));
	depth.resize(n + 1);
	
	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void make_up(int v){
	for(int skok = 1; skok < LOG; skok++)
        up[v][skok] = up[up[v][skok - 1]][skok - 1];
}

void make_depth(int v, int h, int p){
	depth[v] = h;
	up[v][0] = p;
    make_up(v);

	for(auto u: G[v])
		if(u != p) make_depth(u, h + 1, v);
}

int travel(int a, int b){
	if(depth[a] < depth[b]) //a jest glebiej
		swap(a, b);

	int k = depth[a] - depth[b];
	for(int i = LOG - 1; i > -1; i--)
		if(k & (1 << i)) a = up[a][i];

	if(a == b){
		return a;
	}

	for(int i = LOG - 1; i > -1; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}

	a = up[a][0];
	b = up[b][0];

    return a;
}

int main(){
	wczytaj();
	make_depth(1, 0, 0);

    int a, b = 1;
	cin >> q;
	while(q--){
        a = b;
        cin >> b;

        ans += depth[a] + depth[b] - 2 * depth[travel(a, b)];
	}

	cout << ans << '\n';
}




