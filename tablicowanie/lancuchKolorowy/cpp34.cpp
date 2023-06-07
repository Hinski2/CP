#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n,m,w,mm[1000005],nn[1000005],aa[1000005],bb[1000005];


void z(int j,int k)
{
    if(nn[j]>0)
    {
        if(bb[j]==nn[j]) w--;
        bb[j]+=k;
        if(bb[j]==nn[j]) w++;
    }
}

int main()
{
    long long c=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&mm[i]);
        c+=mm[i];
    }

    for(int i=0;i<m;i++)
    {
        int kolor;
        scanf("%d",&kolor);
        nn[kolor]=mm[i];
    }
    if(c>n)
    {
        w=0;
        printf("%d",w);
        return 0;
    }
    if(c==n)
    {
        w=1;
        printf("%d",w);
        return 0;
    }
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&aa[i]);
    }

    for(int i=0;i<c;i++)
    {
        z(aa[i],1);   
    }
    int u=(w==m);
    for(int i=c;i<n;i++)
    {
        z(aa[i],1);       
        z(aa[i-c],-1);
        u+=(w==m);
    }
    printf("%d",u);
}