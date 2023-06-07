#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct punkt{
	ll x;
	ll y;
	int idx;
};

const int inf = 1e9 + 7;

int n;
punkt zero = {inf, inf, inf};
vector<punkt>punkty;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		punkty.push_back({x, y, i});

		if(y < zero.y){
			zero = punkty.back();
		}
		else if(y == zero.y && x < zero.x){
			zero = punkty.back();
		}
	}
}

inline ll cross(const punkt &a, const punkt &b, const punkt &c){
	ll _x = (b.x - a.x) * (c.y - a.y);
	ll _y = (c.x - a.x) * (b.y - a.y);

	return _x - _y;
}

inline ll odl(const punkt &a, const punkt &b){
	ll _x = (a.x - b.x);
	ll _y = (a.y - b.y);

	_x *= _x; _y *= _y;
	return _x + _y;
}

//czy a ma stać przed b
bool cmp(const punkt &a, const punkt &b){
	ll iloczyn_wektorowy = cross(zero, a, b);
	if(iloczyn_wektorowy != 0) return iloczyn_wektorowy > 0;

	ll odl_a = odl(zero, a);
	ll odl_b = odl(zero, b);

	return odl_a < odl_b;
}

inline void wypisz(const vector<punkt> &otoczka){
	for(auto u: otoczka)
		cout << u.idx << ' ';
	cout << '\n';
}

void make_otoczka(){
	vector<punkt>otoczka;
	int sajz = 0;

	for(auto u: punkty){
		while(sajz > 1 && cross(otoczka[sajz - 2], otoczka[sajz - 1], u) < 0){
			otoczka.pop_back();
			sajz--;
		}

		otoczka.push_back(u);
		sajz++;
	}

	wypisz(otoczka);
}

int main(){
	wczytaj();
	sort(punkty.begin(), punkty.end(), cmp);
	make_otoczka();
}