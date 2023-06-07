#include <bits/stdc++.h>
using namespace std;
 
long long z=1,x;
int y;
 
int main()
{
    scanf("%lld",&x);
    for(int i=2;i*i<=x;i++)
    {
        y=0;
        while(x%i==0)
        {
            x/=i;
            y++;
            if(y%2==0)
            {
                z*=i;
                y=0;
            }
        }
        if(y==1)z*=i;
    }
    if(x>1)z*=x;
    printf("%lld",z*z);
    return 0;
}  