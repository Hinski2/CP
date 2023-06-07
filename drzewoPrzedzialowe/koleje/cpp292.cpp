#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 17;
int tree[base << 1], lazy[base << 1];

int n, m, q;
int start, koniec, x; //[p, k] zapytanie

inline void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> q;
}

inline void push(int v, int lewy_syn, int prawy_syn){
	lazy[lewy_syn] += lazy[v];
	lazy[prawy_syn] += lazy[v];

	tree[lewy_syn] += lazy[v];
	tree[prawy_syn] += lazy[v];

	lazy[v] = 0;
}

int querry(int v, int l, int r){
	if(koniec < l || r < start)
		return 0;
	else if(start <= l && r <= koniec)
		return tree[v];
	else{
		int lewy_syn = v << 1;
		int prawy_syn = (v << 1) + 1;
		int mid = (l + r) / 2;

		push(v, lewy_syn, prawy_syn);
		return max(querry(lewy_syn, l, mid), querry(prawy_syn, mid + 1, r));
	}
	return 0;
}

void update(int v, int l, int r){
	if(koniec < l || r < start)
		return;
	else if(start <= l && r <= koniec){
		tree[v] += x;
		lazy[v] += x;
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

int main(){
	wczytaj();
	while(q--){
		cin >> start >> koniec >> x;
        start++;
		if(querry(1, 0, base - 1) + x <= m){
			cout << "T\n";
			update(1, 0, base - 1);
		}
		else
			cout << "N\n";
    }

        //sprawdzenie
    //     char c;
    //     cin >> c;
    //     if(c == 'Q'){
    //         cout << querry(1, 0, base - 1) << '\n';
    //     }
    //     else{
    //         update(1, 0, base - 1);
    //     }
    // }
}