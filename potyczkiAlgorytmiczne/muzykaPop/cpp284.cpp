#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>liczba;

int wyznacz(int l){
	int ans = 0;
	while(l){
		if(l % 2) ans++;
		l /= 2;
	}

	return ans;
}

int main(){
	scanf("%d", &n);

	int idx = 1;
	while(n){
		int waga = wyznacz(idx);

		while(n - waga < 0){
			n += wyznacz(liczba.back());
			liczba.pop_back();
		}

		n -= waga;
		liczba.push_back(idx++);
	}

	printf("%d\n", liczba.size());
	for(int i = liczba.size() - 1; i >= 0; i--)
		printf("%d ", liczba[i]);
	printf("\n");
}

