#include <bits/stdc++.h>
using namespace std;

const int testcase_num = 40;

int main(){
    int t; cin >> t;
    ofstream out("a.out");
    for(int i = 0; i < testcase_num; i++){
        int n, k; cin >> n >> k;
        vector<int> v(n); for(auto &u: v) cin >> u;
        if(i + 1 == testcase_num){
            out << n << endl;
            for(auto u: v)
                out << u << ' ';
            out << endl;
        }
    }
    out.close();
}