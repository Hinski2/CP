#include <bits/stdc++.h>
using namespace std;

int aIle,bIle;
long long a[1000005],b[1000005],aSum,bSum;

int wynik()
{
    int suma=0;
    while(true)
    {
        if(aSum>bSum)//aSume jest większa niż bSum
        {
            aSum-=a[aIle];
            aIle--;
            suma++;

        }
        else if(aSum<bSum)//bSume jest większa niż aSum
        {
            bSum-=b[bIle];
            bIle--;
            suma++;
        }
        else
        {
            return suma;
        }
    }
    return suma;
}

int main()
{
    int x;
    scanf("%d%d",&aIle,&bIle);

    for(int i=0;i<aIle;i++)
    {
        scanf("%d",&x);
        a[i]=x;
        aSum+=x;
    }
    for(int i=0;i<bIle;i++)
    {
        scanf("%d",&x);
        b[i]=x;
        bSum+=x;
    }
    aIle--;
    bIle--;
    cout<<wynik()<<endl;

}