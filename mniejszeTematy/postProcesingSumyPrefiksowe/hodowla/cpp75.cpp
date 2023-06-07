#include <bits/stdc++.h>
using namespace std;

const int maksimum=1015;
int n,ileLat;
bool pole[maksimum][maksimum];
int zmiany[maksimum][maksimum];
int liczonko[maksimum][maksimum];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //magiczna linijka

	//wczytywanie danych
	cin>>n;	//wymiary pola
	for(int y=1;y<=n;y++)
	{
		for(int x=1;x<=n;x++)
		{
			cin>>pole[x][y];
		}
	}
	cin>>ileLat;		//wczytanie ile zmian dokonać 
	while(ileLat--)		//wczytywanie jaki zmianay dokonać 
	{
		int xl, xr, yl, yr;
		cin>>xl>>yl>>xr>>yr;

		zmiany[xl][yl]+=1;
		zmiany[xl][yr+1]-=1;
		zmiany[xr+1][yl]-=1;
		zmiany[xr+1][yr+1]+=1;
	}
	//liczenie jak to zmienić
	for(int y=1;y<=n;y++)
	{
		for(int x=1;x<=n;x++)
		{
			liczonko[x][y]=liczonko[x-1][y] + liczonko[x][y-1] + zmiany[x][y]- liczonko[x-1][y-1] ;
		}
	}

	//dodawanie wartości
	for(int y=1;y<=n;y++)
	{
		for(int x=1;x<=n;x++)
		{
			pole[x][y]=(pole[x][y]+liczonko[x][y])%2;
		}
	}

	//wypisywanie
	for(int y=1;y<=n;y++)
	{
		for(int x=1;x<=n;x++)
		{
			cout<<pole[x][y]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
