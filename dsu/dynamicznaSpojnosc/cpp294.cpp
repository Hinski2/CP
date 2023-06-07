#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int>p, sajz;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	p.resize(n + 1);
	sajz.resize(n + 1);

	for(int i = 1; i <= n; i++){
		p[i] = i;
		sajz[i] = 1;
	}
}

int przodek(int v){
	if(v == p[v]) return v;
	return p[v] = przodek(p[v]);
}

void polac(int a, int b){
	a = przodek(a);
	b = przodek(b);

	if(p[a] == p[b]) return;
	if(sajz[a] < sajz[b]) swap(a, b); //a jest wiekszy
	
	sajz[a] += sajz[b];
	p[b] = p[a];
}

bool sprawdz(int a, int b){
	a = przodek(a);
	b = przodek(b);

	if(p[a] == p[b]) return true;
	return false;
}

int main(){
	wczytaj();

	while(q--){
		int operacja, a, b;
		cin >> operacja >> a >> b;

		if(operacja == 1)
			polac(a, b);
		else
			cout << (sprawdz(a, b) ? "TAK\n" : "NIE\n");
	}
}
	

