#include <bits/stdc++.h>
using namespace std;

int x,y,a,b,c,d,o,aa[1000005],t;

int main()
{
    scanf("%d %d",&x,&y);
    for(int i=0;i<x;i++)
    {
        scanf("%d",&a);
        aa[i]=a;
    }
    sort(aa,aa+x);
    for(int i=0;i<x;i++)
    {
        o=min(x-i-1,y);
        if(b==0)
        {
            if(aa[i]==aa[i+1])
            {
                b=1;
                if(b+o>d)d=b+o;
            }
            if(aa[i]!=aa[i+1])
            {
                b=1;
                if(b+o>d)d=b+o;
                b=0;
            }

        }
        if(t==1)
        {
            if(aa[i]==aa[i+1])
            {
                b++;
                t=1;
                if(b+o>d)d=b+o;
            }
            if(aa[i]!=aa[i+1])
            {
                b++;
                t=0;
                if(b+o>d)d=b+o;
                b=0;
            }
        }
        if(b>0)
        {
            t=1;
        }
    }
    cout<<d;
}