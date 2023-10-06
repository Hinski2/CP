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
const int mak = 1e6 + 7;

ll n, m, sajz;
ll pref[mak], suf[mak];
string s;

void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s, sajz = s.size();
    cin >> n >> m;
}

void prepro(){
    ll mult = 10;
    pref[0] = (s[0] - '0') % n, suf[sajz - 1] = (s[sajz - 1] - '0') % m;

    for(int i = 1; i < sajz; i++)
        pref[i] = (pref[i - 1] * 10 + s[i] - '0') % n;
    for(int i = sajz - 2; i >= 0; i--){
        suf[i] = (suf[i + 1] + (s[i] - '0') * mult) % m;
        mult = (mult * 10) % m;
    }
}


void wypisz(int br){
    cout << "YES\n";
    for(int i = 0; i <= br; i++) cout << s[i];
    cout << endl;
    for(int i = br + 1; i < sajz; i++) cout << s[i];
    cout << endl;
    exit(0);
}
int main(){
    get_input();
    prepro();
    for(int i = 0; i < sajz - 1; i++)
        if(pref[i] == 0 && suf[i + 1] == 0 && s[i + 1] != '0') wypisz(i);

    cout << "NO\n";
}
