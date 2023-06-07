#include <bits/stdc++.h>
using namespace std;

void granica(){
	for(int i = 0; i < 11; i++)
		cout << '-';
	cout << '\n';
}

void puste(int opt){
	cout << "   ";

	if(opt == 0) cout << '\n';
	else cout << '|';
}

void znak(int opt, char c){
	cout << ' ' << c << ' ';

	if(opt == 0) cout << '\n';
	else cout << '|';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	puste(1); puste(1); puste(0);
	granica();
	puste(1); znak(1, 'o'); puste(0);
	granica();
	znak(1, 'o'); puste(1); znak(0, 'x');
}