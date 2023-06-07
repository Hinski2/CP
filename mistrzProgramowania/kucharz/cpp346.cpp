#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	ans.resize(n);

	int last = 0, v;
	for(int i = 0; i < n; i++){
		cin >> v;
		ans[i] = v - last;
		last = v;
	}

	for(auto u: ans)
		cout << u << ' ';
	cout << '\n';
}