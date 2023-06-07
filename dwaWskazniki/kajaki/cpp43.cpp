#include <bits/stdc++.h>
using namespace std;

int MaxWaga,ileOsob,iWaga[30005],x=1,rent;
int main()
{
    scanf("%d%d",&MaxWaga,&ileOsob);
    for(int i=0;i<ileOsob;i++)
    {
        scanf("%d",&iWaga[i]);
    }
    sort(iWaga,iWaga+ileOsob);
    int y;
    while(y<=ileOsob-x)
    {
        if(y==ileOsob-x)
        {
            rent++;
            x++;
            break;
        }
        if(iWaga[ileOsob-x]+iWaga[y]<=MaxWaga)//mieści się w normie
        {
            x++;
            y++;
            rent++;
        }
        else //nie mieści się w normie
        {
            rent++;
            x++;
        }
    }
    cout<<rent<<endl;
}