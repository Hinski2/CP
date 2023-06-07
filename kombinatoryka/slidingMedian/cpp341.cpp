#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int base = 1 << 18;
int tree[base << 1];

int n, k;
vector<int>arr, odw;
map<int, int> mapa;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	arr.resize(n);
	odw.resize(n);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
		mapa[arr[i]] = 1;
	}
}

void przemapuj(){
	int idx = 0;
	for(auto u: mapa)
		mapa[u.fi] = idx++;

	for(int i = 0; i < n; i++){
		int v = mapa[arr[i]];
		odw[v] = arr[i];
		arr[i] = v;
	}
}

void dodaj(int v){
	v += base;
	tree[v]++;
	v >>= 1;

	while(v){
		tree[v]++;
		v >>= 1;
	}
}

void usun(int v){
	v += base;
	tree[v]--;
	v >>= 1;

	while(v){
		tree[v]--;
		v >>= 1;
	}
}

int znajdz(int v){
	int node = 1;

	while(node < base){
		if(tree[node * 2] >= v){    //ide w lewo
            node *= 2;
        }
        else{                       //ide w prawo
            v -= tree[node * 2];
            node = node * 2 + 1;
        }
	}
	return odw[node - base];
}

int main(){
	wczytaj();
	przemapuj();

	for(int i = 0; i < k - 1; i++)
		dodaj(arr[i]);

	for(int i = k - 1; i < n; i++){
		dodaj(arr[i]);
		cout << znajdz((k + 1) / 2) << ' ';
		usun(arr[i - k + 1]);
	}
}