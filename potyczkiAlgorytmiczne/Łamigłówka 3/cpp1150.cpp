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
const int dif = 'Z' - 'A' + 2;

struct ANS{
    char axis;
    int numb;
    char color;
};

vector<vector<int>> x, y;
vector<vector<char>> mat;
vector<ANS> ans;

inline int nu(char c){
    return c - 'A';
}

inline int ile(vector<int> v){
    int cnt = 0;
    for(auto u: v)
        if(u != 0) cnt++;
    
    return cnt;
}

inline char kolor(vector<int> v){
    char kolor;
    for(int i = 0; i < v.size(); i++)
        if(v[i] != 0) kolor = 'A' + i;

    return kolor;
}

int main(){
    io; int n, m; cin >> n >> m;
    x.resize(n + 1);
    y.resize(m + 1);
    mat.resize(n + 1);

    for(int i = 1; i <= n; i++) x[i].resize(dif);
    for(int j = 1; j <= m; j++) y[j].resize(dif);

    for(int i = 1; i <= n; i++){
        mat[i].resize(m + 1);
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
            int c = nu(mat[i][j]);

            x[i][c]++;
            y[j][c]++;
        }
    }

    bool changed = true;
    while(changed){
        changed = false;
        for(int i = 1; i <= n; i++){
            if(ile(x[i]) == 1){
                char c = kolor(x[i]);
                int cint = c - 'A';

                ans.pb({'R', i, c});
                x[i][cint] = 0;

                for(int j = 1; j <= m; j++){
                    if(mat[i][j] == c){
                        y[j][cint]--;
                        mat[i][j] = -1;
                    }
                }

                changed = true;                    
                break;
            }
        }

        if(changed) continue;

        for(int j = 1; j <= m; j++){
            if(ile(y[j]) == 1){
                char c = kolor(y[j]);
                int cint = c - 'A';
                ans.pb({'K', j, c});
                y[j][cint] = 0;

                for(int i = 1; i <= n; i++){
                    if(mat[i][j] == c){
                        x[i][cint]--;
                        mat[i][j] = -1;
                    }
                }
                
                changed = true;
                break;
            }
        }
    }

    int s = ans.size(); cout << s << endl;
    for(int i = s - 1; i >= 0; i--)
        cout << ans[i].axis << ' ' << ans[i].numb << ' ' << ans[i].color << endl;
}
