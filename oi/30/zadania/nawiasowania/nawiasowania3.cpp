//Jakub Iliński płytkie nawiasowanie (przypuszczalna wzorcówka)
#include <bits/stdc++.h>
using namespace std;

int n, h;
int ans;

vector<bool> nawias;
vector<int> do_dolu;


void wczytaj(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> h;

    nawias.resize(n + 1);
    do_dolu.resize(n + 1);

    stack<int>stos;
    int dol = 0;

    stos.push(0);
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;

        if(c == '('){
            nawias[i] = 0;
            stos.push(i);
            dol = 0;
        }
        else{
            nawias[i] = 1;
            dol = do_dolu[stos.top()] + 1;
            stos.pop();
        }

        if(!stos.empty())
            do_dolu[stos.top()] = max(do_dolu[stos.top()], dol);
    }
}

void policz(){
    stack<int>stos;
    stos.push(0);

    for(int i = 1; i <= n; i++){
        if(nawias[i] == 0){
            if(stos.size() % 2 == 0 && stos.size() && do_dolu[i] + stos.top() + stos.size() > h){
                ans += 2;
                stos.push(stos.top() - 2);
            }
            else{
                stos.push(stos.top());
            }
        }
        else{
            stos.pop();
        }
    }
}

int main(){
	wczytaj();
    policz();
	cout << ans << '\n';
}