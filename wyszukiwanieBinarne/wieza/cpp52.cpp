#include <bits/stdc++.h>
using namespace std;

int ileSchodkow,ileOsob;
int osoba[500010],schodek[500010];


int pos(int person)
{
    int l=0,r=ileSchodkow;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(schodek[mid]>=person) //schodek>=osoby
        {
            r=mid-1;
        }
        else                    //schodek<osoba
        {
            l=mid;
        }
    }
    return (l+r+1)/2;
}

int main()
{
    //*wczytywanie 
    cin>>ileSchodkow>>ileOsob;
    for(int i=1;i<=ileSchodkow;i++)
    {
        cin>>schodek[i];
        schodek[i]=max(schodek[i],schodek[i-1]);
    }
    for(int i=1;i<=ileOsob;i++)
    {
        cin>>osoba[i];
    }
    //*liczenie 
    for(int i=1;i<=ileOsob;i++)
    {
        cout<<pos(osoba[i])<<" ";
    }
}