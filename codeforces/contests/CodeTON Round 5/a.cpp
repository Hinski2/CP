#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--){
		int n, m;
		ll a = 0, b = 0;

		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			a += x;
		}
		for(int i = 1; i <= m; i++){
			int x;
			cin >> x;
			b += x;
		}

		if(a == b) cout << "Draw\n";
		else if(a > b) cout << "Tsondu\n";
		else cout << "Tenzing\n";
	}
}



		

