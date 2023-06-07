#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+15;
int lengthPrimeArr,primeArr[MAX];

bool sprawdzenie(int subArr[MAX],int iSubArr)
{
	int j=0;
	for(int i=0;i<lengthPrimeArr;i++)
	{
		if(primeArr[i]==subArr[j])
		{
			j++;
			if(j>=iSubArr)return true;
		}
	}
	
	return false;	
}

int main()
{
		scanf("%d",&lengthPrimeArr);
		for(int i=0;i<lengthPrimeArr;i++)
		{
			scanf("%d",&primeArr[i]);
		}
		
		int iArrs;
		scanf("%d",&iArrs);
		
		for(int i=0;i<iArrs;i++)
		{
			int subArr[MAX],iSubArr;
			
			scanf("%d",&iSubArr);
			for(int i=0;i<iSubArr;i++)
			{
				scanf("%d",&subArr[i]);
			}
			
			if(sprawdzenie(subArr,iSubArr))
			{
				printf("TAK\n");
			}
			else
			{
				printf("NIE\n");
			}
		}
}
