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

int t;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

bool solve(){
    int n, target;
    cin >> n >> target;

    set<int> s;
    queue<int> q;

    q.push(n);
    s.insert(n);

    while(!q.empty()){
        if(q.front() % 3 != 0){
            q.pop();
            continue;
        }
        int no = q.front() / 3;

        if(!s.count(no)){
            s.insert(no);

            if(no) q.push(no);
       }

        if(!s.count(no * 2)){
            s.insert(no * 2);

            if(no * 2) q.push(no * 2);
       }

       q.pop();
   }

   return s.count(target);
}

int main(){
    get_input();
    while(t--)
        cout << (solve() ? "YES" : "NO") << endl;
}
