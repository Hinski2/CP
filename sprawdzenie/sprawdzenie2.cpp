#include<bits/stdc++.h>
using namespace std;

struct node{
    int lNu;
    int lOcc;
    int rNu;
    int rOcc;
    int mNu;
    int mOcc;
}

int base = 1 << 18;
vector<unordered_map<int, int>>tree(base << 1);

int n, q;
void wczytaj(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;

        tree[i + base][x] = 1;
    }
}

void make_tree(){
    for(int i = base - 1; i > 0; i--){
        for(auto u: tree[i * 2])
            tree[i][u.fi] += u.se;
        for(auto u: tree[i * 2 + 1])
            tree[i][u.fi] += u.se;
    }
}

int query(int a, int b){
    a += base;
    b += base;

    unordered_map<int, int>ans;
    for(auto u: tree[a])
        ans[u.fi] += u.se;
    if(a != b)
        for(auto u: tree[b])
            ans[u.fi] += u.se;

    while(a >> 1 != b >> 1){
        if(a % 2 == 0)
            for(auto u: tree[a + 1])
                ans[u.fi] += u.se;
        if(b % 2 == 1)
            for(auto u: tree[b - 1])
                ans[u.fi] += u.se;
        a >>= 1;
        b >>= 1;
    }

    int occ = 0;
    for(auto u: ans)
        occ = max(occ, u.se);

    return occ;
}

int main(){
    wczytaj();
    make_tree();

    int a, b;
    while(q--){
        cin >> a >> b;
        cout << query(a, b) << '\n';
    }

    cin >> q;
}
