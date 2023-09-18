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

int n;
vector<int> v;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    v.resize(n + 2);
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    v[n + 1] = inf;
    
    //not imported in tchat implementation: 
    // map<int, int> mapa;
    // for(auto u: v) mapa[u] = 1;

    // int idx = 0;
    // for(auto &u: mapa) u.se = idx++;
    // for(auto &u: v) u = mapa[u];
}
int main(){
    get_input();

    int no = 0;
    bool started = false;
    for(int i = 1; i <= n; i++){
        if(v[i] > v[i + 1] && !started){
            no++;
            started = 1;
        }
        if(v[i] < v[i + 1] && started) started = 0;
    }

    if(no == 0){
        cout << "yes" << endl;
        cout << "1 1" << endl;
        exit(0);
    }
    if(no != 1){
        cout << "no" << endl;
        exit(0);
    }

    int start = -1, stop = -1;
    for(int i = 1; i <= n; i++){
        if(v[i] > v[i + 1] && start == -1)
            start = i; 
        if(v[i] < v[i + 1] && start != -1 && stop == -1)
            stop = i;
    }

    if(v[stop] > v[start - 1] && v[start] < v[stop + 1]){
        cout << "yes" << endl;
        cout << start << ' ' << stop << endl;
        exit(0);
    }
    else{
        cout << "no" << endl;
        exit(0);
    }
}
