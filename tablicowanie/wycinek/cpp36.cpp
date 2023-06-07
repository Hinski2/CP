#include <bits/stdc++.h> 
using namespace std;
long long fin,cel,ile,scan,y=0,l,r,mid,ans=-1,wynik,pierwsza;
long long suma[1000005];
vector<pair<long long,int> >v;

int main()
{
    scanf("%lld %lld",&ile,&cel);

    suma[0]=0;
    for(int i=1;i<=ile;i++)
    { 
        scanf("%lld",&scan);
        suma[i]=suma[i-1]+scan;
        v.push_back({suma[i],i});
    }
    v.push_back({0,0});

    sort(v.begin(),v.end());

    for(int x=ile;x>=0;x--)
    {
        fin=v[x].first-cel;
        r=ile;
        l=0;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(v[mid].first==fin)
            {
                pierwsza=mid;
                while(l<=r)
                {
                    if(r==l&&v[pierwsza].first==fin)
                    {
                        break;
                    }
                    if(v[pierwsza].first!=fin)
                    {
                        l=pierwsza+1;
                    }
                    else
                    {
                        r=pierwsza-1;
                    }
                    pierwsza=l+(r-l)/2;
                }
                wynik=v[x].second-v[pierwsza].second;
                ans=max(wynik,ans);
                y=0;
                break;
            }
            if(v[mid].first<fin)
            {  
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
    }
    if(ans==-1)
    {
        printf("BRAK");
        return 0;
    }
    printf("%lld",ans);
}