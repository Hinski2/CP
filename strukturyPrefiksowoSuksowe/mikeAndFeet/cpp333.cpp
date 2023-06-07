#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>arr, l, r, ans;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	arr.resize(n + 2);
	l.resize(n + 1);
	r.resize(n + 1);
	ans.resize(n + 2);

	for(int i = 1; i <= n; i++)
		cin >> arr[i];
}

void compute_l(){
	stack<int>stos;

	for(int i = 1; i <= n; i++){
		while(!stos.empty() && arr[stos.top()] >= arr[i])
			stos.pop();

		if(stos.empty())
			l[i] = 0;
		else
			l[i] = stos.top();

		stos.push(i);
	}
}

void compute_r(){
	stack<int>stos;

	for(int i = n; i > 0; i--){
		while(!stos.empty() && arr[stos.top()] >= arr[i])
			stos.pop();

		if(stos.empty())
			r[i] = n + 1;
		else
			r[i] = stos.top();

		stos.push(i);
	}
}

void pre_ustaw(){
	for(int i = 1; i <= n; i++){
        int m = r[i] - l[i] - 1;
		ans[m] = max(ans[m], arr[i]);
	}
}

void dokoncz_ustawianie(){
	for(int i = n; i > 0; i--)
		ans[i] = max(ans[i], ans[i + 1]);
}

void wypisz(){
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	//wczytanie
	wczytaj();

	//preprocesing
	compute_l();
	compute_r();

	//liczenie
	pre_ustaw();
	dokoncz_ustawianie();

	//wypisanie
	wypisz();
}