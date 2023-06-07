#include<iostream>
#include<cmath>
using namespace std;
 
int main()
{
    long long n, pierw, pom;
 
        cout<<"Podaj liczbę: ";
        cin>>n;
        
        pierw = sqrt(n);
 
        cout<<"Czynniki pierwsze liczby "<<n<<": ";
 
        long long k=2; //ustawiamy k na pierwszą liczbę pierwszą
 
        //rozkład liczby na czynniki pierwsze
        while(n>1&&k<=pierw)
        {
                while(n%k==0) //dopóki liczba jest podzielna przez k
                {
                        cout<<k<<" ";
                        n/=k;
                }
                ++k;
        }
        
        if(n>1)
               cout<<n;
        cout<<endl;
 
        return 0;
}
