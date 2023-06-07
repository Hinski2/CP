#include <bits/stdc++.h> 
using namespace std;

typedef pair<pair<int, int>, int>wierzcholek;
typedef long long ll;

int n;
wierzcholek start;
vector<wierzcholek> point;

void wczytanie(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	point.resize(n);

	for(int i = 0; i < n; i++){
		int x, y;

		cin >> x >> y;
		point[i] = {{x, y}, i + 1};	

		if(point[0].first.second > point[i].first.second) swap(point[i], point[0]);
		if(point[0].first.second == point[i].first.second)
			if(point[0].first.first > point[i].first.first) swap (point[i], point[0]);
	}

	start = point.front();
}

ll cross(wierzcholek a, wierzcholek b, wierzcholek c){
	pair<ll, ll> x = {b.first.first - a.first.first, b.first.second - a.first.second};
	pair<ll, ll> y = {c.first.first - a.first.first, c.first.second - a.first.second};

	return x.first * y.second - y.first * x.second;
}

ll odl(wierzcholek a, wierzcholek b){
	ll x = a.first.first - b.first.first;
	ll y = a.first.second - b.first.second;

	x *= x; y *= y;

	return x + y;
}

//czy a ma stać pred b
bool cmp(wierzcholek a, wierzcholek b){
	ll iloczyn_wektorowy = cross(start, a, b);

	if(iloczyn_wektorowy < 0) return false;
	if(iloczyn_wektorowy > 0) return true;

	return odl(start, a) < odl(start, b);
}

void wypisanie(vector<wierzcholek> &otoczka){
	for(auto u: otoczka)
		cout << u.second << "\n";
}

void make_otoczka(){
	vector<wierzcholek> otoczka;

	for(int i = 0; i <= n; i++){
		while(otoczka.size() > 1 && cross(otoczka[otoczka.size() - 2], otoczka.back(), point[i]) <= 0)
			otoczka.pop_back();

		otoczka.push_back(point[i]);
	}

	otoczka.pop_back();
	wypisanie(otoczka);
}

int main(){
	wczytanie();

	sort(point.begin(), point.end(), cmp);

	point.push_back(start);
	make_otoczka();
}