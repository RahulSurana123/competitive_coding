

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ps(2,vector<int>(n,0));
        ps[0][0] = 0;
        ps[1][n-1] = 0;
        int ml = prices[0];
        for(int i = 1; i < n; i++){
            ps[0][i] = max(ps[0][i-1],prices[i]-ml);
            ml = min(ml,prices[i]);
            // cout << i <<" "<< ps[0][i] <<"\n";
        }
        int ans = ps[0][n-1];
        int mr = prices[n-1];
        for(int i = n-2; i >= 0; i--){
            ps[1][i] = max(ps[1][i+1],mr - prices[i]);
            mr = max(mr,prices[i]);
            ans = max(ps[0][i]+ps[1][i],ans);
            // cout << i <<" "<< ps[1][i] <<"\n";
        }
        // for(int i = 0; i < n; i++){
        // }
        return ans;
    }
};