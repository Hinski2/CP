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

int find_maxx(int n){
    int maxx = 0;
    while(n){
        maxx = max(maxx, n % 10);
        n /= 10;
    }

    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    int n;
    cin >> n;

    int step = 0;
    while(n){
        int maxx = find_maxx(n);
        n -= maxx;
        step++;
    }

    cout << step << '\n';
}
