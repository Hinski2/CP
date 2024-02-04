#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}
template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    for(auto& u : v){
        is >> u;
    }
    return is;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define yn (solve() ? "YES" : "NO")

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
char s[20];

inline bool digit(char c){
    return ('0' <= c && c <= '9');
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        n = strlen(s);
        ll c = 1;

        while(c < n && isdigit(s[c])) 
            c++;

        if(c > 1 && c < n){
            ll col = 0;
            for(int i = c + 1; i < n; i++)
                col = col * 10 + (s[i] - '0');

            ll pow = 26;
            while(col > pow){
                col -= pow;
                pow *= 26;
            }
            col--;

            while(pow != 1){
                pow /= 26;
                printf("%c", col / pow + 'A');
                col %= pow;
            }

            s[c] = 0;
            printf("%s\n", s + 1);
        }
        else{
            ll col = 0, val = 0, pow = 1;
            ll i = 0;
            while(isalpha(s[i])){
                col += pow;
                pow *= 26;
                val = val * 26 + s[i] - 'A';
                i++;
            }
            col += val;
            printf("R%sC%lld\n", s + i, col);
        }
    }
}
