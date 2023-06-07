#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
vector<ll> liczba;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	liczba.resize(n);

	for(int i = 0; i < n; i++)
		cin >> liczba[i];
}

bool sprawdzenie(ll mid){
	ll licznik = 0, suma = 0;
	int l = 0, r = 0;


	while(r < n){
        if(liczba[r] > mid) return false;

		if(suma + liczba[r] > mid){
            l = r;
            suma = 0;
            licznik++;
		}
		else{
            suma += liczba[r++];
        }
	}

	if(licznik >= k) return false;
	return true;
}

ll wyszuiwanie_binarne(){
	ll l = 1, r = 2e14;

	while(l < r){
		ll mid = (l + r) / 2;
		if(sprawdzenie(mid))
			r = mid;
		else
			l = mid + 1;
	}

	return r;
}

int main(){
	wczytaj();
	cout << wyszuiwanie_binarne() << "\n";
}