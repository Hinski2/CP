#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int Size = 7;

int ans;
vector<pair<int, int>>vec[200];
bool accesable[9][9];
string str;

void place(int no, int a, int b){
    //return cases
    if(accesable[a][b + 1] && accesable[a][b - 1] && !accesable[a - 1][b] && !accesable[a + 1][b]) return;
    if(!accesable[a][b + 1] && !accesable[a][b - 1] && accesable[a - 1][b] && accesable[a + 1][b]) return;

	if(no == Size * Size - 1){
        if(a == Size && b == 1) ans++;
		return;
	}

    if(a == Size && b == 1) return;

	accesable[a][b] = 0;
	for(auto u: vec[str[no]])
		if(accesable[a + u.fi][b + u.se])
			place(no + 1, a + u.fi, b + u.se);

	accesable[a][b] = 1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	//set vectors
	vec['D'].push_back({1, 0});
	vec['U'].push_back({-1, 0});
	vec['L'].push_back({0, -1});
	vec['R'].push_back({0, 1});

	vec['?'].push_back({-1, 0});
	vec['?'].push_back({1, 0});
	vec['?'].push_back({0, -1});
	vec['?'].push_back({0, 1});

	cin >> str;
	for(int i = 1; i <= Size; i++)
		for(int j = 1; j <= Size; j++)
			accesable[i][j] = 1;

	place(0, 1, 1); //no, i, j
	cout << ans << '\n';
}






