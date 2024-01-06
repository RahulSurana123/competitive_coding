

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. 
Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

 


    ***********************************************************
*/



#include<bits/stdc++.h>

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(367,0);
        set<int> sd(days.begin(),days.end());

        for(int i = 1; i < 366; i++){
            if(sd.count(i)){
                dp[i] = min(dp[max(0,i-1)] + costs[0], min(dp[max(0,i-7)] + costs[1],dp[max(0,i-30)] + costs[2]));
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[365];
    }
};