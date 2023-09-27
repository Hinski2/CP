#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second;
 
void solve() {
    int n;
    cin >> n;
    int ile = 1e5;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        ile = min(ile, b / a);
    }
 
 }
 
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    solve();
}