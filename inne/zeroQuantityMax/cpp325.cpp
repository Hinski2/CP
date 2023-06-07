#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n, ans, add;
vector<vector<int>>vec;
map<pair<int, pair<int, int>>, int>mapa;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
    vec.resize(2);
    vec[0].resize(n);
    vec[1].resize(n);

    for(int k = 0; k < 2; k++)
        for(int i = 0; i < n; i++)
            cin >> vec[k][i];

    for(int i = 0; i < n; i++){
        int a = vec[0][i], b = vec[1][i], g = __gcd(a, b);

        if(!a && !b) add++;
        if(!a) continue;

        int c;
        if((long long)a * b < 0)c = 1;
        else c = -1;

        a = abs(a / g);
        b = abs(b / g);

        mapa[{c, {b, a}}]++;
    }

    for(auto u: mapa)
        ans = max(ans, u.se);

    cout << ans + add << '\n';
}


