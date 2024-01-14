

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, 
and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        int f[26] = { 0 }, g[26] = {0};
        for(auto x: word1) f[x-'a']++;
        for(auto x: word2) g[x-'a']++;
        for(int i = 0; i < 26; i++) if(f[i] > 0 && g[i] == 0) return false;
        sort(f,f+26);
        sort(g,g+26);
        for(int i = 0; i < 26; i++) if(f[i] != g[i]) return false;
        return true;
    }
};