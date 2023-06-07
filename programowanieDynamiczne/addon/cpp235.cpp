#include <bits/stdc++.h>
using namespace std;

int n;
int wysokosc_reaktora;

vector<int>liczby;
vector<int>zbior;

void wczytanie(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	liczby.resize(n);

	for(int i = 0; i < n; i++){
		cin >> liczby[i];
	}

	zbior.push_back(liczby[0]);
}

void liczenie(){
	set<int>kandydaci;
	int idx = 1;
	int nast = liczby[0] * 2;
	bool dalej = true;

	while(idx < n && dalej){
		if(liczby[idx] > nast){
			dalej = false;
		}

		if(liczby[idx] < nast) zbior.push_back(liczby[idx]);
		for(auto u: zbior)
			kandydaci.insert(u + liczby[idx]);
		if(liczby[idx] == nast){
            if(kandydaci.size() > 1) kandydaci.erase(kandydaci.begin());
            nast = *kandydaci.begin();
        }
		idx++;
	}

	wysokosc_reaktora = nast - 1;
}

void wypisanie(){
	cout << wysokosc_reaktora << "\n";
	for(auto u: zbior)
		cout << u << "\n";
}

int main(){
	wczytanie();
	liczenie();
	wypisanie();
}