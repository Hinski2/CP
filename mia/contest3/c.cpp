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
const ll inf = 1LL * 1e9 *1e9;
const int mak = 515; //do zmiany

ll n;
ll matrix[mak][mak], shortest[mak][mak];
vector<ll> v, ans;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> matrix[i][j], shortest[i][j] = inf;
    v.resize(n); ans.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    shortest[v.back()][v.back()] = 0;
    ans[n - 1] = 0;
}
int main(){
    get_input();
    ll sum = 0;
    for(int i = n - 2; i >= 0; i--){
        int ver = v[i];
        shortest[ver][ver] = 0;
        for(int j = i + 1; j < n; j++){
            shortest[v[j]][ver] = matrix[v[j]][ver]; sum += shortest[v[j]][ver];
            shortest[ver][v[j]] = matrix[ver][v[j]]; sum += shortest[ver][v[j]];
        }
        for(int j = i + 1; j < n; j++){
            for(int k = i + 1; k < n; k++){
                if(j == k) continue;
                if(shortest[v[j]][ver] > shortest[v[j]][v[k]] + shortest[v[k]][ver]){
                    sum -= shortest[v[j]][ver] - (shortest[v[j]][v[k]] + shortest[v[k]][ver]);
                    shortest[v[j]][ver] = shortest[v[j]][v[k]] + shortest[v[k]][ver];
                }
                if(shortest[ver][v[j]] > shortest[ver][v[k]] + shortest[v[k]][v[j]]){
                    sum -= shortest[ver][v[j]] - (shortest[ver][v[k]] + shortest[v[k]][v[j]]);
                    shortest[ver][v[j]] = shortest[ver][v[k]] + shortest[v[k]][v[j]];
                }
            }
        }

        for(int j = i + 1; j < n; j++){
            for(int k = i + 1; k < n; k++){
                if(j == k) continue;
                if(shortest[v[j]][v[k]] > shortest[v[j]][ver] + shortest[ver][v[k]]){
                    sum -= shortest[v[j]][v[k]] - (shortest[v[j]][ver] + shortest[ver][v[k]]);
                    shortest[v[j]][v[k]] = shortest[v[j]][ver] + shortest[ver][v[k]];
                }
                if(shortest[v[k]][v[j]] > shortest[v[k]][ver] + shortest[ver][v[j]]){
                    sum -= shortest[v[k]][v[j]] - (shortest[v[k]][ver] + shortest[ver][v[j]]);
                    shortest[v[k]][v[j]] = shortest[v[k]][ver] + shortest[ver][v[j]];
                }
            }
        }

        ans[i] = sum;
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
