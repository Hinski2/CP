#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int p = 179;
const int mod[]{
	(int)1e9 + 7,
	(int)1e9 + 9
};

string s;
vector<int> power[2];
vector<int> hsh[2];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
}

void make_power(){
	power[0].push_back(1);
	power[1].push_back(1);

	for(int i = 1; i < (int)s.size(); i++){
		power[0].push_back((1LL * power[0][i - 1] * p) % mod[0]);
		power[1].push_back((1LL * power[1][i - 1] * p) % mod[1]);
	}
}

void make_hsh(){
	hsh[0].push_back(0);
	hsh[1].push_back(0);

	for(int i = 1; i <= (int)s.size(); i++){
		hsh[0].push_back((1LL * hsh[0][i - 1] * p + s[i - 1]) % mod[0]); 
		hsh[1].push_back((1LL * hsh[1][i - 1] * p + s[i - 1]) % mod[1]); 
	}
}

bool sprawdzenie(int mid){
	set<pair<int, int>> secik;

	for(int i = mid; i <= (int)s.size(); i++){
		int hasz1 = (hsh[0][i] - ((1LL * hsh[0][i - mid] * power[0][mid]) % mod[0]) + mod[0]) % mod[0];
		int hasz2 = (hsh[1][i] - ((1LL * hsh[1][i - mid] * power[1][mid]) % mod[1]) + mod[1]) % mod[1];

		if(secik.find({hasz1, hasz2}) != secik.end()) return true;
		secik.insert({hasz1, hasz2});
	}

	return false;
}

void wypisz(int mid){
	set<pair<int, int>> secik;

	for(int i = mid; i <= (int)s.size(); i++){
		int hasz1 = (hsh[0][i] - ((1LL * hsh[0][i - mid] * power[0][mid]) % mod[0]) + mod[0]) % mod[0];
		int hasz2 = (hsh[1][i] - ((1LL * hsh[1][i - mid] * power[1][mid]) % mod[1]) + mod[1]) % mod[1];

		if(secik.find({hasz1, hasz2}) != secik.end()){
			for(int j = i - mid; j < i; j++)
				cout << s[j];
			cout << '\n';
			return;
		}
		secik.insert({hasz1, hasz2});
	}
}

void bs(){
	int l = 0, r = s.size();
	
	while(l < r){
		int mid = (l + r) / 2;
		if(!sprawdzenie(mid))
			r = mid;
		else
			l = mid + 1;
		}

	if(l == 1){
		cout << "-1\n";
		return;
	}
	else{
		wypisz(l - 1);
	}
}

int main(){
	wczytaj();
	make_power();
	make_hsh();
	bs();
}
