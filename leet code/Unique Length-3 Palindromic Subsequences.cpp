

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with 
some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".


    ***********************************************************
*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int pf[26], sf[26];
        memset(pf,-1, 26 * sizeof(int));
        memset(sf,-1, 26 * sizeof(int));
        for(int i = 0;i < s.length(); i++){
            if(pf[s[i]-'a'] == -1) pf[s[i]-'a'] = i;
        }
        for(int i = s.length()-1; i >=0 ; i--){
            if(sf[s[i]-'a'] == -1) sf[s[i]-'a'] = i;
        }
        for(int i = 0; i < 26; i++){
            if(pf[i]==-1 || sf[i] == -1||pf[i]==sf[i]) continue;
            int st = pf[i],en = sf[i];
            unordered_set<char> ss(s.begin()+st+1,s.begin()+en);
            ans += ss.size();
        }
        return ans;
    }
};