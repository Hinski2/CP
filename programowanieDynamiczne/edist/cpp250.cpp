//zadanie edist 
//nazwa na spoj: hinski2
//link do wysłanego zadania edist na spoju: https://www.spoj.com/status/EDIST,hinski2/

#include <bits/stdc++.h>
using namespace std;

string a, b;

void wczytaj(){
    cin >> a >> b;
}

void policz(){
	int arr[a.size() + 1][b.size() + 1];

	for(int i = 0; i <= a.size(); i++)
		for(int j = 0; j <= b.size(); j++){
			if(i == 0) arr[i][j] = j;
			else if(j == 0) arr[i][j] = i;

			else if(a[i - 1] == b[j - 1]) arr[i][j] = arr[i - 1][j - 1];
			else arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;			
		}

	cout << arr[a.size()][b.size()] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
    cin >> q;

	while(q--){
		wczytaj();
		policz();
	}
}