#include <bits/stdc++.h>
using namespace std;

int ileSchodkow,ileOsob;
int schodek[500010],person[500010];

int main()
{
    //*skanowanie
    scanf("%d%d",&ileSchodkow,&ileOsob);
    for(int i=1;i<=ileSchodkow;i++)
    {
        int x;
        scanf("%d",&x);
        schodek[i]=max(schodek[i-1],x);
    }
    for(int i=1;i<=ileOsob;i++)
    {
        scanf("%d",&person[i]);
    }
    //*liczenie
    int iOsoba=1;
    for(int i=ileSchodkow;i>0;i--)
    {
        if(schodek[i]<person[iOsoba])
        {
            iOsoba++;
            // printf("%d",(ileSchodkow-i));
            cout<<i<<" ";
        }
        if(iOsoba>ileOsob)break;
        if(i==1)
        {
            while(iOsoba<=ileOsob)
            {
                cout<<"0 ";
                iOsoba++;
            }
        }
    }  
}