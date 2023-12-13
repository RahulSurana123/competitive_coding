

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


    ***********************************************************
*/

    
class Solution {
public:
    int n, m;
    vector<vector<bool>> dp;

    bool isMatch(string s, string p) {
        n = s.length(), m = p.length();
        dp.resize(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
       for(int i=0; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[n][m]; 
    }
};