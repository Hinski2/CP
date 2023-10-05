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

string s1, s2;
int pos1, pos2, quest;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    for(auto u: s1){
        if(u == '+') pos1++;
        else pos1--;
    }
    for(auto u: s2){
        if(u == '+') pos2++;
        else if(u == '-') pos2--;
        else quest++;
    }

    cout << setprecision(11) << fixed;
}
int main(){
    get_input();

    double ans = 0;
    if(abs(pos1 - pos2) > quest || abs(pos1 - pos2) % 2 != quest % 2){
        cout << ans << endl;
        return 0;
    }

    int moves = (quest + abs(pos1 - pos2)) / 2;
    int c = 1;
    for(int i = 0; i < moves; i++)
        c *= quest - i;
    for(int i = 2; i <= moves; i++)
        c /= i;
    ans = (double)c / (1 << quest);
    cout << ans << endl;

}
