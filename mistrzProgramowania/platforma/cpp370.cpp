#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 20;
int tree[base << 1];

int maks, n;
void dodaj(int x){
	x += base;

	while(x){
		tree[x]++;
		x >>= 1;
	}
}

int znajdz(int idx){
    idx++;
	int v = 1;
	while(v < base){
		if(tree[v * 2] >= idx) v *= 2;
		else{
			idx -= tree[v * 2];
			v = (v * 2 + 1);
		}
	}

	return v - base;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> maks >> n;
	int x, a, b;
	double ans;
	cout << fixed << setprecision(1);
	for(int i = 1; i <= n; i++){
		cin >> x;

		dodaj(x);
		if(i % 2 == 1){
			a = b = znajdz(i / 2);
		}
		else{
			a = znajdz((i - 1) / 2);
			b = znajdz(i / 2);
		}
		ans = (double)(a + b) / 2;

		cout << ans << '\n';
	}
}


