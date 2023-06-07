#include <bits/stdc++.h>
using namespace std;

const int mak = 2e6 + 15;

int n;
int tablica[mak];
vector<pair<int, int>>ans;

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n; 
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		tablica[2 * a]++;
		tablica[2 * b + 1]--;
	}
}

inline void policz(){
	bool start = 0;
	for(int i = 1; i < mak; i++){
		tablica[i] += tablica[i - 1];

		if(tablica[i] && !start){
			start = 1;
			ans.push_back({i / 2, 0});
		}
		else if(!tablica[i] && start){
			start = 0;
			ans.back().second = (i - 1) / 2;
		}
	}
}

inline void wypisz(){
	for(auto u: ans)
		cout << u.first << ' ' << u.second << '\n';
}


int main(){
	wczytaj();
	policz();
	wypisz();
}
