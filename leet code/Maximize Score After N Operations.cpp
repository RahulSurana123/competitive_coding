

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> dp;
    int df(vector<int>& nums, int mask, int n){
        if(n == 0) return 0;
        if(dp[mask] != -1) return dp[mask];
        
        int ma = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(((mask>>i) & 1)==1 || ((mask>>j) & 1)==1) continue;
                int nm = mask | (1<< i) | (1<<j);
                int cs = n * __gcd(nums[i],nums[j]);
                int rs = df(nums,nm,n-1); 
                ma = max(ma, cs+rs);  
            }
        }
        return dp[mask] = ma;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size()/2, a = 0;
        dp.resize((1<<((n*2)+1)),-1);
        return df(nums,a,n);
    }
};