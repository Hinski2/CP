#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 15;

int pojemnoscBaku, liczbaStacji;
int kosztNaStacji[mak];
bool stacja[mak];

int odl;
int iloscPaliwa;


list<pair<int, int>>l;

void wczytywanie()
{
	cin >> pojemnoscBaku >> liczbaStacji;
	for(int i = 1; i <= liczbaStacji; i++)
	{
		int a, b;
		cin >> a >> b;

		stacja[odl] = true;
		kosztNaStacji[odl] = a;

		odl += b;
	}
}

void dodaj(int i) //dodaje cene paliwa na kolejke
{
	int dodawany_element = kosztNaStacji[i];

	while(dodawany_element < l.back().first)
	{
		if(l.size() == 0) break;
		l.pop_back();
	}

	l.push_back({dodawany_element, i});

}

void zamiana()
{
	l.pop_front();
}

int liczenie()
{
	int ans = 0;
	for(int i = 0; i < odl; i++)
	{
		if(stacja[i])
		{
			dodaj(i);
		}
		if(i - l.front().second >= pojemnoscBaku)
		{
			zamiana();
		}

		ans += l.front().first;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	wczytywanie();
	cout << liczenie() << "\n";
}