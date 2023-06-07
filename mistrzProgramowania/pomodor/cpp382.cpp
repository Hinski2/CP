#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int mak = 1e5 + 5;
const int inf = 1e9 + 7;

int n, q;
int trie[mak][26];
bool koniec[mak];
pair<int, int>nearest[mak];

int next_nr = 1;
int sajz;
string s;


void add_world(int v, int idxs){
    if(idxs == s.size()){
        koniec[v] = true;
        return;
    }

	if(trie[v][s[idxs] - 'a'])
		add_world(trie[v][s[idxs] - 'a'], idxs + 1);
	else{
		trie[v][s[idxs] - 'a'] = next_nr++;
		add_world(trie[v][s[idxs] - 'a'], idxs + 1);
	}
}

void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		add_world(0, 0);
	}
}

void wyznacz_koniec(int v){
	for(int i = 0; i < 26; i++){
		if(trie[v][i]) wyznacz_koniec(trie[v][i]);
	}

	if(koniec[v]){
		nearest[v] = {v, 0};
		return;
	}

	nearest[v].se = inf;
	for(int i = 0; i < 26; i++)
			if(trie[v][i] && nearest[v].se == inf)
				nearest[v] = {i, nearest[trie[v][i]].se + 1};
}

void find_s(int v, int idxs){
	if(nearest[v].se == inf){
		s = "Pomidor";
		return;
	}

	if(idxs < sajz && trie[v][s[idxs] - 'a']){
		find_s(trie[v][s[idxs] - 'a'], idxs + 1);
	}
    else if(idxs < sajz && !trie[v][s[idxs] - 'a']){
		s = "Pomidor";
		return;
	}
	else{
		if(nearest[v].se == 0) return;
		else{
			s += (char)(nearest[v].fi + 'a');
			find_s(trie[v][nearest[v].fi], idxs + 1);
		}
	}
}

int main(){
	wczytaj();
	wyznacz_koniec(0);

	cin >> q;
	while(q--){
		cin >> s;
		sajz = s.size();

		find_s(0, 0);
		cout << s << '\n';
	}
}

