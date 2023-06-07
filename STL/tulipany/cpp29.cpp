#include <bits/stdc++.h>
#include <set>
using namespace std;
 
set<int> s;
int x,y;
int main()
{
    cin>>x;
    for(int i=0;i<x;i++)
    {
        scanf("%d",&y);
        s.insert(y);
    }
    cout<<15000-s.size();
}