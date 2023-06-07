#include <bits/stdc++.h>
using namespace std;

void oblicz(){
	int n;
	int liczba = 1000000;
	long long sum = 0;

	cin >> n;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;

		liczba = min(liczba, c);
	}

	sum = 1LL * (n - 1) * liczba;
	cout << sum << "\n";
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;

	while(q--){
		oblicz();
	}
}