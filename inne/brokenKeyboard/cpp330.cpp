#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<char>str(105);

		for(int i = 1; i <= n; i++)
			cin >> str[i];

		int sprawdz = 0;
		bool poprawny = true;
		for(int i = 1; i <= n; i++){
			if(sprawdz){
				if(str[i] != str[i + 1]) poprawny = false;
				i++;	
			}
			sprawdz ^= 1;
		}

		if(poprawny) cout << "YES\n";
		else cout << "NO\n";
	}
}