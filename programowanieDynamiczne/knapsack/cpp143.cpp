#include <bits/stdc++.h>
using namespace std;

const int mak = 1e6 + 5;

bitset<mak>can;
int n, f;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>f;
    can[0] = 1;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin>>x;

        can |= (can << x);
    }

    for(int i = 1; i <= f; i++)
    {
        cout<<i<<" "<<can[i]<<endl;
    }
}