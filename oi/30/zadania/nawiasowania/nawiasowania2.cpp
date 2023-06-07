//Jakub Iliński nawiasowanie (brut)
#include <bits/stdc++.h>
using namespace std;

int n, h, ile;
int ans = INT_MAX;

vector<bool>s1, s2;
vector<vector<bool>>najlepszy;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> h;

	s1.resize(n);
	s2.resize(n);
	najlepszy.resize(n);

	for(int i = 0; i < n; i++){
		char c;
		cin >> c;

		if(c == '(') s1[i] = 0;
		else s1[i] = 1;
	}
}

bool poprawny(){
	stack<bool>stos;

	for(auto u: s2){
		if(stos.size() > h) return 0;
		if(u == 0)
			stos.push(u);
		else{
			if(!stos.empty() && stos.top() == 0)
				stos.pop();
			else
				stos.push(u);
		}
	}

	if(!stos.empty()) return 0;
	return 1;
}

int sprawdz(){
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(s1[i] != s2[i]) cnt++;

	return cnt;
}

void policz(){
	for(int mask = 0; mask < (1 << n); mask++){
		int liczba = mask;

		for(int i = 0; i < n; i++){
			s2[i] = liczba % 2;
			liczba /= 2;
		}

		if(poprawny()){
			int spr = sprawdz();
            if(ans == spr){
                najlepszy.push_back(s2);
            }
			else if(ans > spr){
				najlepszy.resize(0);
                najlepszy.push_back(s2);
				ans = spr;
			}
		}
	}
}

int main(){
	wczytaj();
	policz();

    //wypisanie
	cout << ans << '\n';
    // for(auto u: najlepszy){
    //     for(auto w: u)
    //         cout << w << ' ';
    //     cout << '\n';
    // }
}