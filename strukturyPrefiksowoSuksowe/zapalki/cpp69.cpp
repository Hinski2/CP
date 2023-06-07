#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+15;
int n;
long long hight[M];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //magiczna linijka

	cin>>n; //wczytanie ilości zapałek

	for(int i=1;i<=n;i++) //wczytywanie wysokości i-tej zapałki 
	{
		cin>>hight[i];
	}

	int maks=0,sum=0,maybe=0;	//maksymalna długość, aktualna długość ,może 
	bool increase=true;

	for(int i=1;i<=n;i++)
	{
		if(increase==true && hight[i-1]<=hight[i]) 			// rosło i rośnie (lub wysokość jest taka sama)
		{
			sum++;
			maks=max(maks,sum);
		}
		else if(hight[i-1] > hight[i])						// rosło teraz spada (lub wysokość jest taka sama) 
		{
			increase=false;
			sum++;
			maybe=1;
			maks=max(maks,sum);
		}
		else if(hight[i-1] == hight[i])						// rosło teraz spada (lub wysokość jest taka sama) 
		{
			increase=false;
			sum++;
			maybe++;
			maks=max(maks,sum);
		}  

		else if(increase==false && hight[i-1] < hight[i])	// spadało teraz rośnie
		{
			increase=true;
			sum=++maybe;
			maks=max(maks,maybe);
			maybe=1;
		}
	}
	cout<<maks<<"\n"; 
}