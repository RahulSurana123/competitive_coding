

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given two strings of the same length s and t. 
In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minSteps(string s, string t) {
        int f[26] = {0}, n = s.length(), ans = 0;
        for(int i = 0; i < n; i++) { f[s[i]-'a']++; f[t[i]-'a']--; }
        for(int i = 0; i < 26; i++) { ans += abs(f[i]); }
        return ans/2;
    }
};