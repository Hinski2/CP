#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll suma_dodatnie, suma_ujemne;
ll last_dodatnie, last_ujemne;

int main(){
	scanf("%d", &q);

	ll v;
	while(q--){
		scanf("%lld", &v);

		if(v > 0){
			last_dodatnie++;
		}
		else{
			swap(last_dodatnie, last_ujemne);
			last_ujemne++;
		}

		suma_dodatnie += last_dodatnie;
		suma_ujemne += last_ujemne;
	}

	printf("%lld %lld \n", suma_ujemne, suma_dodatnie);
}