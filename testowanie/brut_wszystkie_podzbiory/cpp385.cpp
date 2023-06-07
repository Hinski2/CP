#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>Z;

void wczytaj(){
	cin >> n; 
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		Z.push_back(x);
	}
}

inline void wypisz(vector<int> &v){
	for(auto u: v)
		cout << u << ' ';
	cout << '\n';
}

void policz(){
	for(int mask = 0; mask < (1 << n); mask++){
		vector<int>v;
		for(int j = 0; j < n; j++)
			if(mask & (1 << j)) v.push_back(Z[j]);

		wypisz(v);
	}
}

int main(){
	wczytaj();
	policz();
}
