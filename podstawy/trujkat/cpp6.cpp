#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int array[3];
    cin>>array[0]>>array[1]>>array[2];
    sort(array,array+3);
    if(array[0]+array[1]>array[2])
    {
        cout<<"TAK";
    }
    else cout<<"NIE";
    return 0;
}
