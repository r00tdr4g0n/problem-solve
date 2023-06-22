#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)
            return 0;
        int *buy= new int[n];
        int *sell = new int[n];
        int *cooldown = new int[n];
        
        //no choice on day 0
        buy[0] = -prices[0];
        for(int i=1;i<n;i++)
        {
            buy[i] = max(buy[i-1], cooldown[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
        }

        return max(sell[n-1],cooldown[n-1]);
    }
};

class Solution2 {
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

class Solution3 {
public:
    int maxProfit(vector<int>& p) 
    {
        if (p.size() < 2)
            return 0;
        int i, sz = p.size();
        int ret = 0;
        vector<int> buy(sz, 0);
        vector<int> sell(sz, 0);
        buy[0] = -p[0];
        for (i = 1; i < sz; ++i)
        {
            sell[i] = max(buy[i - 1] + p[i], sell[i - 1] - p[i - 1] + p[i]);
            if (ret < sell[i]) //record the max sell[i]
                ret = sell[i];
            if (1 == i)
                buy[i] = buy[0] + p[0] - p[1];
            else
                buy[i] = max(sell[i - 2] - p[i], buy[i - 1] + p[i - 1] - p[i]);
        }
        return ret;
    }
};

class Solution4 {
public:

    int f(int i,vector<int>&prices,int signal,vector<vector<int>>&dp){
        if(i >= prices.size())
            return 0;

        if(dp[i][signal] != -1) 
            return dp[i][signal];
        
        if(signal == 1){
            return dp[i][signal] = max(-prices[i] + f(i+1,prices,0,dp), f(i+1,prices,1,dp));
        }
        else{
            return dp[i][signal] = max(prices[i] + f(i+2,prices,1,dp), f(i+1,prices,0,dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans = f(0,prices,1,dp);
        // for(auto it : dp){
        //     cout << it << " ";
        // }
        // cout << endl;
        return ans;
    }
};

int main()
{
vector<int> v = {1,2,3,0,2};

	Solution s;
    s.maxProfit(v);

    return 0;
}