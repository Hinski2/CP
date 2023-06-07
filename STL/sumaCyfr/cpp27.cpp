#include <bits/stdc++.h>
using namespace std;
 
int k,n,t[500005];
 
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    sort(t,t+n);
    for(int i=0;i<k;i++)
    {
        t[i]=9;
    }
    k=0;
     for(int i=0;i<n;i++)
    {
        k+=t[i];
    }
    cout<<k;
    return 0;
}