#include <bits/stdc++.h>
using namespace std;

const int mak = 10'005;

int n;
int wysokosc_reaktora;

bool wejsc[mak];

vector<int>liczby;
vector<int>zbior;

set<int>kandydaci;
set<int>domk;

void wczytanie(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	liczby.resize(n);

	for(int i = 0; i < n; i++){
		cin >> liczby[i];
        wejsc[liczby[i]] = true;
	}

	zbior.push_back(liczby[0]);
}

void update_knadydaci(int idx){
    for(auto u: zbior)
        domk.insert(u + liczby[idx]);

    for(auto u: domk)
        if(!wejsc[u]) kandydaci.insert(u);
}

void liczenie(){
	int idx = 1;
	int nast = liczby[0] * 2;
	bool dalej = true;

	while(idx < n && dalej){
		if(liczby[idx] > nast){
			dalej = false;
			break;
		}

		if(liczby[idx] < nast) zbior.push_back(liczby[idx]);
		update_knadydaci(idx);

        if(!*kandydaci.begin())
            nast = *domk.rbegin();
		else if(liczby[idx] == nast)
            nast = *kandydaci.begin();
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