#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> wierzcholek;
typedef long long ll;

int n;
wierzcholek start;

vector<wierzcholek>points;
vector<wierzcholek>otoczka;
vector<int>poprawna_oaza;

void wczytanie(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	points.resize(n);

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;

		points[i] = {{x, y}, i + 1};

	if(points[0].first.second > points[i].first.second) swap(points[i], points[0]);
	if(points[0].first.second == points[i].first.second)
		if(points[0].first.first > points[i].first.first) swap(points[i], points[0]);
	}

	start = points[0];
}

int cross(wierzcholek a, wierzcholek b, wierzcholek c){
	pair<ll, ll> x = {b.first.first - a.first.first, b.first.second - a.first.second};
    pair<ll, ll> y = {c.first.first - a.first.first, c.first.second - a.first.second};

    ll wynik = x.first * y.second - x.second * y.first;

    if(wynik > 0) return 1;
    if(wynik < 0) return -1;
    return 0;
}

ll odl(wierzcholek v){
	ll x = (long long)(v.first.first - start.first.first);
	ll y = (long long)(v.first.second - start.first.second);

	x *= x;
	y *= y;

	return x + y;
}

//czy a mastać przed b
bool cmp(wierzcholek a, wierzcholek b){
	if(cross(start, a, b) == -1) return false;
    if(cross(start, a, b) == 1) return true;

    return (odl(a) < odl(b));
}

void make_otoczka(){
	for(int i = 0; i <= n; i++){
		while(otoczka.size() > 1 && cross(otoczka[otoczka.size() - 2], otoczka.back(), points[i]) <= 0)
			otoczka.pop_back();

		otoczka.push_back(points[i]);
	}

	otoczka.pop_back();
}

ll dot(wierzcholek a, wierzcholek b, wierzcholek c){

    pair<ll, ll> x = {b.first.first - a.first.first, b.first.second - a.first.second};
    pair<ll, ll> y = {c.first.first - a.first.first, c.first.second - a.first.second};

	return x.first * y.first + x.second * y.second;
}


void sprawdzenie(){
	if(otoczka.size() == 1){
        poprawna_oaza.push_back(otoczka[0].second);
		return;
	}

	//sa conajmniej 3 oazy
	for(int i = 1; i <= otoczka.size() - 2; i++){

		ll iloczyn_skalarny = dot(otoczka[i], otoczka[i - 1], otoczka[i + 1]);
		if(iloczyn_skalarny >= 0) poprawna_oaza.push_back(otoczka[i].second);
	}

	ll dot_pierwszy = dot(otoczka[0], otoczka.back(), otoczka[1]);
	ll dot_ostatni = dot(otoczka.back(), otoczka[otoczka.size() - 2], otoczka[0]);

	if(dot_pierwszy >= 0) poprawna_oaza.push_back(otoczka[0].second);
	if(dot_ostatni >= 0) poprawna_oaza.push_back(otoczka.back().second);
}

void wypisanie(){
	sort(poprawna_oaza.begin(), poprawna_oaza.end());

	cout << poprawna_oaza.size() << "\n";	
	for(auto u: poprawna_oaza)
		cout << u << "\n";
}

int main(){
	wczytanie();

	sort(points.begin() + 1, points.begin() + n, cmp);

	points.push_back(start);
	make_otoczka();

	sprawdzenie();
	wypisanie();
}