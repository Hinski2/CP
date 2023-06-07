#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int x=0,i=0;
    string str;
    cin>>str;
    int y = str.length();
    reverse(str.begin(), str.end());
    for(;i<y;i++)
    {
       if(x==0 && str[i]!='0')
       {
           x=1;
       }
       if(x==1)
       {
           cout<<str[i];
       }
    }

    return 0;
}
