#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, idx;
vector<pair<int, int>> obwarzanek;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> idx;
	obwarzanek.resize(n + 2);

	for(int i = 1; i <= n; i++)
		cin >> obwarzanek[i].fi >> obwarzanek[i].se;
}

int compute_w_lewo(){
	int ans = 0;
	pair<int, int> donut = obwarzanek[idx];

	for(int i = idx - 1; i >= 1; i--){
		if(obwarzanek[i].fi < donut.se && obwarzanek[i].se > donut.fi){
			ans++;
			donut.fi = min(donut.fi, obwarzanek[i].fi);
			donut.se = max(donut.se, obwarzanek[i].se);
		}
	}

	return ans;
}

int compute_w_prawo(){
	int ans = 0;
	pair<int, int> donut = obwarzanek[idx];

	for(int i = idx + 1; i <= n; i++){
		if(obwarzanek[i].fi < donut.se && obwarzanek[i].se > donut.fi){
			ans++;
			donut.fi = min(donut.fi, obwarzanek[i].fi);
			donut.se = max(donut.se, obwarzanek[i].se);
		}
	}

	return ans;
}

int main(){
	wczytaj();

	int w_lewo = compute_w_lewo();
	int w_prawo = compute_w_prawo();

	cout << min(w_prawo, w_lewo) << '\n';
}