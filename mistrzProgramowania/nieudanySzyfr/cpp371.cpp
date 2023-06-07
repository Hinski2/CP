#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

string s;

void policz(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s;
	ll suma_l = 1, suma_ll = 1;
    for(int i = 1; i < s.size(); i++){
        ll teraz = 0;
        if(s[i] - '0') teraz = suma_l;
        if(s[i - 1] - '0' == 1)
            teraz += suma_ll;
        else if(s[i - 1] - '0' == 2 && s[i] - '0' < 7)
            teraz += suma_ll;
        
        teraz %= mod;
        suma_ll = suma_l; 
        suma_l = teraz;
    }

    cout << suma_l << '\n';
}

int main(){
	policz();
}

