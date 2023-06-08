#include<bits/stdc++.h>
using namespace std;

const int mak = 2e5 + 15;
bitset<mak> bs;

int main(){
    //get data
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        bs[x] = 1;
    }

    for(int i = 1; i <= n; i++)
        if(!bs[i]) cout << i << '\n';
}

