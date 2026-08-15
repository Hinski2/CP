#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;

        string n;
        for(auto u: s){
            if(u == ' ') {
                v.push_back(n);
                n = "";
            } else {
                n += u;
            }
        }

        if(n != "")
            v.push_back(n);

        unordered_map<string, char> um;
        unordered_set<char> us;

        if(v.size() != pattern.size()) return 0;
        for(int i = 0; i < v.size(); i++) {
            if(!um.contains(v[i])) {
                if(us.contains(pattern[i])) return 0;

                us.insert(pattern[i]);
                um[v[i]] = pattern[i];
            } else {
                if(um[v[i]] != pattern[i]) return 0;
            }
        }

        return 1;
    }
};