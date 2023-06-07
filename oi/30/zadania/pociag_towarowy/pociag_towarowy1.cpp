//Jakub Ilińki zadania pociąg towarowy (brut)
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> older, younger;
vector<int> ans;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	older.resize(n + 1);
	younger.resize(m + 1);
	ans.resize(n + 1);

	for(int i = 1; i <= n; i++)
		cin >> older[i];

	for(int i = 1; i <= m; i++)
		cin >> younger[i];
}

bool liczenie(int i, int idx){
	if(idx > m){
		ans[i] = 1;
		return 1;
	}

    bool r = false;
	for(int j = i + 1; j <= n; j++)
		if(older[j] == younger[idx]){
			if(liczenie(j, idx + 1)){
                r = true;
                ans[j] = true;
            }
		}
    return r;
}

void policz(){
	for(int i = 1; i <= n; i++)
		if(older[i] == younger[1]){
			if(liczenie(i, 2)) ans[i] = true; 
		}
}

void wypisz(){
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main()
{
	wczytaj();
	policz();
	wypisz();
}