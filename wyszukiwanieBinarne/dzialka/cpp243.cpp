#include <bits/stdc++.h>
using namespace std;

const int mak = 2005;

int n, ans;
int odl_ostatniego;
int from_top[mak];

void liczenie(){
    bool deleted = false;
	stack<pair<int, int>>stos;

	for(int i = 1; i <= n + 1; i++){
		if(from_top[i - 1] > from_top[i] && !stos.empty()){
            while(!stos.empty()){
				if(stos.top().first > from_top[i]){
					ans = max(ans, stos.top().first * (i - stos.top().second));
		            odl_ostatniego = stos.top().second;
					stos.pop();
				}
				else if(stos.top().first <= from_top[i]) break;
			}

            deleted = true;
        }

        if(deleted){
            stos.push({from_top[i], odl_ostatniego});
            deleted = false;
        }
        
        stos.push({from_top[i], i});
	}
}

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int l;
			cin >> l;

			if(!l) from_top[j] = from_top[j] + 1;
            if(l) from_top[j] = 0;
		}

		liczenie();
	}
	cout << ans << "\n";
}

int main(){
	wczytaj();
}
