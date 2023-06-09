

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of characters letters that is sorted in non-decreasing order, and a character target. 
There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. 
If such a character does not exist, return the first character in letters.

 

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto x = upper_bound(letters.begin(),letters.end(), (target));
        // cout <<  <<"\n";
        return (x==letters.end() ? letters.front() : *x);
    }
};