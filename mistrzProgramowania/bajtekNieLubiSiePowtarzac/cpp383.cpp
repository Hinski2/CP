#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

string s;
vector<bool>chosen;
vector<char>permutation;

int Min = inf;
set<vector<char>> secik;

int wyznacz_dlugosc(){
    int ans = 0;
    for(int l = 1; l <= permutation.size(); l++)
        for(int i = 1; i <= permutation.size() - l; i++)
            for(int k = 0; k < l; k++){
                if(permutation[k] != permutation[k + i]) break;
                if(k + 1 == l) ans = l;
            }
    
    return ans;
}

void make_perm(){
    if(permutation.size() == s.size()){
       int dlugosc = wyznacz_dlugosc(); 

       if(dlugosc < Min){
        secik.clear();
        secik.insert(permutation);

        Min = dlugosc;
       }
       else if(dlugosc == Min){
        secik.insert(permutation);
       }
    }
    else{
        for(int i = 0; i < s.size(); i++){
            if(chosen[i]) continue;
            chosen[i] = true;

            permutation.push_back(s[i]);
            make_perm();

            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s;
    chosen.resize(s.size());

    make_perm();
    for(auto u: *secik.begin())
        cout << u;
        
    cout << '\n';
}
