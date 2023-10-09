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

int n, r;
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r;
}

int solve(int a, int b = r){
    if(a == 1 && b == 1 && n == 1) return 0;

    int ans = 0, operacje = 0;
    while(a != 0 && b != 0 && a != b){
        if(a < b) swap(a, b); //a is bigger
        if(b == 1){
            operacje += a;
            ans += a - 2;
            b = 0;
            
            if(operacje == n) return ans;
            break;
        }

        ans += a / b - 1;
        operacje += a / b;
        a = a % b;
    }

    if(((a == 0 && b == 1) || (a == 1 && b == 0)) && operacje == n) return ans;
    return inf;
}

void odzyskaj(int a, int b, int score_ans){
    vector<char> v;
    while(a && b){
        if(a == 1 && b == 1){
            v.pb('T');
            break;
        }

        if(a >= b){
            v.pb('T');
            a -= b;
        }
        else if(b > a){
            v.pb('B');
            b -= a;
        }
    }
    int no_problems = 0;
    for(int i = 0; i < v.size() - 1; i++)
        if(v[i] == v[i + 1]) no_problems++;
    if(no_problems != score_ans) return;

    for(int i = v.size() - 1; i >= 0; i--) cout << v[i];
    cout << endl;
    exit(0);
}

int main(){
    get_input();
    int ans = -1, score_ans = inf;
    for(int i = 1; i <= r; i++){
        int wynik = solve(i);
        if(wynik < score_ans){
            score_ans = wynik;
            ans = i;
        }
    }

    if(ans == -1) cout << "IMPOSSIBLE\n";
    else{
        cout << score_ans << endl;
        odzyskaj(ans, r, score_ans);
        odzyskaj(r, ans, score_ans);
    }
}
