#include <bits/stdc++.h>
using namespace std;

const int maksimum=1e6+15;
int n,arr[maksimum],best[maksimum],ans;

int main()
{
	//skanowanie danych 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);					//skanowanie liczby z ciągu 
		best[i]=max(arr[i],(best[i-1]+1));		//tworzenie naljepszej liczby 
	}

	for(int i=1;i<=n;i++)
	{
		ans=max(ans,best[i]+arr[i]);			//sprawdzanie i szukanie najlepszego wyniku
	}

	printf("%d\n",ans);
}

	