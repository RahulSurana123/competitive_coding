

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.



    ***********************************************************
*/



class Solution {
public:
    vector<vector<int>> dp;
    int df(int i, int amount,  vector<int>& coins){
        if(amount < 0 || i >= coins.size()) return 0;
        if(amount == 0) return 1;
        if(dp[i][amount] != -1) return dp[i][amount];
        int ans = df(i+1,amount,coins);
        ans += df(i,amount-coins[i],coins);
        return dp[i][amount] = ans;
    }

    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end(),greater<int>());
        return df(0,amount, coins);
    }
};