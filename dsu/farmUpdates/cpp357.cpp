#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, m;
int tajm;

vector<bool>removed;
vector<int>ans, gdzie;
vector<pair<int, int>>road;
vector<vector<int>>component;
vector<pair<char, int>>command;

void wlacz_spojna(int v, int kiedy){
    v = gdzie[v];
	if(ans[v] != -1)return;

	for(auto u: component[v])
		ans[u] = kiedy;
}

void polacz_spojne(int a, int b, int kiedy){
	a = gdzie[a];
	b = gdzie[b];

    if(a == b) return;
	if(component[a].size() < component[b].size()) swap(a, b);

	if(ans[a] != -1 || ans[b] != -1){
		wlacz_spojna(a, kiedy);
		wlacz_spojna(b, kiedy);
	}

	for(auto u: component[b]){
		gdzie[u] = a;
		component[a].push_back(u);
	}
}

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	tajm = m;

	ans.resize(n + 1);
	gdzie.resize(n + 1);
	component.resize(n + 1);

	for(int i = 1; i <= n; i++){
		component[i].push_back(i);
		gdzie[i] = i;
		ans[i] = tajm;
	}

	char c; int a, b;
	for(int i = 0; i < m; i++){
		cin >> c;
		if(c == 'A'){
			cin >> a >> b;
			road.push_back({a, b});
			removed.push_back(false);
			command.push_back({c, 0});
		}
		else if(c == 'D'){
			cin >> a;
			ans[a] = -1;
			command.push_back({c, a});
		}
		else{
			cin >> a;
			removed[a - 1] = true;
			command.push_back({c, a - 1});
		}
	}

	for(int i = 0; i < road.size(); i++)
		if(!removed[i]) polacz_spojne(road[i].fi, road[i].se, tajm);
}

void oblicz(){
	for(int i = m - 1; i >= 0; i--){
		if(command[i].fi == 'R'){
			int idx = command[i].se;
			polacz_spojne(road[idx].fi, road[idx].se, i);
		} 
        else if(command[i].fi == 'D')
			wlacz_spojna(command[i].se, i);
	}
}

void wypisz(){
	for(int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}

int main(){
	//wczytanie
	wczytaj();

	//liczenie
	oblicz();

	//wypisanie wyniku
	wypisz();
}