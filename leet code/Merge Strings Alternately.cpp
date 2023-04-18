

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
 


    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i=0;
        while(i < min(word1.length(),word2.length())){
            ans+=word1[i]; ans+=word2[i++];
        }
        while(i < word1.length()) ans += word1[i++];
        
        while(i < word2.length()) ans += word2[i++];
        return ans;
    }
};