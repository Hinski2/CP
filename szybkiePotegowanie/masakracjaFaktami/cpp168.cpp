#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mak = 505;

int n;
int liczba[mak];
int wynik[mak];

int power(int i, int x)
{
	if(x == 1) return i;

	int ans;
	if(x % 2 == 0)
	{
		ans = power(i, x / 2);
		ans = (1LL * ans * ans) % mod;
	}
	else
	{
		ans = power(i, x / 2);
		ans = (((((1LL * ans) % mod) * ans) % mod) * i) % mod;
	}

	return ans;
}

void potyczka(int a, int b)
{
	int w1 = power(liczba[b], liczba[a]);
	int w2 = power(liczba[a], liczba[b]);

	if(w1 == w2)
	{
		wynik[a]++;
		wynik[b]++;
	}
	else if(w1 > w2)
	{
		wynik[a] += 2;
	}
	else
	{
		wynik[b] += 2;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> liczba[i];
	}

	//liczenie
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j != i)
			{
				potyczka(i, j);
			}
		}
	}

	int ans = -1, zwyciezca;
	for(int i = 1; i <= n; i++)
	{
		if(wynik[i] > ans)
		{
			ans = wynik[i];
			zwyciezca = i;
		}
	}

	cout << zwyciezca << "\n";
}