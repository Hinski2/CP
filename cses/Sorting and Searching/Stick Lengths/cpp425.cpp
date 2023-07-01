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

int n;
vector<int> stick;

ll process(int x){
    ll ans = 0;
    for(auto u: stick)
        ans += abs(u - x);

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    cin >> n; 
    stick.resize(n);

    for(int i = 0; i < n; i++)
        cin >> stick[i];

    sort(stick.begin(), stick.end());

    cout << process(stick[stick.size() / 2]) << '\n';

}
