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

int n, no_stops;
set<int> Set;
stack<int>Stack;
vector<int>stop, sstop;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> no_stops;
    stop.resize(no_stops);
    sstop.resize(no_stops);

    for(int i = 0; i < no_stops; i++){
        cin >> stop[i];
        sstop[i] = stop[i];
    }

    sort(sstop.begin(), sstop.end());

    Stack.push(0);
    Set.insert(0);

    for(int i = 0, last = 0; i < no_stops; i++){
        Set.insert(sstop[i]);
        if(sstop[i] - last > Stack.top()){
            Stack.pop();
            Stack.push(sstop[i] - last);
        }

        last = sstop[i];
    }

    if(n - (*Set.rbegin()) > Stack.top()){
        Stack.pop();
        Stack.push(n - (*Set.rbegin()));
    }
    Set.insert(n);

    for(int i = no_stops - 1; i > 0; i--){
        auto itr1 = Set.lower_bound(stop[i]);
        auto itr2 = itr1; itr2--;

        Set.erase(itr1);
        itr1 = itr2;
        itr2 = Set.upper_bound(stop[i]);

        Stack.push(max(Stack.top(), *itr2 - (*itr1)));
    }

    while(!Stack.empty()){
        cout << Stack.top() << '\n';
        Stack.pop();
    }
}