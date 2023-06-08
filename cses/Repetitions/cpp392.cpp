#include<bits/stdc++.h>
using namespace std;

int main(){
    //get data
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;

    char c = '#'; //last character;
    int cnt = 0, ans = 0; //chow many times last character occured

    for(int i = 0; i < str.size(); i++){
        if(str[i] == c) cnt++;
        else{
            cnt = 1;
            c = str[i];
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}