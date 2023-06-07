#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mak = 1e6 + 5;

ll phi(int x){
    if(x == 1) return 0;

    ll coprime = x;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            while(x % i == 0) x /= i;
            coprime -= coprime / i;
        }
    }

    if(x > 1) coprime -= coprime / x;
    return coprime;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int x;
	while(cin >> x && x != 0)
		cout << phi(x) << '\n';
}
