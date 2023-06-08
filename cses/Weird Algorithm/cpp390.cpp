#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    //getting n
    ll n;
    cin >> n;

    //making simulation
    while(n != 1){
        cout << n << ' ';

        if(n & 1) //n is odd
            n = n * 3 + 1;
        else 
            n >>= 1;
    }

    cout << "1\n";
}
