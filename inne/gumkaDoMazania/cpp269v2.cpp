#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int inf = 1e7 + 15;
int n, rozmiar;
int minimum[125];

vector<string>str;
vector<int>poczatek;
vector<pair<int, int>>ans;
vector<vector<int>>licznik;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	poczatek.resize(n);
	str.resize(n);
	licznik.resize(n);

	for(int i = 0; i < n; i++){
		licznik[i].resize(125);
		cin >> str[i];
	}

	for(int i = 0; i < 125; i++)
		minimum[i] = inf;
}

void make_licznik(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < str[i].size(); j++)
			licznik[i][str[i][j]]++;
} 

void make_minimum(){
	for(int i = 0; i < n; i++)
		for(int j = 'a'; j <= 'z'; j++)
			minimum[j] = min(minimum[j], licznik[i][j]);
}

void wypisz(){
    int cnt = 0, idx = 0;
	string b = "bitek";
	
    for(auto u: ans)
        rozmiar += u.se;

	int w = min((int)b.size(), rozmiar);
	for(int i = 0; i < w; i++){
        if(b[i] > ans[idx].fi){
            cout << b << '\n';
            return;
        }
        else if(b[i] < ans[idx].fi){
            for(auto u: ans)
                for(int k = 0; k < u.se; k++)
                    cout << (char)u.fi;
            
            cout << '\n';
            return;
        }

        if(++cnt == ans[idx].se){
            idx++;
            cnt = 0;
        }
    }

    cout << b << '\n';
}

void wyznacz(){
	for(int let = 'z'; let >= 'a'; let--){
        if(!minimum[let]) continue;

		for(int i = 0; i < n; i++){
			int cnt = 0, j = poczatek[i];
			for(; j < str[i].size(); j++){
				if(str[i][j] == let) cnt++;
				else{
					licznik[i][str[i][j]]--;
					minimum[str[i][j]] = min(minimum[str[i][j]], licznik[i][str[i][j]]);
				}
				if(cnt == minimum[let]) break;
			}
			poczatek[i] = j;
		}

        ans.push_back({let, minimum[let]});
	}
}

int main(){
	wczytaj();
	make_licznik();
	make_minimum();
	wyznacz();
	wypisz();
}
	
