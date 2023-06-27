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

void read_from_file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int n, target;
vector<ll>value, coin;

void count(int position, int i){
    if(position == target) return;

    for(;i < n; i++)
        if(position + coin[i] <= target){
            value[position + coin[i]]++;
            value[position + coin[i]] %= mod;

            count(position + coin[i], i);
        }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    //get input
    cin >> n >> target;
    value.resize(target + 1);
    coin.resize(n);

    for(int i = 0; i < n; i++)
        cin >> coin[i];

    //process
    value[0] = 1; 
    count(0, 0);

    //print ans
    cout << value[target] << '\n';
}
