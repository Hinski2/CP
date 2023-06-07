#include <bits/stdc++.h>
using namespace std;

const int mak = 4e5 + 15;

int n, m, k;
int sumaW[mak], sumaK[mak];
int itr[mak];

bool przejscie[mak]; //sprawdza czy szedłem ta drogą

vector<pair<int, int>>G[mak];
vector<pair<int, int>>wyznaczone;

void wczytaj(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;

        sumaW[x]++;
        sumaK[y]++;

        G[x].push_back({y + n, i});
        G[n + y].push_back({x, i});
    }
}

bool sprawdzenie_poprawnosci(){
    for(int i = 1; i <= n; i++)
        if(sumaW[i] % 2 == 1) return false;

    for(int i = 1; i <= m; i++)
        if(sumaK[i] % 2 == 1) return false;
    
    return true;
}

void euler(int v){
    while(itr[v] < (int)G[v].size()){
        int u = G[v][itr[v]].first;
        int nr = G[v][itr[v]].second;

        itr[v]++;
        if(!przejscie[nr]){
            przejscie[nr] = true;
            euler(u);

            if(u > n)
                wyznaczone.push_back({nr, -1});
            else
                wyznaczone.push_back({nr, 1});
        }
    }
}

void wyznaczenie(){
    for(int i = 1; i <= n; i++)
        if((int)G[i].size()) euler(i);
}

void wypisanie(){
    sort(wyznaczone.begin(), wyznaczone.end());

    cout << "TAK\n";
    for(auto u: wyznaczone)
        cout << u.second << "\n";
}

int main(){
	wczytaj();
	if(sprawdzenie_poprawnosci() == false){
		cout << "NIE\n";
		return 0;
	}
	wyznaczenie();
    wypisanie();
}