#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mak = 1015;

int n, q;

int pole[mak][mak];
int romb[2 * mak][2 * mak];
ll pref[2 * mak][2 * mak];

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> pole[i][j];
}

void make_romb(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			romb[i + (j - 1)][j + (n - i)] = pole[i][j];
}

void make_sumy(){
	for(int i = 1; i < n * 2; i++)
		for(int j = 1; j < n * 2; j++)
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + romb[i][j];
}

void policz(){
	int x, y, r;
	cin >> x >> y >> r;

	int a = x + (y - 1);
	int b = y + (n - x);

	int aT = min(a + r, 2 * n - 1);
	int aL = max(a - (r + 1), 0);	
	int bT = min(b + r, 2 * n - 1);
	int bL = max(b - (r + 1), 0);	

	ll suma = pref[aT][bT] - pref[aT][bL] - pref[aL][bT] + pref[aL][bL];

	cout << suma << '\n';
}

int main(){
	wczytaj();
	make_romb();
	make_sumy();

	while(q--)
		policz();
}