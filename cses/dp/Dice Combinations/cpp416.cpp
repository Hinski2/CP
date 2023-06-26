#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<ll> ways(n + 6);
    ways[0] = 1;

    for(int i = 0; i < n; i++)
        for(int j = 1; j <= 6; j++){
            ways[i + j] += ways[i];
            ways[i + j] %= mod;
        }

    cout << ways[n] << '\n';
}
