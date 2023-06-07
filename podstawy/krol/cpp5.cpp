#include <iostream> 
using namespace std; 
 
int x,s=8,r=3,b=5,k=s;
char y;

int main()  
{ 
    cin>>y>>x;
    if ((y == 'a')||(y == 'h'))
    {
       k = b;
    }
    if ((x == 1)||(x == 8))
    {
        k = b;      
    }
    if (((x == 1)||(x == 8)) && ((y == 'a')||(y == 'h')))
    {
        k = r;
    }
    cout<<k<<endl;
    return 0;
} 
