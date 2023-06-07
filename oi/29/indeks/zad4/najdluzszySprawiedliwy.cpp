//zadanie najdłuższy sprawiedliwy okres Jakub Iliński
#include <bits/stdc++.h>
using namespace std;

const int maksimum=1e6+15;
int ileDni, ileDzieci, ans=0, aktSuma[15];
int arr[maksimum],suma[15][maksimum];

bool usunac[15], znaleziony=false;

bool aktualizacja(int l, int r)
{
	for(int i=1;i<=ileDzieci;i++)
	{
		aktSuma[i]=suma[i][r]-suma[i][l];
	}
	//sprawdzenie czy dany kawełek pasuje 
	for(int i=1;i<ileDzieci;i++)
	{
		if(aktSuma[i]!=aktSuma[i+1])break;
		if(i==ileDzieci-1)
		{
			znaleziony=true;
			return true;
		}
	}

	//sprawdzanie co usunąć
	int MINIMUM=maksimum; 
	for(int i=1;i<=ileDzieci;i++)
	{
		MINIMUM=min(MINIMUM,aktSuma[i]);
	}

	for(int i=1;i<=ileDzieci;i++)
	{
		if(aktSuma[i]!=MINIMUM)usunac[i]=true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	//magiczna linijka

	cin>>ileDni>>ileDzieci;
	for(int i=1;i<=ileDni;i++)
	{
		cin>>arr[i];
	}

	//sumy prefiksowe
	for(int i=1;i<=ileDzieci;i++)
	{
		for(int j=1;j<=ileDni;j++)
		{
			if(arr[j]==i)
			{
				suma[i][j]=suma[i][j-1]+1;
			}
			else
			{
				suma[i][j]=suma[i][j-1];
			}
		}
	}

	//obliczenie przez "odrywanie" końców ciągu
	int l=1, r=ileDni;

	while(!znaleziony && l<r)
	{
		if(aktualizacja(l-1,r))break; 

		if(usunac[arr[l]]) //mozna usunać lewy koniec
		{
			usunac[arr[l]]=false;
			l++;
		}
		else if(usunac[arr[r]]) //mozna usunąć prawy koniec
		{
			usunac[arr[r]]=false;
			r--;
		}
		else	//nie mozna usunąć tego i tego 
		{
			usunac[arr[r]]=false;
			r--;
		}
	}
	if(znaleziony)
	{
		ans=r-l+1;
	}

	cout<<ans<<"\n";
}