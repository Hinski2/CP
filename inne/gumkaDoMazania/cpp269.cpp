#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int inf = 1e7 + 15;
int n, rozmiar;
int minimum[125];

vector<string>str;
vector<vector<int>>licznik;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	str.resize(n);
	licznik.resize(n);

	for(int i = 0; i < n; i++){
		licznik[i].resize(125);
		cin >> str[i];
	}

	for(int i = 0; i < 125; i++)
		minimum[i] = inf;
}

void policz(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < str[i].size(); j++)
			licznik[i][str[i][j]]++;
}

void przeprocesuj(){
	for(int i = 0; i < n; i++)
		for(int j = 'a'; j <= 'z'; j++)
			minimum[j] = min(minimum[j], licznik[i][j]);
}

void wyznacz(){
	for(int i = 0; i < n; i++){
		int let = 'z', cnt = 0;
        vector<int>occur(125);

        while(!minimum[let] || minimum[let] > licznik[i][let]){
                if(minimum[let] > licznik[i][let]) minimum[let] = licznik[i][let];
                if(minimum[let] == 0) let--;
                    
			    if(let == 'a' - 1) continue;
            }
	
		for(int j = 0; j < str[i].size(); j++){
			if(str[i][j] == let) cnt++;
			if(cnt == minimum[let]){
                let--;
                while(!minimum[let] || minimum[let] > licznik[i][let] - occur[let]){
                    if(minimum[let] > licznik[i][let] - occur[let]) minimum[let] = licznik[i][let] - occur[let];
                    if(minimum[let] == 0) let--;
                    
			        if(let == 'a' - 1) break;
                }
                cnt = 0;
            }

			if(let == 'a' - 1) break;
            occur[str[i][j]]++;
		}
	}
	
	for(int i = 'a'; i <= 'z'; i++)
		rozmiar += minimum[i];
}

void wypisz(){
    int i = 0;
	string b = "bitek";
	
	int let = 'z', cnt = 0;
    for(; let >= 'a';){
        if(!minimum[let]) let--;
        else break;
    }

	int w = min((int)b.size(), rozmiar);
	for(; i < w; i++){
		if(b[i] > let){
			cout << "bitek\n";
			return;
		}
		else if(b[i] < let){
            break;
        }

		if(++cnt == minimum[let]){
			cnt = 0;
            for(; let >= 'a';){
                if(!minimum[let]) let--;
                else break;
            }
		}
	}

    if(rozmiar == 0) cout << "bitek";
	else if(rozmiar < b.size() && b[i] == let) cout << "bitek";
	else{
        for(i = 'z'; i >= 'a'; i--)
            for(int j = 0; j < minimum[i]; j++)
                cout << (char)i;
	}
	cout << '\n';
}

int main(){
	wczytaj();
	policz();
	przeprocesuj();
	wyznacz();
	wypisz();
}