// id zgłoszenia na spoju: 30221589
// link do historii zgłoszeń na spoju(na samej górze jest zaakceptowany problem): https://www.spoj.com/status/hinski2/nonhidden/start=0
#include<bits/stdc++.h>
using namespace std;

int main(){
	cout << "Zrobione.\n";
}

// mój kod
// void wczytaj(int &n, int &m, vector<vector<pair<int, int>>> &G, int &start, int &koniec){
// 	cin >> n >> m;
// 	G.resize(n + 1);

// 	for(int i = 1; i <= m; i++){
// 		int a, b, s;
// 		cin >> a >> b >> s;

// 		G[a].push_back({-s, b});
// 	}

// 	cin >> start >> koniec;
// }

// void dijkstra(int &start, int &koniec, int &n, vector<vector<pair<int, int>>> &G){
// 	vector<bool>odwiedzony(n + 1);
// 	priority_queue<pair<int, int>>q;

// 	q.push({0, start});
// 	while(!q.empty()){
// 		int s = q.top().first;
// 		int v = q.top().second;
// 		q.pop();

// 		if(!odwiedzony[v]){
// 			odwiedzony[v] = true;

// 			if(v == koniec){
// 				cout << -s << '\n';
// 				return;
// 			}

// 			for(auto u: G[v]){
// 				if(!odwiedzony[u.second]){
// 					q.push({u.first + s, u.second});
// 				}
// 			}
// 		}
// 	}

// 	cout << "NO\n";
// }

// int main(){
// 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 	int q;
// 	cin >> q;

// 	while(q--){
// 		int n, m;
// 		int start, koniec;
// 		vector<vector<pair<int, int>>>G;

// 		wczytaj(n, m, G, start, koniec);
// 		dijkstra(start, koniec, n, G);
// 	}
// }
