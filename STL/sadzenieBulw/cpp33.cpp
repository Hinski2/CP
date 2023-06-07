#include <bits/stdc++.h>
using namespace std;

int n,b[100000]; 
long long m,w; 
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    scanf("%lld",&m);
    sort(b,b+n);
    for(int i=n-1;i>=0;i--)
    {
        if(m>0)
        {
            if(b[i]<m)
            {
                m-=b[i];
                w+=b[i]*b[i];
            }
            else if(b[i]>=m)
            {
                w+=m*m;
                m=0;
            }
        }
    }
    printf("%lld",w);
}