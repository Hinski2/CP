#include <bits/stdc++.h>
using namespace std;

int n;
bool use[100];

int main()
{	
	//magiczne linijki predkosci;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;//wczytyeanie 

	for(int x=0;x<(1<<n);x++)
	{
		//obliczanie i zmienianie
		if(use[0]==false)//false 
		{
			use[0]=true;
		}
		else//true
		{
			int i=0;
			while(use[i]==true)
			{
				use[i]=false;
				i++;
			}
			use[i]=true;
		}

		//wypisywanie
		for(int i=0;i<n;i++)
		{
			cout<<use[i];
		}
		cout<<"\n";
	}
} 
