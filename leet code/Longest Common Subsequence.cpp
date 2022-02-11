




/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.



    ***********************************************************
*/




class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<int> dp(m+1,0);
        
        // int dp[n+1][m+1];
        
        for(int i = 1; i <= n;i++){
            vector<int> x(m+1,0);
            for(int j = 0; j <= m;j++){
                
                //
                //      #########################
                //          bottom-up Approach
                //      ##########################
                //
                // if(i == 0 || j == 0){
                //     dp[i][j] = 0;
                // }
                // else if(text1[i-1] == text2[j-1]){
                //     dp[i][j] = 1 + dp[i-1][j-1];
                // }
                // else{
                //     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                // }
                
                if( j == 0){
                    x[j] = 0;
                }
                else if(text1[i-1] == text2[j-1]){
                    x[j] = 1 + dp[j-1];
                }
                else{
                    x[j] = max(x[j-1], dp[j]);
                }   
            }
            dp = x;
        }
        return dp[m];
    }
};