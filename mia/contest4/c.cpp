#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int,null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int n, ans = 0, mian = 1, c;
vector<int> p, sajz, alone, vis;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    p.resize(n + 1); vis.resize(n + 1); sajz.resize(n + 1);
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        p[i] = x;
        if(p[i] == i) c = i;
    }
}

int find(int x){
    if(x == p[x]) return x;
    return find(p[x]);
}

void check(int v, int no){
    vis[v] = 1;
    if(p[v] == v){
        sajz[v] = no;
        alone.pb(v);
        vis[v] = 2;
        return;
    }
    if(vis[p[v]] == 2){
        // sajz[find(v)] += no;
        vis[v] = 2;
        return;
    }

    if(vis[p[v]] == 1){
        sajz[v] = no;
        alone.pb(v);

        if(!c){
            c = v;
            p[v] = v;
            ans++;
        }    
        else
            p[v] = v;
    }
    else if(!vis[p[v]]) check(p[v], no + 1);
    vis[v] = 2;
}

void onion(int a){
    a = find(a);

    if(a == c) return;
    ans++;
    sajz[c] += sajz[a];
    p[a] = c;
}

int main(){
    get_input();
    for(int i = 1; i <= n; i++)
        if(p[i] == i && !vis[i]) sajz[i] = 1, alone.pb(i);
        else if(!vis[i]) check(i, 1);

    for(auto u: alone)
        onion(u);

    cout << ans << endl;
    for(int i = 1; i <= n; i++)
        cout << p[i] << ' ';
    cout << endl;
    
    
}
