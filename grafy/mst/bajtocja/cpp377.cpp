#include<bits/stdc++.h>
using namespace std;

const int Log = 14;
struct e{
	int gdzie;
	int waga;
	int idx;
};

struct q{
	int a;
	int b;
	int waga;
	int idx;
};

int n, m;
vector<q>querry;
vector<int>rep, sajz, ans, hi;
vector<vector<int>>jump, Max;
vector<vector<e>>G, Gm;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	querry.resize(m);
	hi.resize(n + 1);
	G.resize(n + 1);
	Gm.resize(n + 1);
	jump.resize(n + 1, vector<int>(Log));
	Max.resize(n + 1, vector<int>(Log));

	int a, b, s;
	for(int i = 1; i <= m; i++){
		cin >> a >> b >> s;

		querry[i - 1] = {a, b, s, i};
		G[a].push_back({b, s, i});
		G[b].push_back({a, s, i});
	}
}

//czy a ma stać przed b
bool cmp(const q &a, const q &b){
	if(a.waga != b.waga) return a.waga < b.waga;
	return a.idx < b.idx;
}

int find(int v){
	if(v == rep[v]) return v;
	return rep[v] = find(rep[v]);
}

void polacz(q edg){
	int a = find(edg.a);
	int b = find(edg.b);

	if(a == b) return;
	if(sajz[a] < sajz[b]) swap(a, b);

	Gm[a].push_back({b, edg.waga, edg.idx});
	Gm[b].push_back({a, edg.waga, edg.idx});

	ans[edg.idx] = true;
	rep[b] = a;
	sajz[a] += sajz[b];	
}

void make_mst(){
	sort(querry.begin(), querry.end(), cmp);

	rep.resize(n + 1);
	ans.resize(m + 1);
    sajz.resize(n + 1);
	for(int i = 1; i <= n; i++){
		rep[i] = i;
		sajz[i] = 1;
	}

	for(auto u: querry){
		polacz(u);
	}
}

void make_lca(int v, int up = 0, int p = 0, int h = 1){
	jump[v][0] = p;
	hi[v] = h;
	Max[v][0] = up;

	for(int i = 1; i < Log; i++){
		jump[v][i] = jump[jump[v][i - 1]][i - 1];
		Max[v][i] = max(Max[v][i - 1], Max[jump[v][i - 1]][i - 1]);
	}

	for(auto u: Gm[v])
		if(u.gdzie != p) make_lca(u.gdzie, u.waga, v, h + 1);
}

int find_lca(int a, int b){
	if(hi[a] < hi[b]) swap(a, b);
	int k = hi[a] - hi[b];

	for(int i = Log - 1; i >= 0; i--)
		if(k & (1 << i)) a = jump[a][i];

	if(a == b) return a;
	for(int i = Log - 1; i >= 0; i--)
		if(jump[a][i] != jump[b][i]){
			a = jump[a][i];
			b = jump[b][i];
		}

	return jump[a][0];
}


void policz_ans(){
	for(auto u: querry){
        int a = u.a, b = u.b;
		int v = find_lca(u.a, u.b);
		int al = hi[u.a] - hi[v], bl = hi[u.b] - hi[v];
        int maxa = 0, maxb = 0;

        for(int i = Log - 1; i >= 0; i--){
            if(al & (1 << i)){
                maxa = max(maxa, Max[a][i]);
                a = jump[a][i];
            }
            if(bl & (1 << i)){
                maxb = max(maxb, Max[b][i]);
                b = jump[b][i];
            }
        }

        if(u.waga <= max(maxa, maxb)) ans[u.idx] = true;
	}
}

void wypisz(){
	for(int i = 1; i <= m; i++)
		cout << (ans[i] ? "TAK\n" : "NIE\n");
}

int main(){
	wczytaj();
	make_mst();
	make_lca(1);
	policz_ans();
	wypisz();
}
