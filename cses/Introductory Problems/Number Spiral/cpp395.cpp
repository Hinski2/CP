#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll process(int i, int j){
    ll ans = 0, smaller, larger;

    //setting smaller and larger number
    if(i < j){
        smaller = i;
        larger = j;
    }
    else{
        smaller = j;
        larger = i;
    }

    ans += 1LL * (larger - 1) * (larger - 1);

    //if larger is odd we spin in differnet direction
    if(larger % 2 == 0) swap(i, j);

    if(i == larger)
        ans += j;
    else
        ans += 2 * j - i;
    
    return ans;
}


int main(){
    int t, i, j;
    cin >> t;

    while(t--){
        cin >> i >> j;
        cout << process(i, j) << '\n';
    }
}