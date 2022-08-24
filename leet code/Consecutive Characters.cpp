

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int maxPower(string s) {
        int ans = 1,maxx = 1;
        for(int i = 1;i < s.size(); i++){
            if(s[i] == s[i-1]) { 
                ans++; 
                maxx = max(maxx,ans);
            } 
            else ans = 1;
        }
        return maxx;
    }
};