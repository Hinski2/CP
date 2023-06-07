#include <bits/stdc++.h>
using namespace std;

int m,n,x[1005],y[1005];
long long ans=0;

int main()
{
    // wczytywanie ilości wierszy, kolumn
    scanf("%d %d",&m,&n);
    //wczytywanie watrości każdego x
    for(int i=1;i<m;i++)
    {
        scanf("%d",&x[i]);
    }
    //wczytywanie wartości każdego y
    for(int i=1;i<n;i++)
    {
        scanf("%d",&y[i]);
    }
    //*koniec wczytywania początek liczenia
    x[0]=0;
    y[0]=0;

    sort(x+1,x+m);//sortowanie
    sort(y+1,y+n);//sortowanie

    int xIndex=m-1;
    int yIndex=n-1;

    while(xIndex>0||yIndex>0)
    {
        if(x[xIndex]>y[yIndex])
        {
            ans+=x[xIndex]*(n-yIndex);
            xIndex--;
        }
        else
        {
            ans+=y[yIndex]*(m-xIndex);
            yIndex--;
        }
    }
    printf("%lld\n",ans);
}