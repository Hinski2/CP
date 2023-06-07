#include <bits/stdc++.h>
using namespace std;

const int maksimum=1e6+15;
int n,path[maksimum];
int miasto[maksimum];
bool breakl[maksimum],breakr[maksimum]; //pokazuje czy da się jechać dalej czy nie 

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&path[i]);

		if(path[i]==0)		//0 jazda→
		{
			breakl[i]=true;
		}
		else if(path[i]==1) 			//1 jazda←
		{
			breakr[i]=true;
		}					//else 2 jazda ←→ więc nic nie robię 
	}

	//sprawdzanie od lewa do prawa
	int suma=0;

	for(int i=1;i<=n;i++)
	{
		if(!breakl[i])		//false 
		{
			suma++;
			miasto[i+1]+=suma;
		}
		else				//true 
		{
			suma=0;
		}
	}

	//sprawdzenie od prawa do lewa 
	suma=0;
	for(int i=n-1;i>=1;i--)
	{
		if(!breakr[i])
		{
			suma++;
			miasto[i]+=suma;
		}
		else
		{
			suma=0;
		}
	}

	//wypisanie wyniku
	for(int i=1;i<=n;i++)
	{
		printf("%d ",miasto[i]);
	}  
	printf("\n");
}