//zadanie klejnot monarchini Jakub Iliński
#include <bits/stdc++.h>
using namespace std;

const int maksimum=1e6+15, modulo=1e9+7;
int n, liczbaLiter;
int arr[maksimum], uproszczenie[maksimum];

long long ans, licznik=-1;

bool policzony[maksimum];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>liczbaLiter;

	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}

	for(int i=1;i<=n;i++)
	{
		if(!arr[i])	//wartość == 0
		{
			licznik++;
			uproszczenie[i]=licznik;
		}	
		else	
		{
			uproszczenie[i]=uproszczenie[arr[i]];
		}
	}

	licznik=0;
	for(int i=1;i<=n;i++)
	{
		if(!policzony[uproszczenie[i]])
		{
			policzony[uproszczenie[i]]=true;
			licznik++;
		}
	}

	if(licznik>liczbaLiter)
	{
		//naukowcy się pomylili
		cout<<"0\n";
		return 0;
	}

	ans=liczbaLiter;
	for(int i=1;i<licznik;i++)
	{
		ans=(ans*(liczbaLiter-1))%modulo;
	}
	cout<<ans<<"\n";
}