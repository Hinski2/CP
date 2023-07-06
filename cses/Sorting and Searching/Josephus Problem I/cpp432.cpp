#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

set<int> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        s.insert(i);

    bool add = 1;
    while(!s.empty()){
        auto now = s.begin();
        if(add) now++;
        add = false;

        auto next = now;
        if(next != s.end()) next++;
        if(next != s.end()) next++;

        while(now != s.end()){
            cout << *now << ' ';
            s.erase(now);

            if(next == s.end()) break;
            now = next;

            if(++next == s.end()){
                add = true;
                continue;
            }
            if(++next == s.end()) add = false;
        }
    }
}
