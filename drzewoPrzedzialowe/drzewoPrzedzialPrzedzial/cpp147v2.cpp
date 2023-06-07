#include<bits/stdc++.h> 	//drzewo dodaj na przedziale, odczytaj sume 
using namespace std;

const int base = 1 << 17; 	//większe od 1e5

int drzewo[base << 1], lazy[base << 1];
int p, k, val; 	//zapytanie [p, k]

//po wykonaniu tej funkcji synowie mają mieć aktualną sytuację po tym co się zdażyło wcześniej
void push(int v, int l, int r, int len){ //przekazuje informatcje do synów
	lazy[l] += lazy[v];
	lazy[r] += lazy[v];

	drzewo[l] += len * lazy[v];
	drzewo[r] += len * lazy[v];

	lazy[v] = 0;
}

void update(int v, int a, int b){ 		//wywołanie update(1, 0, base - 1)
	if(k < a || p > b)					//nie pokrywamy sie
		return;
	else if(p <= a && b <= k){ 			//zawieramy sie w pełni
		drzewo[v] += (b - a + 1) * val;
		lazy[v] += val;
	}
	else{								//czesciowo pokrywamy sie 
		int l = v << 1;
		int r = (v << 1) + 1;
		int mid = (a + b) / 2;

		push(v, l, r, (b - a + 1) / 2);
		update(l, a, mid);
		update(r, mid + 1, b);

		drzewo[v] = drzewo[l] + drzewo[r];
	}
}

int querry(int v, int a, int b){
	if(k < a || p > b)					//nie pokrywamy sie
		return 0;						//zwrace element neutralny
	else if(p <= a && b <= k){ 			//zawieramy sie w pełni
		return drzewo[v];
	}
	else{								//czesciowo pokrywamy sie 
		int l = v << 1;
		int r = (v << 1) + 1;
		int mid = (a + b) / 2;

		push(v, l, r, (b - a + 1) / 2);
		return querry(l, a, mid) + querry(r, mid + 1, b);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	string operacja;
	cin >> q;

	while(q--){
		cin >> operacja;
		if(operacja == "update"){
			cin >> p >> k >> val; 	//początek przedziału, koniec przedziału, val
			update(1, 0, base - 1); // zawsze są te same parametry tu
		}
		else if(operacja == "querry"){
			cin >> p >> k; 			//początek przedziału, koniec przedziału
			cout << querry(1, 0, base - 1) << '\n'; // zawsze są te same parametry tu 
		}
		else{
			cout << "XD\n";
		}
	}
}
