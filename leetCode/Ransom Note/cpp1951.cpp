#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> ran, mag;
            for(auto u: ransomNote)
                ran[u]++;
            for(auto u: magazine)
                mag[u]++;

            for(auto [k, v]: ran) {
                if(v > mag[k]) return 0;
            }


            return 1;
        }
    };