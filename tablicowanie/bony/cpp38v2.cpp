#include <bits/stdc++.h>
using namespace std;

int ileBonow,ileDni;                      
bool iBon[1000005],used[1000005];   
int guest[1000005];                 
const int Max=1000000;
vector <long long> v;

int main()
{
    scanf("%d",&ileBonow);
    for(int i=1;i<=ileBonow;i++)
    {
        int q;
        scanf("%d",&q);
        iBon[q]=true;
    }

    used[0]=true;
    long long sold=1;

    scanf("%d",&ileDni);
    for(int i=0;i<ileDni;i++)
    {
        int ileOsob;
        scanf("%d",&ileOsob);
        
        for(int x=0;x<ileOsob;x++)
        {
            while(guest[ileOsob]*ileOsob<=Max && used[guest[ileOsob]*ileOsob]==true)
            {
                guest[ileOsob]++;
            }
            if(guest[ileOsob]*ileOsob>Max)break;
            if(iBon[guest[ileOsob]*ileOsob])v.push_back(sold+x);
            used[guest[ileOsob]*ileOsob]=true;
            guest[ileOsob]++;
        }
        sold+=ileOsob;
    }
    //wypisanie wyniku
    printf("%d\n",(int)v.size());
    for(auto z : v)
    {
        printf("%lld\n",z);
    }
}


