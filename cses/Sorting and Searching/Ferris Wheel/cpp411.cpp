#include<bits/stdc++.h>
using namespace std;

int n, max_weight, ans = 0;
vector<int>children;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //get input
    cin >> n >> max_weight;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        children.push_back(x);
    }

    //sort children
    sort(children.begin(), children.end());

    //use 2 pointers method
    int l = 0, r = children.size() - 1;
    while(l <= r){
        if(children[l] + children[r] <= max_weight){
            l++;
            r--;
            ans++;
        }
        else{
            r--;
            ans++;
        }
    }

    cout << ans << '\n';
}



    
