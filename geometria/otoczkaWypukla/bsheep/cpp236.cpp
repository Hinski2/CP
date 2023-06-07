#include <bits/stdc++.h> 
using namespace std;

typedef pair<pair<int, int>, int>wierzcholek;
typedef long long ll;

int n;
wierzcholek start;
vector<wierzcholek> point;

void wczytanie(){
	set<pair<int, int>>s;

	cin >> n;
	point.resize(n);

	int idx = 1;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;

		auto it = s.find({x, y});
		if(it == s.end()){
			s.insert({x, y});
			point[i] = {{x, y}, i + idx};

			if(point[0].first.second > point[i].first.second) swap(point[i], point[0]);
			if(point[0].first.second == point[i].first.second)
				if(point[0].first.first > point[i].first.first) swap (point[i], point[0]);
		}
		else{
            i--;
            n--;
            idx++;

			point.pop_back();
        }
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
	if(otoczka.size() == 1){
		if(point.size() == 1){
			cout << "0.00\n";
			cout << otoczka.front().second << "\n";
		}
		else{
			ll najdalej = 0;
			int najdalszy = 0;

			for(int i = 0; i < n; i++)
				if(najdalej < odl(start, point[i])){
					najdalej = odl(start, point[i]);
					najdalszy = i;
				}

			double f_najdalej = (double)sqrt(najdalej);
			if(f_najdalej * f_najdalej == najdalej)
				cout << 2 * f_najdalej << ".00\n";

			else{
				f_najdalej = round(f_najdalej * 200) / 100;
				cout << f_najdalej << "\n";
			}

			cout << start.second << " " << point[najdalszy].second << "\n";
		}
	}
    else{
	    double wynik = 0;
	    bool calkowita = true;

	    for(int i = 1; i < otoczka.size(); i++){
		    ll dist = odl(otoczka[i - 1], otoczka[i]);
		    double f_dist = (double)sqrt(dist);

		    if(f_dist * f_dist != dist) calkowita = false;
		    wynik += f_dist;
	    }   

	    ll dist = odl(otoczka.back(), otoczka.front());
	    double f_dist = (double)sqrt(dist);

	    if(f_dist * f_dist != dist) calkowita = false;
	    wynik += f_dist;

	    if(calkowita) cout << wynik << ".00\n";
	    else{
		    wynik = round(wynik * 100) / 100;
		    cout << wynik << "\n";
	    }

	    for(int i = 0; i < otoczka.size(); i++)
		    cout << otoczka[i].second << " ";
	    cout << "\n";
    }
}

void make_otoczka(){
	vector<wierzcholek> otoczka;

	for(int i = 0; i <= n; i++){
		while(otoczka.size() > 1 && cross(otoczka[otoczka.size() - 2], otoczka.back(), point[i]) <= 0)
			otoczka.pop_back();

		otoczka.push_back(point[i]);
	}
	otoczka.pop_back();
    point.pop_back();

	wypisanie(otoczka);
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while(t--){
		wczytanie();

		if(point.size()) sort(point.begin(), point.end(), cmp);

		point.push_back(start);
		make_otoczka();
	}
}