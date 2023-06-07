#include <bits/stdc++.h>
using namespace std;

const int mak = 2015;

int n, m;
char pole[mak][mak];

void wczytaj(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", &pole[i]);
}

void bfs(int i, int j){
    if(i < 0 || i >= n - 1 || j < 0 || j >= m - 1) return; //koordynaty poza granicami

	int licznik = 0;
    pair<int, int> place;

	for(int x = 0; x < 2; x++)
		for(int y = 0; y < 2; y++)
			if(pole[i + x][j + y] == '*'){
	            licznik++;
	            place = {x + i, y + j};
	        }

	if(licznik == 1){
        pole[place.first][place.second] = '.';
        for(int x = -1; x < 1; x++)
            for(int y = -1; y < 1; y++)
                bfs(place.first + x, place.second + y);
    }

}

void liczenie(){
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < m - 1; j++)
			bfs(i, j);
}

void wypisanie(){
	for(int i = 0; i < n; i++)
			printf("%s\n", pole[i]);
}

int main(){
	wczytaj();
	liczenie();
	wypisanie();
}
