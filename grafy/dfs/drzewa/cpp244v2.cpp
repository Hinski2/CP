#include <bits/stdc++.h>
using namespace std;

#define fi first 
#define se second

const int mak = 2525;

int n;
int min_poziom, idx = 1;

vector<pair<pair<int, int>, pair<int, int>>>liczby[mak];
vector<pair<pair<int, int>, pair<int, int>>>stos;

vector<int>parrent;
vector<bool>nawiasy; //0 otwierajacy 1 zamykajacy

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;

        min_poziom = max(min_poziom, x);
		liczby[x].push_back({{i, i}, {0, 0}});
	}
}

bool make_tree(){
	bool koniec = false;

	for(int i = min_poziom; i > 0; i--){
		if(!liczby[i].size()) return koniec = true;
        if(liczby[i].size() % 2) return koniec = true;

		sort(liczby[i].begin(), liczby[i].end());

		for(int j = 0; j < liczby[i].size() - 1; j += 2){
		if(liczby[i][j + 1].fi.fi - liczby[i][j].fi.se == 1){
				stos.push_back(liczby[i][j]);
				stos.push_back(liczby[i][j + 1]);
				liczby[i - 1].push_back({{liczby[i][j].fi.fi, liczby[i][j + 1].fi.se}, {stos.size() - 2, stos.size() - 1}});
			}
			else return koniec = true;
		}
	}

    if(liczby[0].size() > 1) return koniec = true;
	stos.push_back(liczby[0][0]);
    
    return koniec = false; 
}
        
void przeksztalcenie(int v, int p){
    parrent.push_back(p);
    p = idx++;

    if(stos[v].fi.fi - stos[v].fi.se == 0){
        nawiasy.push_back(1);
        return; //to jest liśc 
    }

    nawiasy.push_back(0);
    przeksztalcenie(stos[v].se.fi, p);

    nawiasy.push_back(0);
    przeksztalcenie(stos[v].se.se, p);
    nawiasy.push_back(1);
}

void wypisanie(){
    for(auto u: parrent)
        cout << u << " ";
    cout << "\n";

    for(auto u: nawiasy){
        if(!u) cout << "(";
        else cout << ")";
    }
    cout << "\n";
}

int main(){
	wczytaj();
	if(make_tree()){
        cout << "NIE\n";
        return 0;
    }

    nawiasy.push_back(0);
    przeksztalcenie(stos.size() - 1, 0);

    wypisanie();
}