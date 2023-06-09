#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, mid;
    cin >> n;

    //special case
    if(n == 1){
        cout << "1\n";
        exit(0);
    }

    //it's inpossible only when n is smaller than 4
    if(n < 4){
        cout << "NO SOLUTION\n";
        exit(0);
    }

    int l = 1, r = n;
    mid = n / 2;

    //printing first part of permutation
    cout << mid + 1 << ' ';

    //printing middle part of permutation
    while(r - l >= 2) cout << l++ << ' ' << r-- << ' ';

    //printing ending part of permutation
    if(n % 2 == 0)
        cout << mid << '\n';
}





