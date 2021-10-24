

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Write a function that reverses a string. The input string is given as an array of characters s.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size()/2;i++){
            char a = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = a;
        }
    }
};