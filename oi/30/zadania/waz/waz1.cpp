#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int mak = 2015;

int m, n, p;
int pole[mak][mak];
int snake[mak][mak];

int ruch;
vector<pair<int, int>>co;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> m >> p >> n;

	//ustawianie planszy
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++){
			pole[i][j] = -1;
			snake[i][j] = -1;
		}

	for(int i = 1; i <= p; i++){
		int x, y, owoc;
		cin >> x >> y >> owoc;

		pole[x][y] = owoc;
	}
}

void z_owocem(int x, int y){
	co.push_back({x, y});
	snake[x][y] = pole[x][y];

	pole[x][y] = -1;
}

void bez_owoca(int x, int y){
    //zmiana koloru
    snake[x][y] = snake[co.back().fi][co.back().se];
	for(int i = co.size() - 1; i > 0; i--)
        snake[co[i].fi][co[i].se] = snake[co[i - 1].fi][co[i - 1].se];
    snake[co.front().fi][co.front().se] = -1;

    //zmiana koordynacji
    for(int i = 0; i < co.size() - 1; i++)
        co[i] = co[i + 1];
    co.back() = {x, y};
}


int main(){
	wczytaj();

	co.push_back({1, 1});
	snake[1][1] = 0;

	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		
		//zapytanie	
		if(c == 'Z'){
			int x, y;
			cin >> x >> y;

			cout << snake[x][y] << '\n';
		}	

		//ruch
		else{
			pair<int, int>wektor;
			if(c == 'G') wektor = {-1, 0};
			else if(c == 'D') wektor = {1, 0};
			else if(c == 'L') wektor = {0, -1};
			else wektor = {0, 1};

			int x = co.back().fi + wektor.fi;
			int y = co.back().se + wektor.se;

			if(pole[x][y] != -1) z_owocem(x, y);
			else bez_owoca(x, y);
		}
	}
}
