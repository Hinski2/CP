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
vector<pii> vec;

//does a should atay before b
bool cmp(pii a, pii b){
    return a.fi < b.fi;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()
 
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        vec.pb({x, i});
    }

    sort(vec.begin(), vec.end(), cmp);

    int ans = 1;
    for(int i = 0; i < n - 1; i++)
        if(vec[i].se > vec[i + 1].se) ans++;

    cout << ans << '\n';
}