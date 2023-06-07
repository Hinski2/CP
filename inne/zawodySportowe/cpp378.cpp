#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n;
ll ans = 1;
vector<bool>zajete;
vector<int>miejsce;
vector<vector<int>>G;
map<pair<int, int>, int>mapa;

void wczytaj(){
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> n;
    zajete.resize(2 * n + 2);
	miejsce.resize(n + 1);
	G.resize(2 * n + 2);

	int a, b;
	char typ;

	for(int i = 1; i <= n; i++){
		cin >> typ;
		if(typ == 'T'){
			cin >> a;
			miejsce[i] = a;
            zajete[a + n] = true;
			mapa[{a, a}]++;

			G[i].push_back(a + n);
			G[a + n].push_back(i);

		}
		else{
			cin >> a >> b;
			if(a > b) swap(a, b);
			mapa[{a, b}]++;

			G[i].push_back(a + n);
			G[a + n].push_back(i);
			G[i].push_back(b + n);
			G[b + n].push_back(i);
		}
	}
}

void qp(int x){
	ll l = 2;
	while(x){
		if(x & 1){
			ans *= l;
			ans %= mod;
		}

		l *= l;
		x /= 2;
	}
}

void find_miejsce(int v){
	for(auto u: G[v]){
		if(!zajete[u] && v <= n){
			miejsce[v] = u - n;
            zajete[u] = true;
			find_miejsce(u);
		}
		else if(!zajete[u] && v > n){
			find_miejsce(u);
		}
	}
}

void policz(){
	for(auto u: mapa)
		qp(u.second - 1);

	if(ans == 1){
		for(int i = 1; i <= n; i++)
			if(!miejsce[i]) find_miejsce(i);
	}
}

void wypisz(){
	if(ans == 1){
		cout << "TAK\n";
		for(int i = 1; i <= n; i++)
			cout << miejsce[i] << '\n';
	}
	else{
		cout << "NIE\n";
		cout << ans << '\n';
	}
}	

int main(){
	wczytaj();
	policz();
	wypisz();
}