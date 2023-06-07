#include<bits/stdc++.h>
using namespace std;

int n;
bool mozliwe = false;
vector<int>vec;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		vec.push_back(x);
	}

	for(int i = 0; i < n; i++)
		vec.push_back(vec[i]);
}

void sprawdz(){
	vector<int>kolejka;
	for(int i = 0; i < 2 * n; i++){
		if(kolejka.empty() || kolejka.back() >= vec[i])
			kolejka.push_back(vec[i]);
		else if(kolejka.back() < vec[i]){
			kolejka.clear();
			kolejka.push_back(vec[i]);
		}

		if(kolejka.size() == n) mozliwe = true;
	}

	kolejka.clear();
	for(int i = 2 * n - 1; i >= 0; i--){
		if(kolejka.empty() || kolejka.back() >= vec[i])
			kolejka.push_back(vec[i]);
		else if(kolejka.back() < vec[i]){
			kolejka.clear();
			kolejka.push_back(vec[i]);
		}

		if(kolejka.size() == n) mozliwe = true;
	}
}

int main(){
	wczytaj();
	sprawdz();

	if(mozliwe) cout << "TAK\n";
	else cout << "NIE\n";
}