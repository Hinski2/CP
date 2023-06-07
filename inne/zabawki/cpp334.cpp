#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n;
int bitek[26][2], bajtek[26][2];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	char c;
	
	for(int i = 1; i <= n; i++){
		cin >> c;
		bitek[c - 'a'][i % 2]++;
	}

	for(int i = 1; i <= n; i++){
		cin >> c;
		bajtek[c - 'a'][i % 2]++;
	}
}

bool sprawdz(){
	for(int i = 0; i < 26; i++)
		for(int k: {0, 1})
			if(bitek[i][k] != bajtek[i][k]) return false;

	return true;
}

int main(){
	wczytaj();
	if(sprawdz()) cout << "TAK\n";
	else cout << "NIE\n";
}