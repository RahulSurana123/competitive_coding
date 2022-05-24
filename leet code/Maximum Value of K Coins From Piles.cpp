

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith 
pile from top to bottom, and a positive integer k, 
return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> dp;
    int ans;
    int df(int i, vector<vector<int>>& piles,int k){
        // if(k == 0){ 
        //     ans= max(ans,s); 
        //     return s; 
        // }
        if(i >= piles.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int a = 0;
        a = max(a,df(i+1,piles,k));
        ;
        int sum = 0;
        // cout << i << " " << k << " " <<a << "\n";
        for(int j = 0; j < piles[i].size(); j++){
            sum += piles[i][j];
            if(k-1-j >= 0)
            a = max(df(i+1,piles,k-1-j)+sum,a);
            ;
        }
        return dp[i][k] = a;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp.resize(piles.size(),vector<int>(k+1,-1));
        // ans = 0;
        return df(0,piles,k);
        // return ans;
    }
};