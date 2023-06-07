#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mak = (ll)1e17;

ll n, last = -1, lastCand, liczba, ans;
ll liczbaDigNumb, lastCandDingNumb, extraZero;

inline ll policz_cyfry(ll numb){
	ll wynik = 0;
	while(numb){
		wynik++;
		numb /= 10;
	}

	return wynik;
}

inline ll trim(ll numb, ll ile){
	if(!ile) return numb;
	while(ile--){
		numb /= 10;
	}

	return numb;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	while(n--){
		cin >> liczba;

		if(last < liczba){
			last = liczba;
		}
		else{
			lastCand = last + 1;
			liczbaDigNumb = policz_cyfry(liczba);
			lastCandDingNumb = policz_cyfry(lastCand);

			if(liczba != trim(lastCand, lastCandDingNumb - liczbaDigNumb)){
				lastCand = liczba * 10;
				while(lastCand < last){
					lastCand *= 10;
					if(lastCand > mak){
						extraZero++;
						lastCand /= 10;
						break;
					}
				}
			}
			
			last = lastCand;
			ans += policz_cyfry(lastCand) - policz_cyfry(liczba) + extraZero;
		}
	}

	cout << ans << '\n';
}
