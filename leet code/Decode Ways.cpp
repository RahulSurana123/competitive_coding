

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, 
all the digits must be grouped then mapped back into letters using the reverse of the mapping above 
(there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is 
different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.


    ***********************************************************
*/

class Solution {
public:

    unordered_map<string,int> dp;

    int numDecodings(string s) {
        if(dp.count(s)) return dp[s];
        if(s.length()<=1) return dp[s] = (s[0] != '0');
        if(s[0] == '0') return 0;
        else if(s[0] == '1') {
            if(s.length()>1 && s[1] != '0')
            return dp[s] = numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            else return dp[s] = numDecodings(s.substr(2));
        }
        else if(s[0] == '2'){
            if(s.length()>=2 && s[1] <= '6' && s[1] >= '1') 
                return dp[s] = numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            else if(s.length()>=2 && s[1] == '0') return dp[s] = numDecodings(s.substr(2));
            else return dp[s] = numDecodings(s.substr(1));
        }
        else return dp[s] = numDecodings(s.substr(1));
    }
};