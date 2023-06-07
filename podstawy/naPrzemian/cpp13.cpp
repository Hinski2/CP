#include <iostream>
using namespace std;

int main()
{
   int d;
   cin>>d;
   int *t;
   t  = new int [d];

   for(int i=0;i<d;i++)
   {
       cin>>t[i];
   }
   for(int i=0;i<d;i+=2)
   {
       cout<<t[i]<<" ";
   }
   cout<<endl;
   for(int i=1;i<d;i+=2)
   {
       cout<<t[i]<<" ";
   }
   return 0;
}
