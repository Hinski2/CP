#include<bits/stdc++.h>
using namespace std;

typedef vector<bool> vec;
const int mak = 8;

int ans;
bool reserved[mak][mak];

vec col(2 * mak, 0), crossI(2 * mak, 0), crossD(2 * mak, 0);

void place(int r){
    if(r == 8){
        ans++;
        return;
    }

    for(int c = 0; c < mak; c++){
        if(col[c] || crossI[r + c] || crossD[r - c + 7] || reserved[r][c]) continue;
        col[c] = crossI[r + c] = crossD[r - c + 7] = 1;
        place(r + 1);
        col[c] = crossI[r + c] = crossD[r - c + 7] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //get the chessboard
    for(int i = 0; i < mak; i++)
        for(int j = 0; j < mak; j++){
            char c;
            cin >> c;

            if(c == '*') reserved[i][j] = 1;
        }
    
    //place queens
    place(0);   
    
    cout << ans << '\n';
}
    
