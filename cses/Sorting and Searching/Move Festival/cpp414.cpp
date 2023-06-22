#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

bool cmp(pii a, pii b){
	return a.se < b.se;
}

int n, ans;
vector<pii> movie;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		movie.push_back({a, b});
	}

	sort(movie.begin(), movie.end(), cmp);

	int occupied_to = 0;
	for(auto u: movie){
		if(u.fi >= occupied_to){
			ans++;
			occupied_to = u.se;
		}
	}

	cout << ans << '\n';
}
