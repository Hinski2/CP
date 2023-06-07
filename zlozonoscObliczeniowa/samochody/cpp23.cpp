#include <iostream>
using namespace std;
 
long long z,j=1,s,y,jj;
 
int main()
{
    cin>>s;
    for(int i=0;i<s;i++)
    {
        cin>>y;
        if(y==0)z++;
        if(y==1)
        {
            jj=jj+j*z;
        }
    }
    cout<<jj;
}