#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
const ll mod = 1e9 + 7;

struct pole{
	ll h;
	pair<int, int>a;
	pair<int, int>b;
};

ll n, m, H;
ll ans;

vector<pole>tama;
vector<vector<pair<int, int>>>p;
vector<vector<ll>>sajz, najwieksza, ways;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> H;

	p.resize(n);
	sajz.resize(n);
    najwieksza.resize(n);
    ways.resize(n);

	for(int i = 0; i < n; i++){
		p[i].resize(m);
		sajz[i].resize(m);
        najwieksza[i].resize(m);
        ways[i].resize(m);
		for(int j = 0; j < m; j++){
			p[i][j] = {i, j};
			sajz[i][j] = 1;
            ways[i][j] = 1;
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m - 1; j++){
			int h;
			cin >> h;
			tama.push_back({h, {i, j}, {i, j + 1}});
		}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m; j++){
			int h;
			cin >> h;
			tama.push_back({h, {i, j}, {i + 1, j}});
		}
    }

}

//czy a ma stać przed b
bool cmp(pole a, pole b){
	return a.h < b.h;
}

pair<int, int> przodek(pair<int, int> v){
	if(v == p[v.fi][v.se]) return v;
	return p[v.fi][v.se] = przodek(p[v.fi][v.se]);
}

bool ta_sama(pair<int, int>a, pair<int, int>b){
	a = przodek(a);
	b = przodek(b);

	if(p[a.fi][a.se] == p[b.fi][b.se]) return true;
	return false;
}

void polacz(pair<int, int>a, pair<int, int> b, ll h){
	a = przodek(a);
	b = przodek(b);

	if(sajz[a.fi][a.se] < sajz[b.fi][b.se]) swap(a, b);

    ans = ways[a.fi][a.se] = ((ways[a.fi][a.se] + h - najwieksza[a.fi][a.se]) * (ways[b.fi][b.se] + h - najwieksza[b.fi][b.se])) % mod;
    najwieksza[a.fi][a.se] = h;

	sajz[a.fi][a.se] += sajz[b.fi][b.se];
	p[b.fi][b.se] = p[a.fi][a.se];
}

void policz(){
	for(auto u: tama){
		if(ta_sama(u.a, u.b) == false){
			polacz(u.a, u.b, u.h);
		}
	}

	pair<int, int>prz = przodek(tama.back().a);
    ans = ans + ((H - najwieksza[prz.fi][prz.se]) % mod) + mod;
	ans %= mod;

	cout << ans << '\n';
}


int main(){
	wczytaj();
	sort(tama.begin(), tama.end(), cmp);
	policz();
}
