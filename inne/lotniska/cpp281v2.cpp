#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n;
vector<pair<int, int>>node; //ile, v
vector<pair<int, int>>connect;

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;

		node.push_back({x, i});
	}
}

void policz(){
	sort(node.begin(), node.end(), greater<>());

	for(int i = 0; i < n; i++){
		int j = i + 1;
		while(node[i].fi){
			if(node[j].fi){
				connect.push_back({node[i].se, node[j].se});
				node[i].fi--;
				node[j].fi--;
			}
			j++;
		}
	}
}

void wypisz(){
	for(auto u: connect)
		cout << u.fi << ' ' << u.se << '\n';
}

int main(){
	wczytaj();
	policz();
	wypisz();
}
