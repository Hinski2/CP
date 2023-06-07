#include <iostream>
using namespace std;
 
int k,l,m=1;
long long w;
 
int main()
{
    cin>>k;
    for(int i=0;i<=k;i++)
    {
        cin>>l;
        w=w+l*m;
        m=m*2;
    }
    cout<<w+1;
}