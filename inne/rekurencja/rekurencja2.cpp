#include <bits/stdc++.h>
using namespace std;

long double potega (int p,int w)
{
    if(w==0) return 1;
    else return p*potega(p,w-1);
}

int main()
{
    cout<<setprecision(1000)<<potega(10,40)<<endl;
    return 0;
}