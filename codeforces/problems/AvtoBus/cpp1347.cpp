#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> pos(55, 1e9 + 7);
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        pos[x] = min(pos[x], i);
    }

    while(q--){
        int x; cin >> x;
        cout << pos[x] << ' ';
        for(auto &u: pos)
            if(u < pos[x]) u++;
        pos[x] = 1;
    }
    cout << endl;
}
