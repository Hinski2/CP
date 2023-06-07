#include <iostream>
using namespace std;
 
int k,w,m;
 
int main()
{
    scanf("%d %d %d",&k,&w,&m);
    printf("%d",(w-k+(m-1))/m);
}