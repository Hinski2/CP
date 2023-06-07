#include<bits/stdc++.h>
using namespace std;

int n, q;
int liczba_spojnych = 1;
vector<vector<int>>G;
vector<int>sasiedzi_bez_strajkow;

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	G.resize(n + 1);
	sasiedzi_bez_strajkow.resize(n + 1);

	int a, b;
	for(int i = 1; i < n; i++){
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);
	}
}

void start(int v){
	if(sasiedzi_bez_strajkow[v] == 0) liczba_spojnych--;
	else if(sasiedzi_bez_strajkow[v] > 1) liczba_spojnych += sasiedzi_bez_strajkow[v] - 1;
}

void koniec(int v){
	if(sasiedzi_bez_strajkow[v] == 0) liczba_spojnych++;
	if(sasiedzi_bez_strajkow[v] > 1) liczba_spojnych -= sasiedzi_bez_strajkow[v] - 1;
}

void pre_procesing(){
    for(int i = 1; i <= n; i++)
        for(auto u: G[i])
            sasiedzi_bez_strajkow[i]++;
}

int main(){
	wczytaj();
    pre_procesing();

    cin >> q;
	while(q--){
		int v;
		cin >> v;
		
		if(v > 0)
			start(v);
		else
			koniec(-v);

		cout << liczba_spojnych << '\n';
	}
}
