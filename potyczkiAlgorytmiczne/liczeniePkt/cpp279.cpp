#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, groupSize, ans = 0;
    char c;

	scanf("%d", &n);
    scanf("%c", &c);

	groupSize = n / 10;
	for(int i = 1; i <= 10; i++){
		bool dodaj = true;

		for(int i = 1; i <= groupSize; i++){
			scanf("%c", &c);
			if(c != 'T') dodaj = false;
		}

		if(dodaj) ans++;
	}

	printf("%d\n", ans);
}