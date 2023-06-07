#include <bits/stdc++.h>
using namespace std;

int arr[50];

int main()
{
    int i=0;
    while(1)
    {
        int x=0;
        cin>>x;

        if(x==0)break;

        arr[i]=x;
        i++;

        if(i>=45)break;
    }

    sort(arr,arr+i);
    int o=0;
    while(o<i-2)
    {
        if(arr[o]+arr[o+1]>arr[o+2])
        {
            printf("%d %d %d\n",arr[o],arr[o+1],arr[o+2]);
            return 0;
        }
        o++;
    }
    cout<<"NIE\n";
}