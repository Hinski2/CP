#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, res = 0, numb = 5;
    cin >> n;

    while(n / numb){
        res += n / numb;
        numb *= 5;
    }

    cout << res << '\n';
}