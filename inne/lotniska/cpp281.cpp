#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n;
priority_queue<pair<int, int>> kolejka;
vector<pair<int, int>> connection;
queue<pair<int, int>> toAdd;

inline void wczytaj(){
	scanf("%d", &n);
	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		kolejka.push({x, i});
	}
}

inline void dodaj(){
	while(!toAdd.empty()){
		kolejka.push({toAdd.front().fi, toAdd.front().se});
		toAdd.pop();
	}
}

void policz(){
	while(!kolejka.empty()){
		int v = kolejka.top().se;
		int ile = kolejka.top().fi;

		kolejka.pop();
		while(ile){
			connection.push_back({v, kolejka.top().se});
			if(kolejka.top().fi != 1) toAdd.push({kolejka.top().fi - 1, kolejka.top().se});
			ile--;
			kolejka.pop();
		}
		dodaj();
	}
}

void wypisz(){
	for(auto u: connection)
		printf("%d %d\n", u.fi, u.se);
}

int main(){
	wczytaj();
	policz();
	wypisz();
}

