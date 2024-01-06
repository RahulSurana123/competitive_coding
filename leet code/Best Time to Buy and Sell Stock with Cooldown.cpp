

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) 
with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


    ***********************************************************
*/



#include <bits/stdc++.h>


class Solution {
public:
    
    vector<vector<int>> dp;

    int df(int i, bool b,vector<int>& prices){
        if(i >= prices.size()) return 0;
        if(dp[b][i] != -1) return dp[b][i];
        if(b){
            return dp[b][i] = max(-prices[i] + df(i+1,false,prices), 0 + df(i+1,true,prices));
        }
        else{
            return  dp[b][i] = max(prices[i] + df(i+2,true,prices), 0 + df(i+1,false,prices));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(2,vector<int>(n+2,0));
        // int ans = df(0,1,prices);
        // int dp[3][n+2];
        // memset(dp,0,sizeof(dp));
        // int ans = 0;
        // for(int i = 1; i < n+1; i++){
        //     // dp[0][i] = max();
        // }
        // for(int i = 0; i < 3; i++){
        for(int j = n-1; j >= 0; j--){
            dp[1][j] = max(dp[1][j+1] +0, dp[0][j+1]-prices[j] );
            dp[0][j] = max(dp[0][j+1] +0, dp[1][j+2]+prices[j] ); 
            // cout << dp[i][j]<<" ";
        }
            // cout << "\n";
        // }
        return dp[1][0];
    }
};