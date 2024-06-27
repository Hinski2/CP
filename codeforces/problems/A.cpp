#include <bits/stdc++.h>
using namespace std;

int solve(){
    int x, y; cin >> x >> y; 
    int z = (y + 1) / 2;
    x -= (z * 15 - y * 4);
    x = max(x, 0);
    z += (x + 14) / 15;
    return z;
}

int main(){
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}