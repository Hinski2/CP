#include<bits/stdc++.h>
using namespace std;

int ile_w_lini, do_narysowania;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> ile_w_lini >> do_narysowania;
	while(do_narysowania){
		for(int i = 1; i <= ile_w_lini && do_narysowania; i++){
			cout << "$ ";
			do_narysowania--;
		}
		cout << '\n';
		ile_w_lini += 2;
	}
}