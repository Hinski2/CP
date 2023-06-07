#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6;
const int mak = 40;

int liczbaMisiow, liczba[4];

//dwie tablice poineważ kopjujemy wartosc mem do dp by zredukować pamięć 
int mem[mak][mak][mak][4][4];
int dp[mak][mak][mak][4][4];

bool sprawdzenie(int i, int j, int k) //sprawdzeni czy ułożenie misi jest poprawne
{
	return !((i/2 == j/2 && j/2 == k/2) || (i%2 == j%2 && j%2 == k%2));
}

int compute()
{
	//przypadek graniczny
	if(liczbaMisiow == 1) return 1;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			mem[ (i == 0) + (j == 0) ][ (i == 1) + (j == 1) ][ (i == 2) + (j == 2) ][i][j]++;
		}
	}

	for(int ile = 2; ile < liczbaMisiow; ile++)
	{
		memset(dp, 0, sizeof(dp));

		for(int a = 0; a <= liczba[0]; a++)
		{
			for(int b = 0; b <= liczba[1]; b++)
			{
				for(int c = 0; c <= liczba[2]; c++)
				{
					for(int i = 0; i < 4; i++)
					{
						for(int j = 0; j < 4; j++)
						{
							if(mem[a][b][c][i][j])
							{
								int d = ile - a - b - c;
								if(d > liczba[3]) continue;

								for(int k = 0; k < 4; k++)
								{
									if(sprawdzenie(i, j, k))
									{
										dp[a + (k == 0)][b + (k == 1)][c + (k == 2)][k][i] += mem[a][b][c][i][j];
										dp[a + (k == 0)][b + (k == 1)][c + (k == 2)][k][i] %= mod;
									}
								}
							}
						}
					}
				}
			}
		}

		memcpy(mem, dp, sizeof(mem));
	}

	//liczenie wyniku końcowego
	int ans = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			ans = (ans + mem[liczba[0]][liczba[1]][liczba[2]][i][j]) % mod;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	for(auto u: {0, 1, 2, 3})
	{
		cin >> liczba[u];
		liczbaMisiow += liczba[u];
	}

	//liczenie
	cout << compute() << "\n";
}