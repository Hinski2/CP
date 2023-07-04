#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;
    
int n, ans;
multiset<int> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;

        auto itr = s.upper_bound(x);
        if(itr == s.end()){
           ans++;
           if(x != 1) s.insert(x);
        }
        else{
            s.erase(itr);
            if(x != 1) s.insert(x);
        }
    }

    cout << ans << '\n';
}
