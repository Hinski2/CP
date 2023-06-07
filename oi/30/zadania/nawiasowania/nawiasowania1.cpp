//Jakub Iliński płytkie nawiasowanie (przypuszczalna wzorcówka)
#include <bits/stdc++.h>
using namespace std;

int n, h;
int ans;

vector<int>p, do_dolu;
vector<vector<int>>G;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> h;

    G.resize(n + 1);
    do_dolu.resize(n + 1);
    p.resize(n + 1);

    int parrent = 0;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;

        if(c == '('){
            G[parrent].push_back(i);
            p[i] = parrent;

            parrent = i;
        }
        else{
            parrent = p[parrent];
        }
    }
}

void dfs(int v){
    for(auto u: G[v]){
        dfs(u);
        do_dolu[v] = max(do_dolu[v], do_dolu[u] + 1);
    }
}

void policz(int v, int wysokosc, int minus){
    if(wysokosc % 2 == 0 && wysokosc && do_dolu[v] + minus + wysokosc > h){
        ans += 2;
        minus -= 2;
    }

    for(auto u: G[v])
        policz(u, wysokosc + 1, minus);
}

int main(){
	wczytaj();
    dfs(0);
    policz(0, 0, 0);
	cout << ans << '\n';
}