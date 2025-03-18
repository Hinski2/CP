#include <bits/stdc++.h>
using namespace std;

const int testcase_num = 38;

int main(){
    int t; cin >> t;
    ofstream out("a.out");
    for(int i = 0; i < testcase_num; i++){
        string n; cin >> n;
        if(i + 1 == testcase_num){
            out << n << endl;
        }
    }
    out.close();
}