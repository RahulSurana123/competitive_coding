

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        vector<vector<int>> m(2,vector<int>(n));
        m[0][0] = prices[0];
        m[1][n-1] = prices[n-1];
        for(int i = 1; i < n; i++){
            m[0][i] = min(m[0][i-1],prices[i]);
        }
        for(int i = n-2; i >= 0; i--){
            m[1][i] = max(m[1][i+1],prices[i]);
        }
        for(int i = n-1; i >= 0; i--){
            ans = max(ans,m[1][i]-m[0][i]);
        }
        return ans;
    }
};