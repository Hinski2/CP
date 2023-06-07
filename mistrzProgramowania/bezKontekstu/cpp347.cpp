#include <bits/stdc++.h>
using namespace std;

int n, m;
string sa, st;
vector<int>anagram, tekst;
vector<int>ans;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> st >> sa;

	st = '#' + st;
	sa = '$' + sa;

	anagram.resize(26);
	tekst.resize(26);
}

void przeprocesuj(){
	for(int i = 1; i <= m; i++)
		anagram[sa[i] - 'a']++;
}

void sprawdz(){
	int zgadza_sie = 0;

	for(int i = 0; i < 26; i++)
		if(anagram[i] == tekst[i]) zgadza_sie++;

	for(int i = 1; i <= n; i++){
		//dodawanie;
		if(tekst[st[i] - 'a'] < anagram[st[i] - 'a']){
			tekst[st[i] - 'a']++;
			if(tekst[st[i] - 'a'] == anagram[st[i] - 'a']) zgadza_sie++;
		}
        else{
            tekst[st[i] - 'a']++;
        }
        
        //sprawdzenie
		if(zgadza_sie == 26)
			ans.push_back(i - m + 1);

		if(i >= m){
			//usuwanie
			if(tekst[st[i - m + 1] - 'a'] == anagram[st[i - m + 1] - 'a']){
				tekst[st[i - m + 1] - 'a']--;
				zgadza_sie--;
			}
			else{
				tekst[st[i - m + 1] - 'a']--;
			}
		}
	}
}

void wypisz(){
	cout << ans.size() << '\n';
	for(auto u: ans)
		cout << u << ' ';
	cout << '\n';
}

int main(){
	wczytaj();
	przeprocesuj();
	sprawdz();
	wypisz();
}