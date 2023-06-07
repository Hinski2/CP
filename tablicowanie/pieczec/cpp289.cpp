#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int mak = 1015;

int q;
int x, y, a, b;

char grid[mak][mak];
char stempel[mak];
vector<pair<int, int>>v;

void wczytaj(){
	scanf("%d%d%d%d", &x, &y, &a, &b);
	for(int i = 0; i < x; i++){
        scanf("%s", &grid[i]);
	}

    pair<int, int> start = {0, 0};
	for(int i = 0; i < a; i++){
        scanf("%s", &stempel);
		for(int j = 0; j < b; j++){
			if(stempel[j] == 'x'){
                if(v.size())
                    v.push_back({i - start.fi, j - start.se});
                else{
                    start = {i, j};
                    v.push_back({0, 0});
                }
			}
		}
    }
}

bool postawiony_poprawnie(int i, int j){
    int pos_i, pos_j;
	for(auto u: v){
		pos_i = i + u.fi;
		pos_j = j + u.se;

		if(pos_i >= x || pos_i < 0 || pos_j >= y || pos_j < 0 || grid[pos_i][pos_j] != 'x') return 0;
		else grid[pos_i][pos_j] = '.';
	}
	return 1;
}

bool poprawny(){
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
		    if(grid[i][j] == 'x' && !postawiony_poprawnie(i, j)) return 0;

	return 1;
}

int main(){
	scanf("%d", &q);
	while(q){
		wczytaj();

		if(poprawny()) printf("TAK\n");
		else printf("NIE\n");

        v.clear();
        q--;
	}
}
