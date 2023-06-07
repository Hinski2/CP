#include <bits/stdc++.h>
using namespace std;

const int MAKS=260;
int n,radious;
long long suma[MAKS][MAKS], arr[MAKS][MAKS], ans[MAKS][MAKS];
int main()
{
    //wczytywanie danych 
    scanf("%d%d",&n,&radious);
    for(int x=1; x<=n; x++)
    {
        for(int y=1; y<=n; y++)
        {
            scanf("%lld",&arr[x][y]);
        }
    }
    //obliczanie sum prefiksowych 
    for(int x=1; x<=n; x++)
    {
        for(int y=1; y<=n; y++)
        {
            suma[x][y]=arr[x][y]+suma[x-1][y]+suma[x][y-1]-suma[x-1][y-1];
        }
    }
    //obliczanie wyniku
    for(int x=1; x<=n; x++)
    {
        for(int y=1; y<=n; y++)
        {
            ans[x][y]=suma[min(x+radious,n)][min(y+radious,n)] - suma[min(x+radious,n)][max(y-radious-1,0)] - suma[max(x-radious-1,0)][min(y+radious,n)] + suma[max(x-radious-1,0)][max(y-radious-1,0)];
        }
    }
    //wypisanie wyniku
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
    }
    
}