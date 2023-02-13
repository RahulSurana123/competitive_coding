

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 


    ***********************************************************
*/



#include <bits/stdc++.h>


class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low)/ 2 + (low%2 || high%2);
    }
};