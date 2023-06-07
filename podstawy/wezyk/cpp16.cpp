#include <iostream>
using namespace std;

int main()
{
    int n,x=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(x % 2==1)
        {
            for(int y=x*n-n+1;y<=n*x;y++)
            {
                cout<<y<<" ";
            }
        }
        if(x % 2==0)
        {
            for(int z=x*n;z>=x*n-n+1;z--)
            {
                cout<<z<<" ";
            }
        }
        cout<<endl;
        x++;    
    }
    return 0;
}
