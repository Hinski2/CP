#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int base = 1 << 18;
vector<ll>tree(base << 1, 1);

int q;

void update(int a, int b, int x)
{
	a += base;
	b += base;

	tree[a] = (tree[a] * x) % mod;
	if(a != b) tree[b] = (tree[b] * x) % mod;

	while(a >> 1 != b >> 1)
	{
		if(a % 2 == 0) tree[a + 1] = (tree[a + 1] * x) % mod;
		if(b % 2 == 1) tree[b - 1] = (tree[b - 1] * x) % mod;

		a >>= 1;
		b >>= 1;
	}
}

void querry(int v)
{
	v += base;
	ll wynik = 1;

	while(v)
	{
		wynik = (wynik * tree[v]) % mod;
		v >>= 1;
	}

	cout << wynik << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> q;
	while(q--) //liczenie
	{
		int o;
		cin >> o;

		if(o)	//querry
		{
			int v;
			cin >> v;

			querry(v);
		}
		else	//update
		{
			int a, b, x;
			cin >> a >> b >> x;

			update(a, b, x);
		}
	}
}