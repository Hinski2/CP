#include <bits/stdc++.h>
using namespace std;

int n;
int stopien_jeden;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == 1) stopien_jeden++;
        if(stopien_jeden == 2) break;
    }
}

int main(){
    wczytaj();
    
    cout << 2 - stopien_jeden << "\n";
    cout <<"2\n1 2\n";
}



