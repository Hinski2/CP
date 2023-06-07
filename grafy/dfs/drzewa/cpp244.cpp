#include <bits/stdc++.h>
using namespace std;

const int mak = 2515;

int n;
int min_poziom;
int pref_rozmiar[mak];

vector<int>parrent;
vector<pair<int, int>>liczby[mak];
vector<pair<int, int>>stos;

int idx = 0;
vector<bool>nawiasy; //0 otwierajacy 1 zamykajacy

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;

        min_poziom = max(min_poziom, x);
		liczby[x].push_back({i, i});
	}
}

bool make_tree(){
	bool koniec = false;
	bool rozpoczecie = false;

	for(int i = min_poziom; i > 0; i--){
		if(!liczby[i].size() && !rozpoczecie) continue;
		else if(!liczby[i].size() && rozpoczecie) return koniec = true;
		else if(liczby[i].size() && !rozpoczecie) rozpoczecie = true;

		sort(liczby[i].begin(), liczby[i].end());
		for(int j = 0; j < liczby[i].size() - 1; j += 2){
			if(liczby[i][j + 1].first - liczby[i][j].second == 1){
				stos.push_back(liczby[i][j]);
				stos.push_back(liczby[i][j + 1]);
				liczby[i - 1].push_back({liczby[i][j].first, liczby[i][j + 1].second});
			}
			else return koniec = true;
		}
	}
    stos.push_back(liczby[0][0]);
	//stos jest gotowy

    return koniec = false; 
}

void sum_pref(){
    pref_rozmiar[0] = 1;
    for(int i = 1; i <= min_poziom; i++)
        pref_rozmiar[i] = pref_rozmiar[i - 1] + liczby[i].size();
}
        
void przeksztalcenie(int v, int poziom, int p){

    parrent.push_back(p);

    if(stos[v].first - stos[v].second == 0){
        nawiasy.push_back(1);
        return; //to jest liśc 
    }

    nawiasy.push_back(0);
    przeksztalcenie(v - pref_rozmiar[poziom] - 1, poziom + 1, idx);

    nawiasy.push_back(0);
    przeksztalcenie(v - pref_rozmiar[poziom], poziom + 1, idx);
    nawiasy.push_back(1);
}

void wypisz(){
    for(auto u: parrent)
        cout << u << " ";
    cout << "\n";

    for(auto u: nawiasy){
        if(u) cout << ")";
        else cout<< "(";
    }
}

int main(){
	wczytaj();
	if(make_tree()){
        cout << "NIE\n";
        return 0;
    }

    //przekształcanie in_order w pre_order 
    sum_pref();

    nawiasy.push_back(0);
    przeksztalcenie(stos.size() - 1, 0, 0);
    nawiasy.push_back(1);

    wypisz();
}