

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) 
and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    int countVowelStrings(int n) {
        int a = 1,e = 1,i = 1,o = 1,u = 1;
        while(--n){
            o += u;
            i += o;
            e += i;
            a += e;
        }
        return a+e+i+o+u;
    }
};