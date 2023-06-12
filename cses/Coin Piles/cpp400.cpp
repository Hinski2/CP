#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        if(a < b) swap(a, b); //a is bigger than b
        int cropp = a - b;
        a -= 2 * cropp;
        b -= cropp;

        
        if(a == b && a % 3 == 0 && a >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
