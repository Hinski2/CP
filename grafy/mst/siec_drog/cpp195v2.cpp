#include <bits/stdc++.h>
using namespace std;

const int mak = 205;

int n;
int matrix[mak][mak];
vector<pair<int, int>>powiazania;

void wyznaczanie()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            bool poprawny = true;
            int k = 1;
            
            while(poprawny && k <= n)
            {
                if(k != i && k != j && matrix[i][j] == matrix[i][k] + matrix[k][j]) poprawny = false;
                k++;
            }

            if(poprawny) powiazania.push_back({i, j});
        }
    }
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> matrix[i][j];
		}
	}

    //liczenie
    wyznaczanie();

    //wysywanie
    for(auto u: powiazania)
    {
        cout << u.first << " " << u.second << "\n";
    }
}