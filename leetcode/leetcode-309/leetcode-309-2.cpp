#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int n;
public:
    int solve(vector<int>& prices, int i, int to_buy, vector<vector<int>>& dp) {
        if(i >= n) return 0; // base case

        if(dp[i][to_buy] != INT_MIN) return dp[i][to_buy];

        int curr_price = prices[i];
        int ans;

        if(to_buy == 1) { 

            int buy_curr = solve(prices, i+1, 0, dp) - curr_price; // buy on current price
            int buy_next = solve(prices, i+1, 1, dp); // leave current day

            ans = max(buy_curr, buy_next);

        } else {

            int sold_curr = solve(prices, i+2, 1, dp) + curr_price; // sell on current price
            int sold_next = solve(prices, i+1, 0, dp); // sell on next day's price

            ans = max(sold_curr, sold_next);
        }

        return dp[i][to_buy] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN)); 

        return solve(prices, 0, 1, dp);
    }
};