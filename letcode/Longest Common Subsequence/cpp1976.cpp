#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        text1 = ' ' + text1, text2 = ' ' + text2;

        vector<vector<int>> lcs(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i] == text2[j]) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }        

        return lcs[n][m];
    }
};