#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void oblicz(){
	int n;
	ll licznik = 0;

    cin >> n;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;

		if(c - '0' == 1)licznik++;
	}

	cout << licznik * (licznik + 1) / 2 << "\n";
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	
	while(q--){
		oblicz();
	}
}