

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, 
it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    
    int numSquares(int n) {
        vector<int> sq(n+1);
        for(int i = 1; i <= n; i++){
            sq[i] = i;
            for(int j = 2; j*j <=i ; j++){
                sq[i] = min(sq[i],sq[i-j*j]+1);
            }
        }
        return sq[n];
    }
};