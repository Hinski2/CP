#include<bits/stdc++.h>
using namespace std;

int n, target;
map<int, int>values;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> target;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        if(values[target - x]){
            cout << values[target - x] << ' ' << i << '\n';
            exit(0);
        }

        values[x] = i;
    }

    cout << "IMPOSSIBLE\n";
}
