#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>Numbers;

void decompose(int numb){
    for(int i = n - 1; i >= 0; i--)
        cout << (numb & (1 << i)? 1 : 0);
    
    cout << '\n';
}

void solve(int x){
    int numb = 1 << x, sajz = (int)Numbers.size();

    for(int i = sajz - 1; i >= 0; i--)
        Numbers.push_back(Numbers[i] + numb);
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> n;
    Numbers.push_back(0);
    Numbers.push_back(1);

    for(int i = 1; i < n; i++)
        solve(i);
    
    for(auto u: Numbers)
        decompose(u);
}

