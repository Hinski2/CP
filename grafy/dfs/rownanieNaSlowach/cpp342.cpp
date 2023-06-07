#include <bits/stdc++.h>
using namespace std;

int liczba_zmiennych;
int lLen, rLen;
vector<vector<vector<pair<int, int>>>>G;
vector<vector<vector<bool>>>vis;
vector<char>lewy_str, prawy_str;

void wczytaj(){
	G.clear();
	vis.clear();
	lewy_str.clear();
	prawy_str.clear();

	G.resize(126);
	vis.resize(126);

	G['0'].resize(1);
	G['1'].resize(1);

	cin >> liczba_zmiennych;
	for(int i = 'a'; i < liczba_zmiennych + 'a'; i++){
		int x;
		cin >> x;

		G[i].resize(x);
	}

	cin >> lLen;
	for(int i = 1; i <= lLen; i++){
		char c;
		cin >> c;
		for(int i = 0; i < G[c].size(); i++)
			lewy_str.push_back(c);
	}

	cin >> rLen;
	for(int i = 1; i <= rLen; i++){
		char c;
		cin >> c;
		for(int i = 0; i < G[c].size(); i++)
			prawy_str.push_back(c);
	}
}

void make_graph(){
	char last_lewy = '&', last_prawy = '&';
	int lewy_idx = 0, prawy_idx = 0;

	for(int i = 0; i < lewy_str.size(); i++){
		if(lewy_str[i] != last_lewy){
			last_lewy = lewy_str[i];
			lewy_idx = -1;
		}
		if(prawy_str[i] != last_prawy){
			last_prawy = prawy_str[i];
			prawy_idx = -1;
		}

		lewy_idx++;
		prawy_idx++;

		G[last_prawy][prawy_idx].push_back({(int)last_lewy, lewy_idx});
		G[last_lewy][lewy_idx].push_back({(int)last_prawy, prawy_idx});
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--){
		wczytaj();
		if(lewy_str.size() != prawy_str.size()){
			cout << "0\n";
			continue;
		}
		
		make_graph();
	}
}