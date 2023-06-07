#include <bits/stdc++.h>//70 pkt  
using namespace std;

long long ileCity,iAutostrada[50010];
long long lSuma,rSuma;

int main()
{
    scanf("%lld",&ileCity);
    for(int i=0;i<ileCity;i++)
    {
        int x;
        scanf("%d",&x);
        iAutostrada[i]=x;
    }
    sort(iAutostrada,iAutostrada+ileCity+1,greater<long long>());
    for(int i=0;i<ileCity;i++)
    {
        lSuma<rSuma?lSuma+=iAutostrada[i]:rSuma+=iAutostrada[i];
    }
    cout<<min(rSuma,lSuma)<<endl;
}
