#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m,x;
    cin>>m;
    for(int i=0;x<=m;i++)
    {
        x = pow(2,i);
        if(x<=m)
        {
            cout<<x<<endl;
        }
    }
    return 0;
}
