#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--){
		int n, target, now = 0;
		cin >> n >> target;

		for(int i = 1; i <= 3; i++){
			bool read = 1;
			for(int j = 1; j <= n; j++){
				int x;
				cin >> x;

				if(!read) continue;
				if((target | x) == target)
					now |= x;
				else
					read = 0;
			}
		}

		cout << (now == target ? "YES\n" : "NO\n");
	}
}