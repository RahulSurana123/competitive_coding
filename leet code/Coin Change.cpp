

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array coins representing coins of different denominations and 
an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    // vector<vector<int>> dp;
    
//     int df(int i, int a, vector<int>& c){
//         if(i == 0){
//             if(a%c[i] == 0){
//                 return a/c[i];
//             }
//             else return 1e9;
//         }
//         if(dp[i][a] != -1) return dp[i][a];
//         int ans = 1e9;
//         int nt = df(i-1,a,c);
//         if(a>=c[i]) ans = 1 + df(i,a-c[i],c);
        
//         return dp[i][a] = min(ans,nt);
//     }
    
    int coinChange(vector<int>& coins, int amount) {
        //
        //          **********************************
        //              Top Down Approach
        //          **********************************
        // dp.resize(coins.size()+1,vector<int>(amount+1,-1));
        // int ans = df(coins.size()-1,amount,coins);
        // return ans >= 1e9? -1 : ans;
   
        // dp.resize(coins.size()+1,vector<int>(amount+1,-1));
        vector<int> dp(amount+1,0);
        for(int i = 0; i <= amount; i++){
            //
            //      *******************************
            //          Bottom Up Approach
            //      *******************************
            //
            // if(i % coins[0] == 0) dp[0][i] = i/coins[0];
            // else dp[0][i] = 1e9;

            if(i % coins[0] == 0) dp[i] = i/coins[0];
            else dp[i] = 1e9;
        }
        
        
        for(int i = 1; i < coins.size(); i++){
            vector<int> temp(amount+1,0);
            for(int j = 0; j <= amount; j++){
                
                //
                //      *******************************
                //          Bottom Up Approach
                //      *******************************
                //
                // int nt = dp[i-1][j];
                // int ans = 1e9;
                // if(j>=coins[i]) ans = 1 + dp[i][j-coins[i]];  
                // dp[i][j] = min(nt,ans);
                
                int nt = dp[j];
                int ans = 1e9;
                if(j>=coins[i]) ans = 1 + temp[j-coins[i]];  
                temp[j] = min(nt,ans);
            }   
            dp = temp;
        }
        if(dp[amount] >= 1e9) return -1;
        return dp[amount];
        
    }
};