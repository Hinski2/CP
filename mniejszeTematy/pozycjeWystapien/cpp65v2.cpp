#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+15;
int lengthPrimeArr;
vector<int>pos[MAX];

bool sprawdzenie(int arr[MAX],int length)
{
    int j=0;
	for(int i=0;i<length;i++)//ide po podsłowie
	{
        auto pozycja=lower_bound(pos[arr[i]].begin(),pos[arr[i]].end(),j);//wyszukoje najmniejsza pozycję danej liczby w dużym ciągu 

        if(pozycja==pos[arr[i]].end())//sprawdzenie czy nie znalazło tej liczby 
        {   
            return false;
        }
        else// znalazło tą liczbę 
        {
            j=*pozycja+1;
        }

	}
	
	return true;	
}

int main()
{
		scanf("%d",&lengthPrimeArr);
		for(int i=0;i<lengthPrimeArr;i++)
		{
            int x;
			scanf("%d",&x);
            pos[x].push_back(i);
		}
		
		int iArrs;
		scanf("%d",&iArrs);
		
		for(int i=0;i<iArrs;i++)
		{
			int sub[MAX],iSub;
			
			scanf("%d",&iSub);
			for(int i=0;i<iSub;i++)
			{
				scanf("%d",&sub[i]);
			}
			
			if(sprawdzenie(sub,iSub))
			{
				printf("TAK\n");
			}
			else
			{
				printf("NIE\n");
			}
		}
}
