#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;

void read_from_file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

ll n;
ll gmax = -inf, lmax = -inf;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    cin >> n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;

        lmax = max(lmax + x, x);
        gmax = max(lmax, gmax);
    }

    cout << gmax << '\n';
}
