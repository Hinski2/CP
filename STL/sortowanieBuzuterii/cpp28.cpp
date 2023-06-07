#include <bits/stdc++.h>
#include <string>
using namespace std;
 
bool edt(string x,string y)
{
    return (x.size() == y.size()? x<y : x.size() < y.size());
}
 
int n;
string t[160],k;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       cin>>t[i];
    }
 
    sort(t,t+n,edt);
    for(int i=0;i<n;i++)
    {
        cout<<t[i]<<"\n";
    }
}