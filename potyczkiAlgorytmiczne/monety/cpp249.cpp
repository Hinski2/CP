#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int ans;

map<ll, int>mapa;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	char c;
	ll current_sum = 0;
	mapa[0] = 0;

	for(int i = 1; i <= n; i++){
		cin >> c;

		if(c == 'O') current_sum += 1;
		else current_sum -= k;

		if(mapa.find(current_sum) == mapa.end()) mapa[current_sum] = i;
		else ans = max(ans, i - mapa[current_sum]);
	}

	cout << ans << "\n"; 
}


