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

void wypisz(vector<int> &v, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << v[i * n + j] << ' ';
        cout << endl;
    }
    cout << endl;
}


int main(){
    int n = 5;
    vector<int> a(n * n), b(n * n);
    for(int i = 0; i < n; i++)
        a[i] = a[i * n] = 0;

    for (long i = 1; i < n; i++)
        for (long j = 1; j < n; j++)
            a[j * n + i] = i * j;

    wypisz(a, n);

    for (long i = 1; i < n; i++)
        for (long j = 1; j < n; j++)
            b[i * n + j] = a[i * n + j] + a[(i - 1) * n + (j - 1)];

    wypisz(b, n);

    //v2
    long itr1 = 0; 
    for (long i = 0; i < n; i++){
        a[itr1] = a[i] = 0;
        itr1 += n;
    }

    itr1 = n + 1;   
    long itr2 = 0;  
    long val = 0;   //dodanie zmiennej pomocniczej

    for (long i = 1; i < n; i++){
        val = i;
        for (long j = 1; j < n; j++){
            a[itr1] = val;
            val += i;

            b[itr1] = a[itr1] + a[itr2];
            itr1++;
            itr2++;
        }

        // przejście do następnej lini 
        itr1++;
        itr2++;
    }
    wypisz(a, n);
    wypisz(b, n);
}
