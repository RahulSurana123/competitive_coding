

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed string s and a dictionary of words dictionary. 
You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. 
There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.



    ***********************************************************
*/


class Solution {
public:

    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> ss(dictionary.begin(),dictionary.end());
        int ans = 0, n = s.length();
        vector<int> dp(n+1,n+1);
        dp[0] = 0;
        for(int i = 1 ; i <= n; i++){
            dp[i] = dp[i-1]+1;
            for(int j = 1; j <= i; j++){
                if(ss.count(s.substr(i-j,j)))
                    dp[i] = min(dp[i], dp[i-j]);
            }
            // cout << i <<" "<< ans <<"\n";
        }
        return dp[n];
    }
};