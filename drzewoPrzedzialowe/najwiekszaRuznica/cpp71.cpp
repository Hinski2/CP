#include <bits/stdc++.h>
using namespace std;

const int infinity=2e9;			
struct intervalTree
{
	int Max=-1;					//maksymalna wartość
	int Min=infinity;			//minimalna wartość 
	int Res=-1;					//rezultat
};

const int base=1<<17;			//podstawa drzewa
intervalTree tree[1<<18];		//tablica przechowująca wartości na drzewie

void update(int idx,int nowy)	//podmiana warwości w drzewie 
{
	idx+=base;
	
	tree[idx].Min=nowy;			//zamiana minimalnej warwości 
	tree[idx].Max=nowy;			//zamiana maksymalnej wartości 

	while(idx)//idzie do roota(włącznie) 
	{
		idx/=2;//przejście na przedostatni poziom 

		tree[idx].Min=min(tree[idx*2].Min,tree[idx*2+1].Min);		//obliczanie tree[x].Min
		tree[idx].Max=max(tree[idx*2].Max,tree[idx*2+1].Max);		//obliczanie tree[x].Max

		if(tree[idx*2+1].Max==-1)									//obliczanie tree[x].Res
		{//jeśli lewy syn nie jest zapisany lub w synie wartość o nideksie x > od tej na indeksie x+1
			tree[idx].Res=max(tree[idx*2].Res,tree[idx*2+1].Res);
		}
		else
		{
			tree[idx].Res=max(max(tree[idx*2].Res, tree[idx*2+1].Res), (tree[idx*2+1].Max-tree[idx*2].Min));
		}
	}

}

int question()				//zapytanie o "X"
{
	return tree[1].Res;		//wartość roota
}

void build()
{
	for(int M=16;M>=1;M--)
	{
		for(int i=1<<M;i<(1<<(1+M));i++)
		{
			tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);		//obliczanie tree[x].Min
			tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);		//obliczanie tree[x].Max

			if(tree[i*2+1].Max==-1)								//obliczanie tree[x].Res
			{//jeśli lewy syn nie jest zapisany lub w synie wartość o nideksie x > od tej na indeksie x+1
				tree[i].Res=max(tree[i*2].Res,tree[i*2+1].Res);
			}
			else
			{
				tree[i].Res=max(max(tree[i*2].Res, tree[i*2+1].Res), (tree[i*2+1].Max-tree[i*2].Min));
			} 
		}
	}
	//oddzielne liczenie roota 
	tree[1].Min=min(tree[2].Min,tree[3].Min);		//obliczanie tree[x].Min
	tree[1].Max=max(tree[2].Max,tree[3].Max);		//obliczanie tree[x].Max

	if(tree[2].Min==-1 || tree[3].Max==-1)			//obliczanie tree[x].Res
	{
		tree[1].Res=max(tree[2].Res,tree[3].Res);
	}
	else
	{
		tree[1].Res=max(max(tree[2].Res, tree[3].Res), (tree[3].Max-tree[2].Min));	
	}
}

int main()
{
	int n,zapytanie;						//n-ilość liczb, zapytanie-ilość zapytań
	scanf("%d%d",&n,&zapytanie);

	for(int i=0;i<n;i++)					//wczytywanie drzewa 
	{	
		scanf("%d",&tree[base+i].Min);		//dodanie minimalnej wartości 
		tree[base+i].Max=tree[base+i].Min;	//dodanie maksymalnej wartości
	}

	build();	//budowanie drzewa

	while(zapytanie--)
	{
		char znak;		//wczytuje operacja ma się wykonać q czy u
		scanf(" %c",&znak);

		if(znak=='q')	//pytanie 
		{
			printf("%d\n",question());
		}
		else			//podmiana/aktualizacja drzewa
		{
			int co,naCo;//liczbę o jakim indeksie ma podmienić, na jaką liczbę na to podmienić  
			scanf("%d%d",&co,&naCo);
			update(co-1,naCo);	//co-1 ponieważ indeksuje od 0 
		}
	}
}