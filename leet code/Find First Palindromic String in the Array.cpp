

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of strings words, return the first palindromic string in the array. 
If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.



    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:

    bool isP(string &s){
        int n = s.length();
        for(int i = 0; i < n/2; i++) if(s[i] != s[n-1-i]) return false;
        return true;
    }


    string firstPalindrome(vector<string>& words) {
        for(auto &z: words){
            if(isP(z)){ return z; }
        }
        return "";
    }
};