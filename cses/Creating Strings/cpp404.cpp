#include<bits/stdc++.h>
using namespace std;

int n, occ[130], fact[10];
string str;

void print(){
    for(auto u: str)
        cout << u;
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fact[1] = fact[0] = 1;
    for(int i = 2; i < 10; i++)
        fact[i] = fact[i - 1] * i;

    cin >> str;
    n = str.size();

    for(int i = 0; i < n; i++)
        occ[str[i]]++;

    int div = 1;
    for(int i = 'a'; i <= 'z'; i++)
        div *= fact[occ[i]];

    //print answear 
    cout << fact[n] / div << '\n';

    //make all permutations
    sort(str.begin(), str.end());

    do{
        print();   
    } while(next_permutation(str.begin(), str.end()));
}
