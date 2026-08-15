#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int last_price = prices[0], ans = 0;
        for(auto price: prices) {
            if(price > last_price) {
                ans += price - last_price;
                last_price = price;
            } else {
                last_price = price;
            }
        }

        return ans;
    }
};

int main(){
    vector<int> prices = {8, 3, 6, 2, 8, 8, 8, 4, 2, 0, 7, 2, 9, 4, 9};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
}