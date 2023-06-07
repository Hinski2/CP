#include <bits/stdc++.h>
using namespace std;

int n;
int start, koniec;
int najwiekszy;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int>value;

	cin >> n;
	value.resize(n);

	for(int i = 0; i < n; i++)
		cin >> value[i];

	sort(value.begin(), value.end());

	start = value[0];
	koniec = value[n - 1];

	for(int i = 1; i < n; i++)
		najwiekszy = max(najwiekszy, value[i] - value[i - 1]);
}

void policz(){
	int ans = koniec - start - najwiekszy;
	cout << ans << "\n";
}

int main(){
	wczytaj();
	policz();
}