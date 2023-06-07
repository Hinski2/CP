#include<bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int>lps;
vector<int>kandydat;

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s;
	n = s.size();
	s = '#' + s;

	lps.resize(n + 1);
}

void make_lps(){
	int l = 0;
	for(int i = 2; i <= n; i++){
		while(s[i] != s[l + 1] && l > 0) l = lps[l];
	    if(s[i] == s[l + 1]) l++;
		lps[i] = l;
	}

    while(l){
        if(l * 2 <= n) kandydat.push_back(l);
        l = lps[l];
    }
}

bool kmp(int m){
    int l = 0;
    for(int i = 1; i <= n; i++){
        while(s[i] != s[l + 1] && l) l = lps[l];
        if(s[i] == s[l + 1]) l++;
        if(l == 0) return 0;
        if(l == m) l = lps[l];
    }
    return 1;
}

int sprawdzenie(){
    kandydat.push_back(0);

    for(int i = kandydat.size() - 2; i >= 0; i--)
        if(kandydat[i] > kandydat[i + 1] * 2)
            if(kmp(kandydat[i])) return kandydat[i];
    
    return n;
}

int main(){
	wczytaj();
	make_lps();
	cout << sprawdzenie() << '\n';
}
