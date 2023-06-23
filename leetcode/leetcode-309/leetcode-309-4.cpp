#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
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