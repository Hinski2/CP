#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mak = 1e6 + 15;

int n, q;
ll suma[mak];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> suma[i];
	}
}

int main(){
	wczytaj();

	cin >> q;
	int a, b;
	while(q--){
		cin >> a >> b;
		cout << suma[b] - suma[a - 1] << '\n';
	}
}


