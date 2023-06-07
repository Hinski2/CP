#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, cel;
int ans;

vector<pair<ll, int>>v;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> cel;


	ll current_sum = 0;
	v.resize(n + 1);


	for(int i = 1; i <= n; i++){
		cin >> v[i].first;
		v[i].first += v[i - 1].first;
		v[i].second = i;
	}
}

void liczenie(){
	sort(v.begin(), v.end());

	int j = 0;
	for(int i = 0; i <= n; i++){
		while(j <= n && v[j].first - v[i].first < cel) j++;
		if(v[j].first - v[i].first == cel)
			ans = max(ans, v[j].second - v[i].second);
	}

	j = 0;
	for(int i = 0; i <= n; i++){
		while(j <= n && v[j].first - v[i].first <= cel) j++;
		if(j > 1 && v[j - 1].first - v[i].first == cel)
			ans = max(ans, v[j - 1].second - v[i].second);
	}
}

void wypisz(){
    if(ans == 0) cout << "BRAK\n";
	else cout << ans << "\n";
}

int main(){
	wczytaj();
	liczenie();
	wypisz();
}