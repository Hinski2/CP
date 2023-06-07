#include <bits/stdc++.h>
using namespace std;

int ileOsob,ilePotrzeba;
int ciag[1000010];

int main()
{
//*skanowanie
    scanf("%d%d",&ileOsob,&ilePotrzeba);
    for(int i=1;i<=ileOsob;i++)
    {
        scanf("%d",&ciag[i]);
    }
//*początek liczenia
    int l=1,girls=0,ans=ileOsob+1;

    for(int r=1;l<ileOsob;r++)
    {
        if(ciag[r]==0)//dziewczyna
        {
            girls++;
            if(girls==ilePotrzeba)
            {
                ans=min(ans,r-l+1);
            }
        }
        while((girls>ilePotrzeba || r==ileOsob) && l<ileOsob)//usuwanie pierwszej liczby 
        {
            if(ciag[l]==0)girls--;
            l++;
            if(girls==ilePotrzeba) 
            {
                ans=min(ans,r-l+1);
            }
        }
    }
//*wypisywanie 
    if(ans==ileOsob+1)//nie wystarczająca ilość dziweczyn 
    {
        cout<<"NIE"<<"\n";
    }
    else cout<<ans-ilePotrzeba<<"\n";    
}