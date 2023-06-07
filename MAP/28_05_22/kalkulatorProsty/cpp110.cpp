#include <bits/stdc++.h>
using namespace std;

int x, y; //x poprawny, y kalkulator

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>x>>y;


    if(x == y)
    {
    	cout<<x<<"+0\n";
    }
    else if(x == 0)
    {
    	cout<<"NIE\n";
    }
    else if(x > y)
    {
    	cout<<x<<"-"<<y<<"+1*0+"<<y<<"\n";
    }
    else if(x < y)
    {
        cout<<x<<"+0/"<<x<<"+0*"<<y<<"\n";
    }
}