#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s = n-1;
    int x = 1;
    //cz 1
    for(int l=1;l<=n;l++)
    {
        for(int i=0;i<=s;i++) cout<<" ";
        s--;
        for(int i=0;i<x;i++) cout<<"*";
        x+=2;
        cout<<endl;
    }
    //cz 2
    s = n-1;
    x = 1;
        for(int l=0;l<=n;l++)
    {
        for(int i=0;i<=s;i++) cout<<" ";
        s--;
        for(int i=0;i<x;i++) cout<<"*";
        x+=2;
        cout<<endl;
    }
    //podstawa
    for(int i = 1;i<=n;i++) cout<<" ";
    cout<<"*"<<endl;
    for(int i = 1;i<=n;i++) cout<<" ";
    cout<<"*"<<endl;

    return 0;
}
