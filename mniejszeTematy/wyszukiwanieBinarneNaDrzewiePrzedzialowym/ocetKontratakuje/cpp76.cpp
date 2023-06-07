#include <bits/stdc++.h>
using namespace std;

int operacje;
const int base=1<<14;
int tree[1<<15];

//prawie normalna implementacja drzewa ppr
void update(int u)
{
	u+=base;
	tree[u]++;
	u/=2;
	while(u)	//idzie do roota
	{
		tree[u]=tree[u*2]+tree[u*2+1];
		u/=2;
	}
}

int query(int i)
{
	int idx=1;		//root - z niego zaczynamy

	while(idx<base)	//dopóki nie znajdziemy sie na dole 
	{
		if(tree[idx*2]>=i)	//idzie w lewo
		{
			idx*=2;
		}
		else				//idzie w prawo
		{
			idx=idx*2+1;
			i-=tree[idx-1];	//odjącie lewego elementu  
		}
	}
	idx-=base;
	return idx;	//zwrócenie wyniku
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);	//magiczna linijka

	cin>>operacje;	//wczytywanie ilości operacji
	int kolej=1;

	while(operacje--)	//wykonywanie operacji
	{
		bool whatToDo; 	//trzyma jaką operację wykonać

		cin>>whatToDo;	
		if(whatToDo)	//1 - dodać coś na liste 
		{
			int ADD;
			cin>>ADD;			//wczytanie wartości do dodania
			update(ADD);

		}
		else			//0 wypisanie wyniku
		{
			cout<<query(kolej)<<"\n";
			kolej++;
		}
	}
}