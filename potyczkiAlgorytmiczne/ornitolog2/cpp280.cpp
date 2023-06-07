#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n;
vector<int>liczby;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	liczby.resize(n);

	for(int i = 0; i < n; i++)
		cin >> liczby[i];
}

int policz1(){
	int ans = 0, ostatnia = -inf;
	int teraz_rosnie = true;

	for(auto u: liczby){
		if(teraz_rosnie){
			if(ostatnia >= u){
				ans++;
				ostatnia = inf;
			}
			else
				ostatnia = u;
		}
		else{
			if(ostatnia <= u){
				ans++;
				ostatnia = -inf;
			}
			else
				ostatnia = u;
		}

		teraz_rosnie = (teraz_rosnie + 1) % 2;
	}

	return ans;
}

int policz2(){
	int ans = 0, ostatnia = inf;
	int teraz_rosnie = false;

	for(auto u: liczby){
		if(teraz_rosnie){
			if(ostatnia >= u){
				ans++;
				ostatnia = inf;
			}
			else
				ostatnia = u;
		}
		else{
			if(ostatnia <= u){
				ans++;
				ostatnia = -inf;
			}
			else
				ostatnia = u;
		}
		
		teraz_rosnie = (teraz_rosnie + 1) % 2;
	}

	return ans;
}

int main(){
	wczytaj();	
	cout << min(policz1(), policz2()) << '\n';
}
