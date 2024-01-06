

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways 
(out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. 
Since the answer may be too large, return it modulo 109 + 7.


    ***********************************************************
*/

class Solution {
public:

    const int MOD = 1e9 +7;
    vector<long> dp;

    int numRollsToTarget(int n, int k, int target) {
        if(target > n*k || target < n) return 0;
        dp.resize((n+1)*(k+1),0);
        for(int i = 1;i <= k; i++) dp[i] = 1;
        for(int i = 2; i <= n; i++){
            vector<long> t((n+1)*(k+1),0);
            for(int j = i; j <= i*k; j++){
                for(int l = 1; l <= k; l++){
                    if(j-l>=0) t[j] = (t[j] + dp[j-l])%MOD;
                }
            }
            dp = t;
        }
        return dp[target];
    }
};