#include<bits/stdc++.h>
using namespace std;

int n;
set<int>Set;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        Set.insert(x);
    }

    cout << Set.size() << '\n';
}
