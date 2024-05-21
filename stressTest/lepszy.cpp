#include <bits/stdc++.h>
using namespace std;

int m(long long n) {
    long long maska = 0x0F0F0F0F0F0F0F0F;
    long long m = (n >> 4) & maska;
    n &= maska;

    n += (n >> 8);
    n += (n >> 16);
    n += (n >> 32);

    m += (m >> 8);
    m += (m >> 16);
    m += (m >> 32);

    n &= 0xFF;
    m &= 0xFF;

    n -= m;
    if(n < 0)
        n += 136;
    
    m = (n >> 4) & 0xF;
    n &= 0xF;

    n -= m;
    if(n < 0)
        n += 17;

    return n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long x; cin >> x;
    cout << m(x) << endl;
}