#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second;
const ll SIZE = 3e5 + 7;
const ll MOD = 1e9 + 7;
const ll BASE = 179;
 
ll hsh[SIZE], potPre[SIZE];
string text;
 
void pre() {
    potPre[0] = 1;
    for(int i=1; i<=text.size(); i++) {
        potPre[i] = (1LL * potPre[i-1] * BASE) % MOD;
    }
    for(int i=0; i<text.size(); i++) {
        hsh[i+1] = (1LL * hsh[i] * BASE + text[i]) %MOD;
    }
}
 
ll getHash(int l, int r) {
    l++; r++;
    ll res = (hsh[r] - (1LL * hsh[l-1] * potPre[r-l+1])%MOD + MOD) %MOD;
    return res;
}
 
ll sprawdz(int x){
    unordered_map<ll, ll> mapa;
    for(int i = x; i < text.size(); i++)
        mapa[getHash(i - x, i)]++;
    unordered_map<ll, ll> jeden;
    for(auto u: mapa)
        if(u.second == 1) jeden[u.first] = 1;
    for(int i = x; i < text.size(); i++)
        if(jeden[getHash(i - x, i)] == 1) return getHash(i - x, i);
    return -1;
}
 
void znajdz(int x, int hasz){
    //cout << hasz << endl;
    for(int i = x; i < text.size(); i++){
        //cout << getHash(i - x, i) << endl;
    
        if(getHash(i - x, i) == hasz){
            for(int j = i - x; j <= i; j++)
                cout << text[j];
            cout << '\n';
            return;
        }
    }
}
 
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> text;
 
    pre();
    //for(int i = 0; i < text.size(); i++)
        //cout << sprawdz(i) << endl;
    int l = -1, r = text.size(), mid = 0, ans = sprawdz(0);
    if(ans != -1){
        znajdz(0, ans);
        exit(0);
    }
    while((l+1) < r){
        mid = (l + r) / 2;
        ans = sprawdz(mid);
        if(ans != -1) r = mid;
        else l = mid;
    }
        
    znajdz(r, sprawdz(r));
}