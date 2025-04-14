#include<bits/stdc++.h>
using namespace std;

#define int long long

int solve(){
    int n; cin >> n;
    vector<string> vs(n); 
    for(auto &u: vs) cin >> u;

    map<char, int> fi, se;
    map<string, int> all;

    for(auto u: vs){
        fi[u[0]]++;
        se[u[1]]++;
        all[u]++;
    }

    int ans = 0;
    for(auto u: vs){
        ans += fi[u[0]] - all[u];
        ans += se[u[1]] - all[u];
    }
    return ans / 2;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}