#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (const auto &u : v) {
    os << u << ' ';
  }
  return os;
}

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &u : v) {
    is >> u;
  }
  return is;
}

template <typename T> long long sum(const vector<T> &v) {
  long long s = 0;
  for (auto u : v)
    s += u;
  return s;
}

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define endl '\n'
#define alf 'z' + 1
#define yn (solve() ? YES : NO)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int mak = 2e5 + 7;

void solve() {
  	int n; cin >> n;
	vector<set<int>> loves(n + 1);
  	vector<int> fr(n + 1, 1), skipped;

	for(int i = 1; i <= n; i++){
		int k; cin >> k;

		bool matched = false;
		for(int j = 1; j <= k; j++){
			int cand; cin >> cand;
			loves[i].insert(cand);

			if(matched or !fr[cand]) continue;
			fr[cand] = false;
			matched = true;
		}

		if(!matched) skipped.pb(i);
	}

	vector<int> free_cand;
	for(int i = 1; i <= n; i++)
		if(fr[i]) free_cand.pb(i);


	for(auto princess: skipped){
		for(auto f: free_cand){
			if(!loves[princess].count(f)){
				cout << "IMPROVE" << endl;
				cout << princess << ' ' << f << endl;
				return;
			}
		}
	}

	cout << "OPTIMAL" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}
