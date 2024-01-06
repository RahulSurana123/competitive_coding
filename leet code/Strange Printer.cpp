

/* 

    Solution by Rahul Surana
    
    ***********************************************************

There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any 
place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

    ***********************************************************
*/

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,n));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for(int len = 1; len < n; len++){
            for(int i = 0; i < n-len; i++){
                int j = i+len;
                if(s[i] != s[j]){
                    for(int k = i; k < j; k++){
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
                    }
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[0][n-1];
    }
};