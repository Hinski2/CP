#include<bits/stdc++.h>
using namespace std;

int n, m, t, p;
vector<int> T, P;

set<int>s;

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> p >> t;
	T.resize(t);
	P.resize(p);
	
	int a, b;
	for(int i = 0; i < p; i++){
		cin >> a >> b;
		P[i] = a - b;
	}
	for(int i = 0; i < t; i++){
		cin >> a >> b;
		T[i] = a - b;
	}
}

inline void setuj(){
	for(auto u: P)
		s.insert(u);
}

inline void policz(){
	int ans = 0;

	for(auto u: T)
		if(s.count(u) == 0) ans++;
	cout << ans<< '\n';
}

int main(){
	wczytaj();
	setuj();
	policz();
}
