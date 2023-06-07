#include <bits/stdc++.h>
using namespace std;
int n,d,x,y,z,zz[300000]; //n-ilość d-różnica
set<int> s;

int main()
{
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        if(x==1)
        {
            s.insert(y);
            if(s.find(y+d)!= s.end()==1)
            {
                z+=1;
            }
            if(s.find(y-d)!= s.end()==1)
            {
                z+=1;
            }

        }
        if(x==-1)
        {
            if(s.find(y+d)!= s.end()==1)
            {
                z-=1;
            }
            if(s.find(y-d)!= s.end()==1)
            {
                z-=1;
            }
            s.erase(y);
        }
        zz[i]=z;
    }
    for(int i=0;i<n;i++)
    {
        cout<<(zz[i]>=1 ?"TAK":"NIE" )<<"\n";
    }
}