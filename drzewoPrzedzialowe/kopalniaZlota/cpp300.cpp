#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define start true
#define koniec false

typedef pair<bool, pair<int, int>> para;

const int bonus = 30000;
const int base = 1 << 16;

int tree[base << 1], lazy[base << 1];

int p_start, p_koniec, add;
int s, w, n;

vector<para>punkty;
void wczytaj(){
    int a, b;
	scanf("%d%d%d", &s, &w, &n);
	for(int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);

        punkty.push_back({start, {a + bonus, b + bonus}});
        punkty.push_back({koniec, {a + bonus, b + w + 1 + bonus}});
    }
}

bool cmp(const para &a, const para &b){
    if(a.se.se != b.se.se) return a.se.se < b.se.se;
	else if(a.fi == koniec && b.fi == koniec) return a.se.fi < b.se.fi;
    return a.fi == koniec;
}

void push(int v, int lewy_syn, int prawy_syn){
	lazy[lewy_syn] += lazy[v];
	lazy[prawy_syn] += lazy[v];
	tree[lewy_syn] += lazy[v];
	tree[prawy_syn] += lazy[v];

	lazy[v] = 0;
}

void update(int v, int l, int r){
	if(p_koniec < l || r < p_start) 
		return;
	else if(p_start <= l && r <= p_koniec){
		lazy[v] += add;
		tree[v] += add;
	}
	else{
		int lewy_syn = v << 1;
		int prawy_syn = (v << 1) + 1;
		int mid = (l + r) / 2;

		push(v, lewy_syn, prawy_syn);
		update(lewy_syn, l, mid);
		update(prawy_syn, mid + 1, r);

		tree[v] = max(tree[lewy_syn], tree[prawy_syn]);
	}
}


void policz(){
	int ans = 0;
	for(para u: punkty){
		if(u.fi == start){
			p_start = u.se.fi;
			p_koniec = u.se.fi + s;
			add = 1;

			update(1, 0, base - 1);
		    ans = max(ans, tree[1]);
		}
		else{
			p_start = u.se.fi;
			p_koniec = u.se.fi + s;
			add = -1;

			update(1, 0, base - 1);
		}
	}

	printf("%d", ans);
}

int main(){
	wczytaj();
	sort(punkty.begin(), punkty.end(), cmp);
	policz();
}
