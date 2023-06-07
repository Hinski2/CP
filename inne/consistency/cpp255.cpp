#include <bits/stdc++.h>
using namespace std;

int max_sp, max_sa;
int liczba_sp, liczba_sa;

int policz(){
	string s;
	cin >> s;

	int litera_occ[26];

    //czyszczenie
    for(int i = 0; i < 26; i++)
        litera_occ[i] = 0;
    max_sp = 0;
    max_sa = 0;
    liczba_sa = 0;
    liczba_sp = 0;
    //koniec czyszczenia

	for(int i = 0; i < s.size(); i++)
		litera_occ[s[i] - 'A']++;

	for(int i = 0; i < 26; i++){
		if(i == 'A' - 'A'){
			max_sa = max(max_sa, litera_occ[i]);
			liczba_sa += litera_occ[i];
		}
		else if(i == 'E' - 'A'){
			max_sa = max(max_sa, litera_occ[i]);
			liczba_sa += litera_occ[i];
		}
		else if(i == 'I' - 'A'){
			max_sa = max(max_sa, litera_occ[i]);
			liczba_sa += litera_occ[i];
		}
		else if(i == 'O' - 'A'){
			max_sa = max(max_sa, litera_occ[i]);
			liczba_sa += litera_occ[i];
		}
		else if(i == 'U' - 'A'){
			max_sa = max(max_sa, litera_occ[i]);
			liczba_sa += litera_occ[i];
		}
		else{
			max_sp = max(max_sp, litera_occ[i]);
			liczba_sp += litera_occ[i];
		}
	}

    int zamiana_na_sp = (liczba_sp - max_sp) * 2 + liczba_sa;
    int zamiana_na_sa = (liczba_sa - max_sa) * 2 + liczba_sp;

    return min(zamiana_na_sa, zamiana_na_sp);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	for(int i = 1; i <= q; i++){
		cout << "Case #" << i << ": " << policz() << "\n";
	}
}
