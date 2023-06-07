//nick na codeforces: Hinski2
//link do profilu: https://codeforces.com/profile/Hinski2
//link do zgłoszenia: https://codeforces.com/contest/228/submission/187663800

#include<bits/stdc++.h>
using namespace std;

int n, m;
int mak;

vector<int>colour;
vector<vector<int>>G, Gt;
vector<int>kolejka;
vector<bool>vis;
vector<int>ans;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	mak = (n + 1) * 2;
	colour.resize(mak);
	vis.resize(mak);
	G.resize(mak);
    Gt.resize(mak);

	int a, b, typ;
	for(int i = 1; i <= m; i++){
		cin >> a >> b >> typ;
		a *= 2;
		b *= 2;

		if(typ){
			G[a ^ 1].push_back(b ^ 1);
			G[b].push_back(a);
			Gt[b ^ 1].push_back(a ^ 1);
			Gt[a].push_back(b);

			G[a].push_back(b);
			G[b ^ 1].push_back(a ^ 1);
			Gt[b].push_back(a);
			Gt[a ^ 1].push_back(b ^ 1);
		}
		else{
			G[a ^ 1].push_back(b);
			G[b ^ 1].push_back(a);
			Gt[b].push_back(a ^ 1);
			Gt[a].push_back(b ^ 1);

			G[a].push_back(b ^ 1);
			G[b].push_back(a ^ 1);
			Gt[b ^ 1].push_back(a);
			Gt[a ^ 1].push_back(b);
		}
	}
}

void dfs1(int v){
	vis[v] = true;

	for(auto u: G[v])
		if(!vis[u]) dfs1(u);

	kolejka.push_back(v);
}

void dfs2(int v, int c){
	colour[v] = c;
	for(auto u: Gt[v])
		if(!colour[u]) dfs2(u, c);
}

void make_scc(){
	int c = 0;
	for(auto u: kolejka)
		if(!colour[u]) dfs2(u, ++c);
}

void ustal_kolejnosc(){
	for(int i = 1; i <= n; i++){
		if(colour[2 * i] == colour[2 * i + 1]){
			cout << "Impossible\n";
			exit(0);
		}
		else if(colour[2 * i] > colour[2 * i + 1])
			ans.push_back(i);
	}
}

void wypisz(){
	cout << ans.size() << '\n';
	for(auto u: ans)
		cout << u << ' ';
	cout << '\n';
}

int main(){
	wczytaj();
	for(int i = 1; i < mak; i++)
        if(!vis[i]) dfs1(i);
	reverse(kolejka.begin(), kolejka.end());
	make_scc();
	ustal_kolejnosc();
	wypisz();
}
	
