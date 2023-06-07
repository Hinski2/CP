#include <bits/stdc++.h>
using namespace std;

int base=1<<16;							//podstawa drzewa
int tree[1<<17];						//tablica ze wszystkimi elementami drzewa
const int maksimum=60015;				//zmienna pomocnicza by sie nie pomylić z pisaniem "0"

int ileElementow, element[maksimum];	//ile elementów jest w ciągu, tablica elemtntów ciągu;
long long inwersje;						//licznik inwersji 

long long query(int a, int b)
{
	long long res=0;	//rezultat (ile jest wartości mniejszych od i)
	a=a+base-1;
	b=b+base+1;

	while(a/2!=b/2)	//idzie dopuki a i b nie będą miały wspólnego ojca
	{
		if(a%2==0) res+=tree[a+1];	//jeśli a to lewy syn
		if(b%2==1) res+=tree[b-1];	//jeśli b to prawy syn 

		//przejście wyżej
		a/=2;
		b/=2;
	}

	//zwrócenie wyniku
	return res;
}

void update(int liczba) 	//funkcja aktualizujące ilość "liczba" w drzewie
{
	liczba+=base;
	tree[liczba]++;	//aktualizacja 
	liczba/=2;		//przejście do ojca

	while(liczba)	//idzie do root'a
	{
		tree[liczba]=tree[2*liczba]+tree[2*liczba+1];	//aktualizuje wartość ojca lewego i prawego syna 
		liczba/=2;	//przejscie wyżej
	}
}

void mapowanie() //sztuczka z mapowaniem wartości 
{
	map<int,int>m;
	for(int i=0;i<ileElementow;i++)
	{
		m[element[i]]=1;
	}

	int idx=1;

	for(auto p:m)
	{
		m[p.first]=idx++;
	}

	for(int i=0;i<ileElementow;i++)
	{
		element[i]=m[element[i]];
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	//magiczna linijka

	//wczytywanie danych 
	cin>>ileElementow;
	for(int i=0;i<ileElementow;i++)
	{
		cin>>element[i];
	}

	//mapowanie wartości
	mapowanie();

	//tworzenie drzewa przedziałowego ppr 
	for(int i=ileElementow-1;i>=0;i--)
	{
		inwersje+=query(0,element[i]-1);	//zapytanie ile jest aktualnie wartości mniejszych od i

		update(element[i]);	//aktualizowanie drzewa o 1 dla i
	}
	cout<<inwersje<<"\n";
}