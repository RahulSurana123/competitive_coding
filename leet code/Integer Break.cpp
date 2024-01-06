

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer n, break it into the sum of k positive integers, 
where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.



    ***********************************************************
*/


class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        for(int i = 2; i <= n; i++){
            int k = n/i;
            int c = n%i;
            int v = 1;
            for(int j = 0; j < i; j++) {v *= (k+(c>0)); c--;}
            ans = max(ans, v);
        }
        return ans;
    }
};