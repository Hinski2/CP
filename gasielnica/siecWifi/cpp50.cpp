#include <bits/stdc++.h>
using namespace std;

int ilePlan,ilePunktow,ileKlas;
double klasa[100010];
const double EPS = 1e-2;

bool sprawdzenie(double mid)
{
    double last=-1e19;
    int ile=0;
    for(int i=1;i<=ileKlas;i++)
    {
        if(klasa[i]-last-mid>EPS)
        {
            last=klasa[i]+mid;
            ile++;
        }
    }
    return ile<=ilePunktow;
}
int main()
{
    //*wczytywanie ilości planów
    scanf("%d",&ilePlan);
    while(ilePlan--)
    {
        //*wczytywanko dla każdego planu
        scanf("%d%d",&ilePunktow,&ileKlas);
        for(int i=1;i<=ileKlas;i++)
        {
            scanf("%lf",&klasa[i]);
        }
        //*liczenie
        sort(klasa+1,klasa+ileKlas+1);
        double s=0, cla=klasa[ileKlas];

        while(cla-s>EPS)
        {
            double mid=(cla+s+EPS)/2;
            if(sprawdzenie(mid))
            {
                cla=mid-EPS;
            }
            else
            {
                s=mid;
            }
        }
		printf("%.1lf\n", s);
    }
}