#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

int n, k;
vector<int>vec;

inline void wczytaj(){
	scanf("%d%d", &n, &k);
	vec.resize(n);

	for(int i = 0; i < n; i++)
		cin >> vec[i];
}

void policz_jeden(){
	int ans = inf;

	for(auto u: vec) ans = min(ans, u);

	printf("%d\n", ans);
}

void policz_normalnie(){
	int ans = -inf;

	for(auto u: vec) ans = max(ans, u);

	printf("%d\n", ans);
}

void policz_dwa(){
	vector<int>pref(n, inf), suf(n, inf);
	
	pref[0] = vec[0];
	suf[n - 1] = vec[n - 1];

	for(int i = 1; i < n; i++)
		pref[i] = min(pref[i - 1], vec[i]);
	for(int i = n - 2; i > -1; i--)
		suf[i] = min(suf[i + 1], vec[i]);

	int ans = -inf;
	for(int i = 1; i < n; i++)
		ans = max(ans, max(pref[i - 1], suf[i]));
	
	printf("%d\n", ans);
}

int main(){
	wczytaj();
	if(k == 1) policz_jeden();
	else if(k == 2) policz_dwa();
	else policz_normalnie();
}
