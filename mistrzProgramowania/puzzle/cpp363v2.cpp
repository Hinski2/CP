#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int mak = 1e7 + 5;

vector<int>ans(mak, inf);

void compute_ans(){
    int sqr = sqrt(mak);
    for(int i = 1; i <= sqr + 1; i++){
        int j = 1;
        while(i * j <= mak){
            ans[i * j] = min(ans[i * j], (i + 2) * (j + 2) - i * j);
            j++;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    compute_ans();
    int q, x;
    cin >> q;
    while(q--){
        cin >> x;
        cout << ans[x] << '\n';
    }
}