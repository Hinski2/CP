#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int start = 1;
const int koniec = 0;
const int mak = 1e6 + 15;

struct prawnik{
	int pozycja;
	int nr;
	bool status;
};

int n, k;
pair<int, int>przedzial[mak];
vector<prawnik>prawnicy;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> przedzial[i].fi >> przedzial[i].se;
		prawnicy.push_back({przedzial[i].fi, i, start});
		prawnicy.push_back({przedzial[i].se, i, koniec});
	}
}

//czy a ma stać przed b
bool cmp(const prawnik &a, const prawnik &b){
	return a.pozycja < b.pozycja;
}

void policz(){
	int L = 0, R = -1, r = 0;
	set<int>insajd, deleted;

	for(int l = 0; l < prawnicy.size(); l++){
		if(prawnicy[l].status == start && deleted.count(prawnicy[l].nr) == 0)
			insajd.insert(prawnicy[l].nr);

		while(r < prawnicy.size() && insajd.size() >= k){
			if(R - L < prawnicy[r].pozycja - prawnicy[l].pozycja){
				R = prawnicy[r].pozycja;
				L = prawnicy[l].pozycja;
			}
			if(prawnicy[r].status == koniec){
				deleted.insert(prawnicy[r].nr);
				if(insajd.count(prawnicy[r].nr))
					insajd.erase(prawnicy[r].nr);
			}
			r++;
		}
	}

	cout << R - L << '\n';
	for(int i = 0; i < n; i++)
		if(przedzial[i].fi <= L && R <= przedzial[i].se && k-- > 0)
			cout << i + 1 << ' ';
	cout << '\n';
}

int main(){
	wczytaj();
	sort(prawnicy.begin(), prawnicy.end(), cmp);
	policz();
}