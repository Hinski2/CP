//numer zgłoszenea: 30680180
//nazwa na spoj'u: hinski2
//link do profilu: https://www.spoj.com/users/hinski2/
//link do zgłoszenia: https://www.spoj.com/status/QTREE,hinski2/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int Log = 14;
const int base = 1 << 14;

struct para{
	int a;
	int b;
	int s;
};

int n, tajmer;
vector<int>tree;
vector<vector<pair<int, int>>>G; //v, cost;
vector<vector<int>>up;
vector<para>node;
vector<int>sajz, order, koniec, hi;

void wczytaj(){
	tajmer = 0;
	G.clear();
	hi.clear();
	node.clear();
	up.clear();
	order.clear();
	sajz.clear();
	tree.clear();
	koniec.clear();

	cin >> n;
	G.resize(n + 1);
	hi.resize(n + 1);
	order.resize(n + 1);
	koniec.resize(n + 1);
	node.resize(n + 1);
	up.resize(n + 1, vector<int>(Log));
	sajz.resize(n + 1, 1);
	tree.resize(base << 1);

	int a, b, s;
	for(int i = 1; i < n; i++){
		cin >> a >> b >> s;

		node[i] = {a, b, s};
		G[a].push_back({b, s});
		G[b].push_back({a, s});

	}
}

void compute_up(int v, int p = 1){
	up[v][0] = p;
	for(int i = 1; i < Log; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for(auto u: G[v])
		if(u.fi != p) compute_up(u.fi, v);
}

void compute_sajz(int v, int h, int p = 0){
	hi[v] = h;
	for(auto u: G[v])
		if(u.fi != p){
			compute_sajz(u.fi, h + 1, v);
			sajz[v] += sajz[u.fi];
		}
}

void compute_order(int v, int p = 0){
	order[v] = tajmer++;
	
	int heavy = 0;
	for(auto u: G[v])
		if(u.fi != p && sajz[u.fi] > sajz[v] / 2){
			heavy = u.fi;
			compute_order(heavy, v);
		}
	for(auto u: G[v])
		if(u.fi != p && u.fi != heavy)
			compute_order(u.fi, v);
}

void compute_koniec(int v, int p = 0){
	for(auto u: G[v])
		if(u.fi != p){
			if(sajz[u.fi] > sajz[v] / 2) koniec[u.fi] = koniec[v];
			else koniec[u.fi] = u.fi;

            compute_koniec(u.fi, v);
		}
}

int lca(int a, int b){
	if(hi[a] < hi[b]) swap(a, b);
	int k = hi[a] - hi[b];

	for(int i = Log - 1; i >= 0; i--)
		if(k & (1 << i)) a = up[a][i];

	if(a == b) return a;

	for(int i = Log - 1; i >= 0; i--)
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}

	return up[a][0];
}

void tree_update(int v, int val){
    v += base;

    tree[v] = val;
    v >>= 1;

    while(v){
        tree[v] = max(tree[v << 1], tree[(v << 1) + 1]);
        v >>= 1;
    }
}

int tree_querry(int a, int b){
    int ans = 0;
    a += base;
    b += base;

    ans = max(tree[a], tree[b]);
    while(a >> 1 != b >> 1){
        if(a % 2 == 0) ans = max(ans, tree[a + 1]);
        if(b % 2 == 1) ans = max(ans, tree[b - 1]); 

        a >>= 1;
        b >>= 1;
    }

    return ans;
}

void make_tree(){
	for(auto u: node){
		int a = order[u.a];
		int b = order[u.b];

		if(a < b) swap(a, b);
        
        tree_update(a, u.s);
    }
}

int compute_path(int v, int c){
    int maks = 0;
    while(v != c){
        int p_z, k_z;
        bool heavy = false;
        if(sajz[v] > sajz[up[v][0]] / 2) heavy = true;

        if(heavy){
            if(koniec[v] != koniec[c]){
                p_z = order[koniec[v]] + 1;
                k_z = order[v];
                
                v = koniec[v];
            }
            else{
                p_z = order[c] + 1;
                k_z = order[v];

                v = c;
            }
        }
        else{
            p_z = order[v];
            k_z = order[v];

            v = up[v][0];
        }

        maks = max(maks, tree_querry(p_z, k_z));
    }

    return maks;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while(t--){
		//preprocesing
		wczytaj();
		compute_up(1);
		compute_sajz(1, 0);
		compute_order(1);

        koniec[1] = 1;
		compute_koniec(1);
		make_tree();

		//przetwarzane zapytań
		string s;
		while(cin >> s && s != "DONE"){
			if(s == "CHANGE"){
                int idx, val;
                cin >> idx >> val;

                int a = order[node[idx].a];
                int b = order[node[idx].b];

                if(a < b) swap(a, b);

                tree_update(a, val);
			}
			else{
				int a, b;
				cin >> a >> b;

				int c = lca(a, b);
				cout << max(compute_path(a, c), compute_path(b, c)) << '\n';
			}
		}
	}
}