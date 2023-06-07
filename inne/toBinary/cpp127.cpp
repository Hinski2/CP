#include <bits/stdc++.h>
using namespace std;

int decimal, format;


int main()
{
    cout<<"decimal\n>";
    cin>>decimal;
    cout<<"format\n>";
    cin>>format;

    vector<bool>binary(format, 0);

    for(int idx = 0; decimal > 0; idx++)
    {
        binary[idx] = decimal % 2;
        decimal /= 2;
    }
    for(int i = binary.size() - 1; i >= 0; i--)
    {
        cout<<binary[i];
    }
}