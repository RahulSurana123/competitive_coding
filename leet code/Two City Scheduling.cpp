

/* 

    Solution by Rahul Surana
    
    ***********************************************************


A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], 
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        sort(costs.begin(),costs.end(),[&](auto a, auto b){
            return a[0] - a[1] < b[0]-b[1];
        });
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += costs[i][0] + costs[n+i][1];
        }
        return ans;
    }
};