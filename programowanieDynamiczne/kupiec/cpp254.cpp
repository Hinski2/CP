#include <bits/stdc++.h>
using namespace std;

int n;
int ans;

vector<int>price;
vector<int>fee;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;

		price.push_back(x);
	}
	for(int i = 0; i < n - 1; i++){
		int x;
		cin >> x;

		fee.push_back(x);
	}
}

void w_prawo(){
	int local_max = 0, global_max = 0, start = 0, suma_oplat = 0;

	for(int i = 1; i < n; i++){
		if(0 < price[i] - price[start] - suma_oplat - fee[i - 1]){
			local_max = price[i] - price[start] - suma_oplat - fee[i - 1];
			suma_oplat += fee[i - 1];
		}
		else{
			start = i;
			suma_oplat = 0;
		}

		global_max = max(global_max, local_max);
	}

	ans = max(ans, global_max);
}

void w_lewo(){
	int local_max = 0, global_max = 0, start = n - 1, suma_oplat = 0;
	
	for(int i = n - 2; i >= 0; i--){
		if(0 < price[i] - price[start] - suma_oplat - fee[i]){
			local_max = price[i] - price[start] - suma_oplat - fee[i];
			suma_oplat += fee[i];
		}
		else{
		start = i;
		suma_oplat = 0;
		}

		global_max = max(global_max, local_max);
	}

	ans = max(ans, global_max);
}	

void wypisz(){
	cout << ans << "\n";
}

int main(){
	wczytaj();
	w_lewo();
	w_prawo();
	wypisz();
}