#include <bits/stdc++.h>
using namespace std;

int i[1000005],y;

int main()
{
    scanf("%d",&y);
    for(int x=0;x<y;x++) scanf("%d",&i[x]);
    cout<<*min_element(i, i + y-1)<<".00";
    return 0;
}
