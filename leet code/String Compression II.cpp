

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Run-length encoding is a string compression method that works by replacing consecutive 
identical characters (repeated 2 or more times) with the concatenation of the character 
and the number marking the count of the characters (length of the run). 
For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". 
Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. 
You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.


    ***********************************************************
*/

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.size();
        vector<vector<int>> dp(101,vector<int>(101,0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i && j <= k; j++) {
                int need_remove = 0;
                int group_count = 0;
                dp[i][j] = INT_MAX;
                if (j) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                for (int x = i; x >= 1; x--) {
                    if (s[x - 1] != s[i - 1]) need_remove += 1;
                    else group_count += 1;
                    
                    if (need_remove > j) break;
                    
                    if (group_count == 1)
                        dp[i][j] = min(dp[i][j], dp[x - 1][j - need_remove] + 1);
                    else if (group_count < 10) 
                        dp[i][j] = min(dp[i][j], dp[x - 1][j - need_remove] + 2);
                    else if (group_count < 100) 
                        dp[i][j] = min(dp[i][j], dp[x - 1][j - need_remove] + 3);
                    else
                        dp[i][j] = min(dp[i][j], dp[x - 1][j - need_remove] + 4);
                }
            }
        }
        return dp[n][k];
    }
};