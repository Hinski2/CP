#include <bits/stdc++.h>
#define inf 1e9 + 7;
using namespace std;

struct patyczek{
	int dl;
	char kolor;
};

bool operator < (const patyczek &a, const patyczek &b){
	if(a.dl != b.dl) return a.dl < b.dl;
	return a.kolor < b.kolor;
}

int kolory_liczba;
vector<patyczek>liczby;
patyczek bok[3];

void wczytanie(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> kolory_liczba; 
	for(int i = 0; i < kolory_liczba; i++){
		int m;
		cin >> m;
		patyczek patyk;
		patyk.kolor = i + 1;

		for(int j = 0; j < m; j++){
			cin >> patyk.dl;
			liczby.push_back(patyk);
		}
	}
}

void sprawdz(int i){
	int patyk1 = 1, patyk2 = 2;

	if(bok[1].kolor == liczby[i].kolor) patyk1 = 0;
	if(bok[2].kolor == liczby[i].kolor) patyk2 = 0;

	if(bok[patyk1].dl + bok[patyk2].dl > liczby[i].dl){
		cout << (int)liczby[i].kolor << " " << liczby[i].dl << " " <<
			(int)bok[patyk1].kolor << " " << bok[patyk1].dl << " " <<
			(int)bok[patyk2].kolor << " " << bok[patyk2].dl << "\n";
		exit(0);
	}
}

void popraw(int i){
	int  zamiana = 0;
	if(bok[1].kolor == liczby[i].kolor) zamiana = 1;
	if(bok[2].kolor == liczby[i].kolor) zamiana = 2;

	bok[zamiana] = liczby[i];
	sort(bok, bok + 3);
}

void liczenie(){
	sort(liczby.begin(), liczby.end());

	for(int i: {0, 1, 2}){
		bok[i].dl = -inf;
		bok[i].kolor = -i;
	}

	for(int i = 0; i < liczby.size(); i++){
		sprawdz(i);
		popraw(i);
	}

	cout << "NIE\n";
}

int main(){
	wczytanie();
	liczenie();
}
