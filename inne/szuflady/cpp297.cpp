#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>v;

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
}

inline int policz(){
	int ans = 0;
	for(int i = v.size() - 2; i >= 0; i--){
		if(v[i] >= v[i + 1]){
		 	v[i] = v[i + 1] - 1;
		 	ans++;
		}

		if(v[i] == 0) return -1;
	}

	return ans;
}


int main(){
	wczytaj();
	cout << policz() << '\n';
}