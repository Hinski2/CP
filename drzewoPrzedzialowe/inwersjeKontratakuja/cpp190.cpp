#include <bits/stdc++.h>
using namespace std;

const int mak = 60005;
const int base = 1 << 16;

int tree[base << 1];

int n;
int arr[mak], wynik;

map<int, int>mapa;

int querry(int a, int b = 60000)
{
	a += base;
	b += base;

	int ans = 0;

	ans += tree[a];
	if(a != b) ans += tree[b];

	while(a >> 1 != b >> 1)
	{
		if(a % 2 == 0) ans += tree[a + 1];
		if(b % 2 == 1) ans += tree[b - 1];

		a >>= 1;
		b >>= 1;
	}

	return ans;
}

void update(int v)
{
	v += base;

	while(v)
	{
		tree[v]++;
		v >>= 1;
	}
}

void mapowanie()
{
	int idx = 0;
	for(auto u: mapa)
	{
		mapa[u.first] = idx++;
	}

	for(int i = 1; i <= n; i++)
	{
		arr[i] = mapa[arr[i]];
	}
}

void liczenie(int i)
{
	wynik += querry(i + 1);
	update(i);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		mapa[arr[i]] = 1;
	}

	//liczenie
	mapowanie(); //mapowanie pozycji wejściowych 

	for(int i = 1; i <= n; i++)
	{
		liczenie(arr[i]);
	}

	cout << wynik << "\n";

}