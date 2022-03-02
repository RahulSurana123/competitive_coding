

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting 
some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i = 0; i < t.length(); i++){
            if( j < s.length() && s[j] == t[i]) j++;
        }
        return j == s.length();
    }
};