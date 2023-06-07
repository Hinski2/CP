//nick na codeforces: Hinski2
//link do profulu: https://codeforces.com/profile/Hinski2
//link do zgłoszenia: https://codeforces.com/submissions/Hinski2

#include<bits/stdc++.h>
using namespace std;

int n;
int matrix[16][16];
vector<vector<int>>legitne(17);

void wyznacz_legitne(){
	for(int i = 1; i <= 16; i++)
		for(int j = 0; j < (1 << i); j++)
			if((j & (j << 1)) == 0) legitne[i].push_back(j);
}

void wczytaj(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> matrix[i][j];
}

int dodaj(int wiersz, int mask){
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(mask & (1 << i)) ans += matrix[wiersz][i];

	return ans;
}

int policz(){
    int prev = 0, next = 1;
	vector<vector<pair<int, int>>>ans(2);
	ans[0].push_back({0, 0});

	for(int i = 0; i < n; i++){
		for(auto w: legitne[n]){
            int maks = 0;
			for(auto u: ans[prev])
				if((u.first & ((w << 1) | w | (w >> 1))) == 0)
                    maks = max(maks, u.second + dodaj(i, w));

			ans[next].push_back({w, maks});
        }
        
        ans[prev].clear();
        prev = (prev + 1) % 2;
        next = (next + 1) % 2;
    }

	int odpowiedz = 0;
	for(auto u: ans[prev])
		odpowiedz = max(odpowiedz, u.second);

	return odpowiedz;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	wyznacz_legitne();

	while(t--){
		wczytaj();
		cout << policz() << '\n';
	}
}
