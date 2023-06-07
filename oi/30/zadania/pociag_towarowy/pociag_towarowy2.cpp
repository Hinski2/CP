//Jakub Ilińki zadania pociąg towarowy (lepszy brut)
#include <bits/stdc++.h>
using namespace std;

int n, m, k;

vector<int> older, younger;
vector<int> najdalej;
vector<int> ans;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    older.resize(n + 1);
    younger.resize(m + 1);
    ans.resize(n + 1);

    najdalej.resize(m + 2);
    najdalej[m + 1] = n + 1;

    for(int i = 1; i <= n; i++)
        cin >> older[i];
    for(int i = 1; i <= m; i++)
        cin >> younger[i];
}

void ustaw(int idx, int i){
	if(idx > m) return;

	bool znaleziony = false;
	while(!znaleziony && i <= n){
		if(younger[idx] == older[i])
			znaleziony = true;
		else
			i++;
	}

	if(i <= n && znaleziony){
		najdalej[idx] = i;
		ustaw(idx + 1, i + 1);
	}
    else{
        najdalej[m + 1] = 0;
    }
}

void sprawdz(){
	for(int idx = m; idx > 0; idx--)
		for(int i = najdalej[idx]; i < najdalej[idx + 1]; i++)
			if(younger[idx] == older[i]){
				ans[i] = true;
				najdalej[idx] = i;
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
	ustaw(1, 1);
    if(najdalej[m + 1])
	    sprawdz();
	wypisz();
}