#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>>plyta; //wysokosc, wartosc

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m; 
	for(int i = 0; i < m; i++){
		int w, h;
		cin >> w >> h;

		plyta.push_back({h, w});
	}
}


void policz(){
	int idx = 0, ans = 0;
	priority_queue<int>kolejka;

	for(int i = 1; i <= n; i++){
		while(idx < plyta.size() && plyta[idx].first <= i)
			kolejka.push(plyta[idx++].second);

		if(!kolejka.empty()){
			ans += kolejka.top();
			kolejka.pop();
		}
	}

	cout << ans << '\n';
}

int main(){
	wczytaj();
	sort(plyta.begin(), plyta.end());
	policz();
}
