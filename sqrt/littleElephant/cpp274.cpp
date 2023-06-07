//nick na codeforces: Hinski2
//link do profilu: https://codeforces.com/profile/Hinski2
//link do zgłoszenia: https://codeforces.com/contest/220/submission/184649961

#include<bits/stdc++.h>
using namespace std;

const int mak = 1e5;

int n, m, itr = 1;

vector<int>idx;
vector<int>idxToNumb;
vector<int>numb;
vector<int>occ;
vector<vector<int>>suma;


void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	numb.resize(n + 1);
    occ.resize(n + 1);
    idx.resize(n + 1);

	for(int i = 1; i <= n; i++){
		cin >> numb[i];
        if(numb[i] <= mak) occ[numb[i]]++;
    }
}

void zindeksuj(){
    idxToNumb.push_back(0);
    for(int i = 1; i <= n; i++)
        if(occ[i] >= i){
            idx[i] = itr++;
            idxToNumb.push_back(i);
        }
}

void zsumuj(){
    suma.resize(n + 1);

    suma[0].resize(itr);
    for(int i = 1; i <= n; i++){
        suma[i].resize(itr);
        suma[i] = suma[i - 1];

        if(numb[i] <= mak && idx[numb[i]]) suma[i][idx[numb[i]]]++;
    }
}

int policz(int l, int r){
    int ans = 0;

    for(int i = 0; i < itr; i++)
        if(suma[r][i] - suma[l - 1][i] == idxToNumb[i]) ans++;

    return ans - 1;
}

int main(){
	wczytaj();
    zindeksuj();
    zsumuj();

	while(m--){
		int l, r;
        cin >> l >> r;
		if(l == r){
			if(numb[l] == 1) cout << "1\n";
			else cout << "0\n";
			continue;
		}	
		cout << policz(l, r) << '\n';
	}
}

