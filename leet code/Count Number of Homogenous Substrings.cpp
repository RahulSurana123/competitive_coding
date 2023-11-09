

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, return the number of homogenous substrings of s. 
Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.


    ***********************************************************
*/

class Solution {
public:
    const int MOD = 1e9+7;

    int countHomogenous(string s) {
        long ans = 0, j = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i-1]) j++;
            else { 
                ans += (j * (j+1)/2);
                j = 1;
            }
        }
        ans += (j * (j+1)/2);
        return ans%MOD;
    }
};