#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const ll mak = 2e5 + 7;

void read_from_file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int n;
ll maks = 0;
vector<ll>values;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        values.pb(x);
    }

    sort(values.begin(), values.end());
    for(auto u: values){
        if(u > maks + 1){
            cout << maks + 1 << '\n';
            exit(0);
        }

        maks += u;
    }
    
    cout << maks + 1 << '\n';
}
