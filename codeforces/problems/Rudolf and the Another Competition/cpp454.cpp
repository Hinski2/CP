#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

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

struct person{
    int id;
    int points;
    ll penalty;
};

int t;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
}

//czy a ma stać przed b
bool cmp(person a, person b){
    if(a.points != b.points) return a.points > b.points;
    if(a.penalty == b.penalty) return a.id == 0;
    return a.penalty < b.penalty;
}

int solve(){
    int n, no_problems, tajm;
    cin >> n >> no_problems >> tajm;
    vector<person> rank(n);

    for(int i = 0; i < n; i++){
        vector<int>problems(no_problems);
        for(int j = 0; j < no_problems; j++)
            cin >> problems[j];
        sort(all(problems));

        rank[i].id = i;
        for(int j = 0, czas = 0; czas <= tajm && j < no_problems; j++)
            if(czas + problems[j] <= tajm){
                rank[i].points++;
                czas += problems[j];
                rank[i].penalty += czas;
            }
    }

    sort(all(rank), cmp);
    int pos = 0;
    while(rank[pos].id)
        pos++;

    return pos + 1;
}


int main(){
    get_input();
    while(t--)
        cout << solve() << '\n';
}
