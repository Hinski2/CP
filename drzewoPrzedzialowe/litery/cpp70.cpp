#include <bits/stdc++.h>
using namespace std;

int n;							//długość nazwiska 
char A[1000005],B[1000005];		//nazwiska
vector<int> chars[555];			//vector na pozycję wystąpienia znaku w nazwisku

int tree[1<<21];				//wielkość drzewa
int base=1<<20;					//podstawa

int query(int l,int r)
{
	l+=base;				//dodanie podstawy
	r+=base;				//dodanie podstawy
	int res=tree[l];		//rezultat

	if(l!=r) res+=tree[r];	//jeśli to przedział zawierający wyęcej niż jedną literę
	while(l/2!=r/2)			//chodzenie po drzewie
	{
		if(l%2 == 0) res+=tree[l+1];	//jeśli l to lewy syn
		if(r%2 == 1) res+=tree[r-1];	//jeśli r to prawy syn
		l/=2;		//przejście wyżej
		r/=2;		//przejście wyżej 
	}
	return res;		
}

void update(int pozycja)
{
	pozycja+=base;
	while(pozycja)	//idzie do roota włacznie
	{
		tree[pozycja]+=1;
		pozycja/=2;
	}
}

int main()
{
	//wczytywanie
	scanf("%d",&n);				//wczytanie długości nazwiska 

	for(int i=1;i<=n;i++)
	{
		scanf(" %c",&A[i]);		//wczytanie litery z pierwszego nazwiska
	}

	for(int i=1;i<=n;i++)
	{
		scanf(" %c",&B[i]);			//wczytywanie litery z drugiego nazwiska 
		chars[B[i]].push_back(i);	//wczytanie pozycjy wystąpień 
	}

	//odwrócenie
	for(int c='A';c<='Z';c++)
	{
		reverse(chars[c].begin(),chars[c].end());	//obrócenie wartości poszczególnej tablicy w vektorze  
	}

	//liczenie
	long long ans=0;	

	for(int i=1;i<=n;i++)
	{
		char znak=A[i];
		int pos=chars[znak].back();		//ostatnia wartość vectora (przed obróceniem była to pierwsza wartość)

		ans+=pos-i+query(pos+1,n+1);	//pozycja wystąpienia w B - pozycja wystąpienia w A + drzewo
		update(pos);					//update drzewa

		chars[znak].pop_back();			//usunięcie ostatniej wartości vectora(przed obróceniem była to pierwsza wartość)
	}

	printf("%lld\n",ans);
}