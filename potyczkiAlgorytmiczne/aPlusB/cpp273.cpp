#include<bits/stdc++.h>
using namespace std;

string a, b;
vector<int>ans;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> a >> b;
}

void dodaj(){
	int idxa = a.size() - 1, idxb = b.size() - 1;
	bool extra = false, konieca = false, koniecb = false;

	while(!konieca || !koniecb){
		int sum = (a[idxa--] - '0') + (b[idxb--] - '0');

        if(idxa == -1){
            idxa = 0;
            a[0] = '0';
            konieca = true;
        }
        if(idxb == -1){
            idxb = 0;
            b[0] = '0';
            koniecb = true;
        }

		if(extra){
			sum++;
			extra = 0;
		}
		if(sum > 9){
			sum -= 10;
			extra = 1;
		}

		ans.push_back(sum);
	}

	if(extra) ans.push_back(1);
}

void wypisz(){
	for(int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i];
	}
	cout << '\n';
}	

int main(){
	wczytaj();
	dodaj();
	wypisz();
}