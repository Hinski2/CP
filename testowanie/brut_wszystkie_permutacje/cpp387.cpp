#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>permutation;

void wczytaj(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		permutation.push_back(x);
	}
}

inline void wypisz(){
	for(auto u: permutation)
		cout << u << ' ';
	cout << '\n';
}

void policz(){
	sort(permutation.begin(), permutation.end());

	do{
		wypisz();
	}while(next_permutation(permutation.begin(), permutation.end()));
}

int main(){
	wczytaj();
	policz();
}