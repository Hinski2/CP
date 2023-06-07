#include <bits/stdc++.h>
using namespace std;

int n;
int Max, Min;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	Max = n - 1;

	int i = 1;
	while(n % i == 0) i++;

	Min = i;

	cout << Min << ' ' << Max << '\n';
}