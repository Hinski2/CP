#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int mak = 2015;

int m, p, n;
int pole[mak][mak];
int snake[mak][mak];

int ruch;
pair<int, int> glowa;
vector<int>color;

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

void z_owocem(){
    snake[glowa.fi][glowa.se] = ++ruch;
    color.push_back(pole[glowa.fi][glowa.se]);
    pole[glowa.fi][glowa.se] = -1;
}

void bez_owoca(){
    snake[glowa.fi][glowa.se] = ++ruch;
}

int main(){
	wczytaj();

	color.push_back(0);
	glowa = {1, 1};
	snake[1][1] = 0;

	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;

		//zapytanie
		if(c == 'Z'){
			int x, y;
			cin >> x >> y;

			if(snake[x][y] == -1) cout << "-1\n";
			else if(ruch - snake[x][y] >= color.size()) cout << "-1\n";
			else cout << color[color.size() - (ruch - snake[x][y] + 1)] << '\n';
		}

		//ruch
		else{
			pair<int, int>wektor;
			if(c == 'G') wektor = {-1, 0};
			else if(c == 'D') wektor = {1, 0};
			else if(c == 'L') wektor = {0, -1};
			else wektor = {0, 1};

			glowa.fi += wektor.fi;
			glowa.se += wektor.se;

            if(pole[glowa.fi][glowa.se] != -1) z_owocem();
            else bez_owoca();
		}
	}
}
