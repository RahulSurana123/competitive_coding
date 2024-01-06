

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

    ***********************************************************
*/


class Solution {
public:

    vector<vector<int>> dp;

    bool df(int i, int j, int k,string &s1, string &s2,string &s3){
        if(k >= s3.length()) return true;
        if(j >= s2.length()) return (s1.substr(i,s3.length()-k) == s3.substr(k));
        if(i >= s1.length()) return (s2.substr(j,s3.length()-k) == s3.substr(k));
        if(dp[i][j] != -1) return dp[i][j];
        if(s2[j] == s3[k] && s3[k] == s1[i]){
            return dp[i][j] = (df(i+1,j,k+1,s1,s2,s3) || df(i,j+1,k+1,s1,s2,s3));
        }
        else if(s2[j] == s3[k]) return dp[i][j] = df(i,j+1,k+1,s1,s2,s3);
        else if(s1[i] == s3[k]) return dp[i][j] = df(i+1,j,k+1,s1,s2,s3);
        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        dp.resize(s1.length(), vector<int>(s2.length(),-1));
        return df(0,0,0,s1,s2,s3);
    }
};