#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string my_sort(string &s) {
        vector<int> let('z' - 'a' + 1);
        for(auto u: s)
            let[u - 'a']++;
        
        int let_idx = 0;
        string s_out;
        s_out.resize(s.size());

        for(int s_idx = 0; s_idx < s.size(); s_idx++) {
            while(let[let_idx] == 0) {
                let_idx++;
            }

            s_out[s_idx] = 'a' + let_idx;
            let[let_idx]--;
        }

        return s_out;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) { 
        unordered_map<string, vector<string>> um;
        um.reserve(strs.size() + 1);

        for(int i = 0; i < strs.size(); i++) {
            um[my_sort(strs[i])].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto& [k, v]: um) {
            ans.push_back(v);
        }

        return ans;
    }
};
