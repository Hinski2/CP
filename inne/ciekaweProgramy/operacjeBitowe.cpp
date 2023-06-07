#include <bits/stdc++.h>
using namespace std;

const int liczba_liczb = 8;

int main()
{
	int x,y,z;
	cin>>x>>y;
	
    string binary = bitset<liczba_liczb>(x).to_string(); //to binary
    string binary2 = bitset<liczba_liczb>(y).to_string(); //to binary
    
    z = x | y;
    string binary3 = bitset<liczba_liczb>(z).to_string(); //to binary
    z = x ^ y;
    string binary4 = bitset<liczba_liczb>(z).to_string(); //to binary
    z = x & y;
    string binary5 = bitset<liczba_liczb>(z).to_string(); //to binary
    
    cout<<binary<<"\n";
    cout<<binary2<<"\n";
    cout<<"________"<<"\n";
    cout<<binary3<<"	or"<<"""\n";
    cout<<binary4<<"	xor"<<"\n";
    cout<<binary5<<"	and"<<"\n";
}
