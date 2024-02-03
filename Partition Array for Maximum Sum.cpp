

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array arr, 
partition the array into (contiguous) subarrays of length at most k. 
After partitioning, each subarray has their values changed to 
become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. 
Test cases are generated so that the answer fits in a 32-bit integer.


    ***********************************************************
*/


class Solution {
public:

    int df(int i, int &k, int &n, vector<int> & a, vector<int> &dp){
        if(i>n-1) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0, m = -1;
        for(int j = 0; j < k && i+j < n; j++){
            m = max(m,a[i+j]);
            ans = max(ans, ((j+1) * m) + df(i + j + 1, k, n, a, dp));
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return df(0, k, n, arr, dp);
    }
};