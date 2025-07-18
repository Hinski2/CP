#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v){
    for(const auto &u: v){
        os << u << ' ';
    }
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v){
    for(auto& u : v){
        is >> u;
    }
    return is;
}

template<typename T> long long sum(const vector<T> &v){
    long long s = 0;
    for(auto u: v) s += u;
    return s;
}

template<typename T> T max(const vector<T> &v){
    T maxi = v[0];
    for(auto u: v) maxi = max(maxi, u);
    return maxi;
}

template<typename T> T min(const vector<T> &v){
    T mini = v[0];
    for(auto u: v) mini = min(mini, u);
    return mini;
}

template<typename T> unsigned arg_max(const vector<T> &v){
    T maxi = v[0];
    unsigned pos = 0;
    for(unsigned i = 1; i <= v.size(); i++)
        if(v[i] > maxi){
            maxi = v[i];
            pos = i;
        }
    return pos;
}

template<typename T> unsigned arg_min(const vector<T> &v){
    T mini = v[0];
    unsigned pos = 0;
    for(unsigned i = 1; i <= v.size(); i++)
        if(v[i] < mini){
            mini = v[i];
            pos = i;
        }
    return pos;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define yn (solve() ? "YES" : "NO")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 1000 + 7;

class Matrix {
    /*
        90 deg rotations:
            (i, j) -> (j, n - 1 - i) -> (n - 1 - i, n - 1 - j) -> (n - 1 - j, i) -> (i, j)
    */
    vector<vector<char>> mat;

    void reverse_each_row() {
        for(int i = 0; i < n; i++)
            reverse(all(mat[i]));
    }

    void reverse_each_col() {
        for(int j = 0; j < n; j++) 
            for(int i = 0; i < n / 2; i++)
                swap(mat[i][j], mat[n - i - 1][j]);
    }

    void transpose() {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                swap(mat[i][j], mat[j][i]);
    }

public:
    const int n;
    Matrix(int n) : n(n) {
        mat.resize(n);
        for(int i = 0; i < n; i++)
            mat[i].resize(n);
    };

    char& operator () (int i, int j) {
        return mat[i][j];
    }

    friend istream& operator >> (istream& in, Matrix& mat) {
        for(int i = 0; i < mat.n; i++)
            for(int j = 0; j < mat.n; j++)
                in >> mat(i, j);

        return in;
    }

    friend ostream& operator << (ostream& out, Matrix& mat) {
        for(int i = 0; i < mat.n; i++) {
            for(int j = 0; j < mat.n; j++)
                out << mat(i, j) << ' ';
            out << endl;
        }

        return out;
    }

    void rotate_plus_90() {
        transpose();
        reverse_each_row();
    }

    void rotate_minus_90() {
        transpose();
        reverse_each_col();
    }

    void rotate_plus_180() {
        reverse_each_row();
        reverse_each_col();
    }

    void rotate_minus_180() {
        reverse_each_col();
        reverse_each_row();
    }
};


int solve() {
    int n; cin >> n;
    Matrix a(n); cin >> a;
    int ans = 0;

    for(int i = 0; i * 2 < n; i++) {
        for(int j = 0; j * 2 < n; j++) {
            vector<char> b {a(i, j), a(n - 1 - j, i), a(j, n - 1 - i), a(n - 1 - i, n - 1 - j)};
            auto maxi = *max_element(all(b));
            for(auto u: b) {
                ans += maxi - u;
            }
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
        cout << solve() << endl;
}
