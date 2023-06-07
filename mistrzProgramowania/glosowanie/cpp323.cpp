#include<bits/stdc++.h>
using namespace std;

int a, b;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a >> b;

	if(a + b != 100)
		cout << "SKANDAL\n";
	else if(a == b)
		cout << "Remis\n";
	else if(a < b)
		cout << "Bajtek\n";
	else
		cout << "Bitek\n";
}