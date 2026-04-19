

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.


    ***********************************************************
*/

class Solution {
public:

    vector<int> dp;

    int countNumbersWithUniqueDigits(int n) {
        dp.resize(n+1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            dp[i] = (dp[i-1] + (nCr(9,i-1)*9));  
        }
        return dp[n];
    }

    int nCr(int n, int r){
        if(r<1) return 1;
        // if(r==0) return n;
        return n*nCr(n-1,r-1);
    }
};