#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;

	ll suma = 0;
	for(int i = 1; i <= n; i++)
		suma += i;

	cout << suma << '\n';
}	
