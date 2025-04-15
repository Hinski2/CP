#include<bits/stdc++.h>
using namespace std;

struct my_stack{
    int maks, no;
    list<int> l;
    set<int> s;

    my_stack(int k){
        maks = k;
        no = 0;
    }

    void add(int v){
        if(!s.count(v)){
            l.push_back(v);
            s.insert(v);
            no++;
        }

        if(no > maks)
            pop_front();
    }

    void pop_front(){
        int v = l.front(); l.pop_front();
        s.erase(v);
        no--;
    }

    void print(){
        cout << no << endl;
        while(!l.empty()){
            int v = l.back(); l.pop_back();
            cout << v << ' ';
        }
        cout << endl;
    }
};

int main(){
    // get input
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n); for(auto &u: v) cin >> u;

    // compute ans
    my_stack s(k);
    for(auto u: v){
        s.add(u);
    }

    s.print();
}