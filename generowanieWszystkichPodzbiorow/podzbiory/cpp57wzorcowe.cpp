#include <bits/stdc++.h>
using namespace std;

bool inUse[100];
int ile;

int main()
{	
	//magiczne linijki predkosci;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>ile;//wczytywanko ilości liczb
	
	for(int x=0;x<(1<<ile);x++)
	{
		int y=x;
		
		//obliczanie 
		for(int i=0;i<ile;i++)
		{
			inUse[i]=y%2;
			y/=2;
		}
		
		//wypisywanie
		for(int i=0;i<ile;i++)
		{
			cout<<inUse[i];
		}
		cout<<"\n";
	}
} 
