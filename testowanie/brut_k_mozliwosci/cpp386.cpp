#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int>opcja;

void wczytaj(){
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		opcja.push_back(x);
	}
}

inline void wypisz(vector<int> &v){
	for(int i = 0; i < n; i++)
		cout << i << ":" << opcja[v[i]] << "	";
	cout << '\n';
} 

void policz(){
	int power = 1;
	for(int i = 0; i < k; i++)
		power *= k;

	for(int i = 0; i < power; i++){
		vector<int>v;
		int op = i;

		for(int j = 0; j < n; j++){
			v.push_back(op % k);
			op /= k;
		}

		wypisz(v);
	}
}

int main(){
	wczytaj();
	policz();
}