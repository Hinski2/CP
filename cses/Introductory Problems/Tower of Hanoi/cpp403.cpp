#include<bits/stdc++.h>
using namespace std;

void Set(int ammount, int from, int to, int thrue){
    if(ammount != 1) 
        Set(ammount - 1, from, thrue, to);
        
    cout << from << ' ' << to << '\n';

    if(ammount != 1) 
        Set(ammount - 1, thrue, to, from);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';

    Set(n, 1, 3, 2);
}
