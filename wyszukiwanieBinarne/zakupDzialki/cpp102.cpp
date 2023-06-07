#include <bits/stdc++.h>
using namespace std;

const int maks = 2e5 + 15;
int n, q;
int dom[maks];

int sprawdzenie(int zapytanie)
{
    int l = 1, r = n;
    while(l + 1 < r)
    {
        int mid = (l + r) / 2;
        if(dom[mid] > zapytanie) //wynik po lewej
        {
            r = mid;
        }
        else if(dom[mid] < zapytanie) //wynik po prawej
        {
            l = mid;
        }
        else //idealnie wstrzelenie się 
        {
            return 0;
        }
    }

    int ans = min(abs(dom[l] - zapytanie), abs(dom[r] - zapytanie));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("a.out", "w", stdout);
    
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
    {
        cin>>dom[i];
    }

    for(int i = 1; i <= q; i++)
    {
        int zapytanie;
        cin>>zapytanie;

        cout<<sprawdzenie(zapytanie)<<"\n";
    }

}