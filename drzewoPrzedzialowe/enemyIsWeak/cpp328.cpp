#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;

const int base = 1 << 20;
int treeL[base << 1], treeR[base << 1];

ll n, ans;
vector<int>arr;
map<int, int>mapa;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	arr.resize(n);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
		mapa[arr[i]] = 1;
	}
}

void dodaj(int v){
	v += base;
	while(v){
		treeL[v]++;
		v >>= 1;
	}
}

void usun(int v){
	v += base;
	while(v){
		treeR[v]--;
		v >>= 1;
	}
}

int sumujl(int a, int b){
	int wynik = 0;

	a += base;
	b += base;

	wynik += treeL[a];
	if(a != b) wynik += treeL[b];

	while(a >> 1 != b >> 1){
		if(a % 2 == 0) wynik += treeL[a + 1];
		if(b % 2 == 1) wynik += treeL[b - 1];

		a >>= 1;
		b >>= 1;
	}

	return wynik;
}

int sumujr(int a, int b){
	int wynik = 0;

	a += base;
	b += base;

	wynik += treeR[a];
	if(a != b) wynik += treeR[b];

	while(a >> 1 != b >> 1){
		if(a % 2 == 0) wynik += treeR[a + 1];
		if(b % 2 == 1) wynik += treeR[b - 1];

		a >>= 1;
		b >>= 1;
	}

	return wynik;
}

ll policz(){
	dodaj(arr[0]);

	ll suml, sumr;
	for(int i = 1; i < n - 1; i++){
		sumr = sumujr(0, arr[i] - 1);
		suml = sumujl(arr[i] + 1, base - 1);

		usun(arr[i]);
		dodaj(arr[i]);
		
		ans += suml * sumr;
	}

	return ans;
}

void przemapuj(){
	int idx = 1;
	for(auto u: mapa)
		mapa[u.fi] = idx++;
	for(int i = 0; i < n; i++)
		arr[i] = mapa[arr[i]];
}

void inicjalizuj(){
	for(int i = 1; i < n; i++)
		treeR[arr[i] + base]++;

	for(int i = base - 1; i > 0; i--)
		treeR[i] = treeR[i * 2] + treeR[i * 2 + 1];
}

int main(){
	wczytaj();
	przemapuj();
	inicjalizuj();
	cout << policz() << '\n';
}
