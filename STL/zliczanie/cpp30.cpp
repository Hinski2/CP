#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    vector<tuple<int, int, int> > t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        t.push_back(make_tuple(b,i,a));
    }
    sort(t.begin(), t.end());
     for (int i = 0; i < t.size(); i++)
     {
        cout<< get<2>(t[i]) << "\n";
     }
 
    return 0;
}