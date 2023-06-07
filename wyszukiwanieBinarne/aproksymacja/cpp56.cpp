#include <bits/stdc++.h>
using namespace std;

const double epsilon = 1e-6;
double arr[1000010],ans[10000010];
int ileLiczb;

//obliczanie przypadków w czasie liniowym 
bool sprawdzenie(double x)
{
    if(x < epsilon)
    {
        return false;
    }
    double y = arr[1] - x;
    ans[1] = y;
    for(int i = 2;i <= ileLiczb;i++)
    {
        y=max(arr[i]-x, y);
        if(y - arr[i] - x > epsilon)return false;
        ans[i] = y;
    }
    return true;
}

int main()
{
    //wczytywanie 
    scanf("%d",&ileLiczb);
    for(int i=1;i<=ileLiczb;i++)
    {
        scanf("%lf",&arr[i]);
    }

    //strzelanie w wynik 
    double l=0,r=2100000;

    while(r - l > epsilon)
    {
        double x = (r + l)/2;
        if(sprawdzenie(x))
        {
            r = x;
        }
        else
        {
            l = x + epsilon;
        } 
    }

    //wypisywanie wyniku
    printf("%.5lf\n",l);
    for(int i = 1;i <= ileLiczb;i++)
    {
        printf("%.5lf\n",ans[i]);
    }
}