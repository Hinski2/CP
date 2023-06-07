#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m, k, teraz;
vector<int>p, sajz;
vector<pair<int, int>> node;


void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	node.resize(m + 1);
	p.resize(n + 1);
	sajz.resize(n + 1);
	teraz = n;

	for(int i = 1; i <= n; i++){
		p[i] = i;
		sajz[i] = 1;
	}
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		node[i] = {a, b};
	}
}

int przodek(int v){
	if(p[v] == v) return v;
	return p[v] = przodek(p[v]);
}

bool sprawdz(int a, int b){
	a = przodek(a);
	b = przodek(b);

	if(p[a] == p[b]) return true;
	return false;
}

void polacz(int a, int b){
       	a = przodek(a);
	b = przodek(b);

	if(p[a] == p[b]) return;
	if(sajz[a] < sajz[b]) swap(a, b); //a jest wiekszy od b
      	
	sajz[a] += sajz[b];
	p[b] = p[a];
}	

void policz(){
	int dzien = m;
	for(int i = m; i > 0; i--){
		if(!sprawdz(node[i].fi, node[i].se)) teraz--;
		polacz(node[i].fi, node[i].se);

		if(teraz < k){
			cout << dzien + 1 << '\n';
			return;
		}
		dzien--;
	}
}

int main(){
	wczytaj();
	policz();
}


