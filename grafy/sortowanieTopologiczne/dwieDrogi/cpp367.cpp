#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m;
vector<int>suma, in, order, ans;
vector<vector<pair<int, int>>>G;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	suma.resize(n + 1);
	in.resize(n + 1);
	G.resize(n + 1);

	int a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		G[a].push_back({b, i});
		in[b]++;
	}
}

void make_order(){
	vector<int>list;

	for(int i = 1; i <= n; i++)
		if(!in[i]){
			list.push_back(i);
			order.push_back(i);
		}

	while(!list.empty()){
		int v = list.back();
		list.pop_back();

		for(auto u: G[v]){
			in[u.fi]--;
			if(!in[u.fi]){
				list.push_back(u.fi);
				order.push_back(u.fi);
			}
		}
	}
}

void policz(){
	vector<bool>poprawny(n + 1, false);
	vector<set<int>>vs(n + 1);
	poprawny[1] = true;

	for(auto u: order){
		if(vs[u].size() >= 2) poprawny[u] = true;

		if(poprawny[u])
			for(auto w: G[u])
				vs[w.fi].insert(w.se);
		else
			for(auto w: G[u])
				for(auto y: vs[u])
					vs[w.fi].insert(y);
	}	

	for(int i = 1; i <= n; i++)
		if(poprawny[i]) ans.push_back(i);
}

void wypisz(){
	sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
	for(auto u: ans)
		cout << u << ' ';
	cout << '\n';
}

int main(){
	wczytaj();
	make_order();

	policz();
	wypisz();
}
