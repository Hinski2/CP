#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ss, tt;
        for(auto u: s)
            ss[u]++;
        for(auto u: t)
            tt[u]++;

        for(auto [k, v]: ss) {
            if(v != tt[k]) return 0;
        }

        for(auto [k, v]: tt) {
            if(v != ss[k]) return 0;
        }

        return 1;
    }
};