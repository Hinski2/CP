#include<bits/stdc++.h>
using namespace std;

int n, k, naj, idxNaj;

int minimum = 1e9;
vector<int>v;
vector<int>maks;

void wyznacz_maks(){
	maks[n] = v[n];
	for(int i = n - 1; i > 0; i--)
		maks[i] = max(v[i], maks[i + 1]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	v.resize(n + 1);
	maks.resize(n + 1);

	for(int i = 1; i <= n; i++){
		cin >> v[i];

		if(v[i] >= naj){
			naj = v[i];
			idxNaj = i;
		}
	}

	//jesli idx jest na końcu - nie da sie
	if(idxNaj == n){
		cout << "NIE\n";
		return 0;
	}

	k--;
	//jeli k == 1
	if(k == 1){
		wyznacz_maks();
		for(int i = 1; i < n; i++){
			minimum = min(minimum, v[i]);
			if(minimum >= maks[i + 1]){
				cout << "TAK\n" << i << '\n';
				return 0;
			}
		}

		cout << "NIE\n";
		return 0;
	}

	cout << "TAK\n";
	//jesli idx jest na poczatku
	if(idxNaj == 1){
		cout << "1 ";
		for(int i = 2; i <= k; i++)
			cout << i << ' ';
		cout << '\n';
		return 0;
	}

	//jeli k == 2
	if(k == 2){
		cout << idxNaj - 1 << ' ' << idxNaj << '\n';
		return 0;
	}

	//normalnie
	int i = 1;
	int ilePut = 0;
	k -= 3;

	for(; i <= (idxNaj - 2, k); i++){
		cout << i << ' ';
		ilePut++;
	}

	cout << idxNaj - 1 << ' ' << idxNaj << ' ' << idxNaj + 1 << ' ';

	i += 2;
	for(; ilePut <= k; ilePut++)
		cout << i++ << ' ';

	cout << '\n';
}







