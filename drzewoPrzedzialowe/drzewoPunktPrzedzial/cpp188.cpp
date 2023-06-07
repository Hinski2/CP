#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 18;

int tree[base << 1];
int q;

void update(int v, int x)
{
	v += base;
	tree[v] = x;
	v >>= 1;

	while(v)
	{
		tree[v] = max(tree[v << 1], tree[(v << 1) + 1]);
		v >>= 1;
	}
}

void querry(int a, int b)
{
	a += base;
	b += base;

	int ans = tree[a];
	ans = max(ans, tree[b]);

	while(a >> 1 != b >> 1)
	{
		if(a % 2 == 0) ans = max(ans, tree[a + 1]);
		if(b % 2 == 1) ans = max(ans, tree[b - 1]);

		a >>= 1;
		b >>= 1;
	}

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> q;
	while(q--)
	{
		int o;
		cin >> o;

		if(o) 	// zapytanie
		{
			int a, b;
			cin >> a >> b;

			querry(a, b);

		}
		else	// update
		{
			int a, b;
			cin >> a >> b;

			update(a, b);
		}
	}
}