

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, return true if the s can be palindrome after deleting at most one character from it.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool validPalindrome(string s) {
        if(s.length()<3) return true;
        if(s.length()==3) return s[0] == s[2];
        int k = 0;
        bool f = true;
        int i = 0;
        while( i+k < s.length()/2){
            if(s[i+k] != s[s.length()-i-1]){
                k++;
            }
            else{
                i++;
            }
            if(k>1) { f = false; break;}
        }
        if(f) return true;
        f = true;
        k =0;
        i = 0;
        while( i+k < s.length()/2){
            if(s[i] != s[s.length()-i-1-k]){
                k++;
            }
            else{
                i++;
            }
            if(k>1) { f = false; break;}
        }
        if(f) return true;
        return false;
    }
};