//nick na codeforces: Hinski2
//link do profilu: https://codeforces.com/profile/Hinski2
//link do zgłoszenia: https://codeforces.com/contest/13/submission/184714904

#include <bits/stdc++.h>
using namespace std;

int n, m, sqr, ile;
vector<int>liczba;
vector<int>ileDoNext, nextIdx;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	liczba.resize(n + 1);
	ileDoNext.resize(n + 1);
	nextIdx.resize(n + 1);

	for(int i = 1; i <= n; i++)
		cin >> liczba[i];
}

void preprocesing(){
	for(int i = n; i > 0; i--){
		int teraz = i / sqr;
		int nrPrze2 = (i + liczba[i]) / sqr;

		if(i + liczba[i] > n)
			ileDoNext[i] = 1;
		else if(teraz == nrPrze2){
			ileDoNext[i] = ileDoNext[i + liczba[i]] + 1;
			nextIdx[i] = nextIdx[i + liczba[i]];
		}
		else{
			ileDoNext[i] = 1;
			nextIdx[i] = i + liczba[i];
		}
	}
}

void oblicz(int idx){
	int ans = 0;

	while(nextIdx[idx] || ileDoNext[idx] != 1){
		if(nextIdx[idx]){
		    ans += ileDoNext[idx];
            idx = nextIdx[idx];
        }
        else{
            idx += liczba[idx];
            ans++;
        }
	}

	cout << idx << ' ' << ans + 1 << '\n';
}

void zamiana(int idx, int x){
	int teraz = idx / sqr;
	int last = teraz - 1;
	liczba[idx] = x;
	
	for(int i = idx; (i / sqr) > last; i--){
        if(i == 0) break;
        int skacze = (i + liczba[i]) / sqr;

	    if(i + liczba[i] > n){
		    ileDoNext[i] = 1;
		    nextIdx[i] = 0;
	    }
	    else if(skacze == teraz){
		    ileDoNext[i] = ileDoNext[i + liczba[i]] + 1;
            nextIdx[i] = nextIdx[i + liczba[i]];
	    }
	    else{
		    ileDoNext[i] = 1;
		    nextIdx[i] = i + liczba[i];
	    }
    }
}

int main(){
	wczytaj();

	sqr = sqrt(n);
	ile = (n + sqr - 1) / sqr;
	preprocesing();

	while(m--){
		bool opt;
		cin >> opt;

		if(!opt){
			int a, b;
			cin >> a >> b;
			zamiana(a, b);
		}
		else{
			int x;
			cin >> x;
			oblicz(x);
		}
	}
}



