#include <iostream>
#include <iostream>
using namespace std;
 
int main()
{
int x,g,gr,m,s;
cin>>x;
g = x/3600;
gr = x % 3600;
m = gr/60;
s = gr % 60;
cout<<g<<"g"<<m<<"m"<<s<<"s";
return 0;
}
