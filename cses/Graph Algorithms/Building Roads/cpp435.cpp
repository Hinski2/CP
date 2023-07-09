#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

int n, m;
int parent[mak], sajz[mak];
set<int> alone; 

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void onion(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(sajz[a] < sajz[b]) swap(a, b);
    alone.erase(b);

    sajz[a] += sajz[b];
    parent[b] = a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        alone.insert(i);
        sajz[i] = 1;
        parent[i] = i;
    }

    for(int i = 1, a, b; i <= m; i++){
        cin >> a >> b;
        onion(a, b);
    }

    cout << alone.size() - 1 << '\n';

    auto itr1 = alone.begin();
    auto itr2 = itr1; itr2++;

    while(itr2 != alone.end()){
        cout << *itr1 << ' ' << *itr2 << '\n';
        itr1++; itr2++;
    }
}
