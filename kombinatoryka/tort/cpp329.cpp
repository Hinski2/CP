#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mak = 2e5 + 15;

ll n, a, b, k;
ll h[mak], w[mak];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a >> b >> n >> k;

    int last = 0, v;
    for(int i = 0; i < n; i++){
        cin >> v;
        h[i] = v - last;
        last = v;
    }
    h[n] = a - last;

    last = 0;
    for(int i = 0; i < n; i++){
        cin >> v;
        w[i] = v - last;
        last = v;
    }
    w[n] = b - last;
}

ll policz(ll mid){
    ll ans = 0, x = -1;

    for(int y = n; y >= 0; y--){
        while(x < n && h[x + 1] * w[y] < mid) x++;
        ans += n - x;
    }

    return ans;
}

void bs(){
    ll l = h[0] * w[0], r = h[n] * w[n], mid;
    while(l < r){
        mid = (l + r + 1) / 2;
        
        if(policz(mid) < k) r = mid - 1;
        else l = mid;
    }

    cout << l << '\n';
}

int main(){
	wczytaj();
	sort(h, h + n + 1);
    sort(w, w + n + 1);
	bs();
}