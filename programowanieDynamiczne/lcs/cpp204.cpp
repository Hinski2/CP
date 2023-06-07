#include <bits/stdc++.h>
using namespace std;

string a, b;

bool sprawdzenie(int start, int dlugosc)
{
	for(int i = 0; i < b.size(); i++)
	{
		for(int j = 0; j <= dlugosc; j++)
		{
			if(a[start + j] != b[i +j]) break;
			if(j == dlugosc) return true;
		}
	}
	return false;
}	

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//wczytywanie
	cin >> a >> b;

	//liczenie
	int start = 0, dlugosc = -1;
	string ans;

	while(start + dlugosc < (int) a.size())
	{
		if(sprawdzenie(start, dlugosc + 1))
		{
			dlugosc++;
			ans = a.substr(start, dlugosc + 1);
		}
		else
		{
			start++;
		}
	}

	//wypisanie wyniku
	cout << ans << "\n";
}