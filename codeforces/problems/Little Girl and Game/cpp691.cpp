#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tree<int,null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
//erase: oms.erase(oms.upper_bound(value))

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

string s;
int ile[alf];
void get_input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for(auto u: s) ile[u]++;
}

bool pal(){
	int ileN = 0;
	for(int i = 'a'; i <= 'z'; i++)
		ileN += ile[i] % 2;

	return ileN < 2;
}

void usun(){
	for(int i = 'a'; i <= 'z'; i++){
		if(ile[i] == 0) continue;

		ile[i]--;
		if(pal()) ile[i]++;
		else return;
	}
	for(int i = 'a'; i <= 'z'; i++)
		if(ile[i] != 0){
			ile[i]--;
			return;
		}
}

int main(){
    get_input();
    for(int i = 1; i <= s.size(); i++){
	    if(pal()){
		    cout << (i % 2 ? "First" : "Second") << endl;
		    return 0;
	    }
	    usun();
    }
}
