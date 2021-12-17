

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if 
there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.



    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    vector<long> dp;
    int MOD = 1000000007;
    long df(int n){
        if(dp[n] != -1) return dp[n];
        else if(n == 1) return 1;
        else if(n == 2) return 2;
        else if(n == 3) return 5;
        return dp[n] = (((2*df(n-1))%MOD)+df(n-3)%MOD )%MOD;
    }
    
    int numTilings(int n) {
        dp.resize(n+1,-1);
        return df(n);
    }
};