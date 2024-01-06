

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.
 


    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        while(i >= 0 && s[i] == ' ') i--;
        int ans = 0;
        while(i-ans >= 0 && s[i-ans] != ' ') ans++;
        return ans;
    }
};