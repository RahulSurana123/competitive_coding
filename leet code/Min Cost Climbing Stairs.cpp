

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            dp[i] = min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};