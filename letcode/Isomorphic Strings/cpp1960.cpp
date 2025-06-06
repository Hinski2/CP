#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return 0;
        unordered_map<char, char> trans;  
        unordered_set<char> used;

        for(int i = 0; i < s.size(); i++) {
            if(trans.count(s[i])) {
                if(trans[s[i]] != t[i]) return 0;
            } else {
                if(used.count(t[i])) return 0;
                trans[s[i]] = t[i];
                used.insert(t[i]);
            }
        }

        return 1;
    }
};