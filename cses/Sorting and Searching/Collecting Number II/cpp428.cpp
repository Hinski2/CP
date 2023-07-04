#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

void read_from_file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int n, m, ans = 1;
int numb[mak], pos[mak];

void update(int a, int b){
    if(pos[numb[a] - 1] <= pos[numb[a]] && b < pos[numb[a] - 1]) ans++;
    if(pos[numb[a] - 1] > pos[numb[a]] && b >= pos[numb[a] - 1]) ans--;
    if(pos[numb[a]] <= pos[numb[a] + 1] && b > pos[numb[a] + 1]) ans++;
    if(pos[numb[a]] > pos[numb[a] + 1] && b <= pos[numb[a] + 1]) ans--;
    pos[numb[a]] = b;

    if(pos[numb[b] - 1] <= pos[numb[b]] && a < pos[numb[b] - 1]) ans++;
    if(pos[numb[b] - 1] > pos[numb[b]] && a >= pos[numb[b] - 1]) ans--;
    if(pos[numb[b]] <= pos[numb[b] + 1] && a > pos[numb[b] + 1]) ans++;
    if(pos[numb[b]] > pos[numb[b] + 1] && a <= pos[numb[b] + 1]) ans--;
    pos[numb[b]] = a;

    swap(numb[a], numb[b]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //read_from_file()

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> numb[i];
        pos[numb[i]] = i;
    }

    pos[n + 1] = n + 1;
    for(int i = 1, ptr = 0; i <= n; i++){
        if(ptr > pos[i]) ans++;
        ptr = pos[i];
    }

    while(m--){
        int a, b;
        cin >> a >> b;

        update(a, b);
        cout << ans << '\n';
    }
}
