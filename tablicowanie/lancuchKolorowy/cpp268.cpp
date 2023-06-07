#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
int niepotrzebne, potrzebne, rozmiar;

vector<int>pomocniczy, perfect, ile;
queue<int>kolejka;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	pomocniczy.resize(m + 1);
	perfect.resize(n + 1);
	ile.resize(n + 1);

	for(int i = 1; i <= m; i++){
		cin >> pomocniczy[i];
		rozmiar += pomocniczy[i];
	}
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		perfect[x] = pomocniczy[i];
	}
}

void policz(int x){
	kolejka.push(x);
	
	//dodawanie nowego elementu
	if(ile[x] == perfect[x] && perfect[x]){
		potrzebne--;
		niepotrzebne += ile[x] + 1;
	}
    else if(ile[x] == perfect[x]){
        niepotrzebne++;
    }

	ile[x]++;
	if(ile[x] == perfect[x]){
		potrzebne++;
		niepotrzebne -= ile[x] - 1;
	}
	else if(ile[x] != perfect[x] && ile[x] - 1 != perfect[x]){
		niepotrzebne++;
	}

	
	//usuwanie ostatniego elementu
	if(kolejka.size() > rozmiar){
        int y = kolejka.front();
	    kolejka.pop();

        if(ile[y] == perfect[y]){
            potrzebne--;
            niepotrzebne += ile[y] - 1;
        }

        ile[y]--;
        if(ile[y] == perfect[y] && perfect[y]){
            potrzebne++;
            niepotrzebne -= ile[y] + 1;
        }
        else if(ile[y] == perfect[y]){
            niepotrzebne -= ile[y] + 1;
        }
        else if(ile[y] != perfect[y] && ile[y] + 1 != perfect[y]){
            niepotrzebne--;
        }
	}

	//sprawdzenie
	if(!niepotrzebne && (potrzebne == m))
		ans++;
}

void wypisz(){
	cout << ans << '\n';
}

int main(){
	wczytaj();
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		policz(x);
	}
	wypisz();
}
