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
const int mak = 2e5 + 7;

void read_from_file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int n, val[mak];
map<int, int> mapa;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> val[i];
    
    int ans = 0;
    for(int start = 0, i = 0; start < n; start++){
        while(i < n && mapa[val[i]] < 1){
            mapa[val[i]]++;
            i++;
        }
        ans = max(ans, i - start);
        mapa[val[start]]--;
    }

    cout << ans << '\n';
}
