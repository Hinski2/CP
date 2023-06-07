#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    int x,y,z=0;
    cin>>x>>y;
    x=x%10;
    for(int i=1;i<=y;i++)
    {
        z++;
        if(z==5)z=1;
    }
    y=z;
    x=pow(x,y);
    x=x%10;
    cout<<x;
}