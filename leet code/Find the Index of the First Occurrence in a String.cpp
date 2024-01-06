

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings needle and haystack, return the index of the first occurrence of needle in haystack,
 or -1 if needle is not part of haystack.

 



    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) return -1;
        for(int i = 0; i < haystack.length()-needle.length()+1; i++){
            if(needle == haystack.substr(i,needle.length())) return i;
        }
        return -1;
    }
};