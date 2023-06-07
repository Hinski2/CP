#include<bits/stdc++.h>
using namespace std;

int n, szukany;
int longest;

long long current_sum;
map<long long, int>mapa;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> szukany;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		current_sum += x;

		if(mapa.find(current_sum) == mapa.end()) mapa[current_sum] = i;

		if(mapa.find(current_sum - szukany) != mapa.end())
			longest = max(longest, i - (int)mapa[current_sum - szukany] + (current_sum - szukany == 0 ? 1 : 0));
	}

	if(longest == 0) cout << "BRAK\n";
	else cout << longest << "\n";
}
