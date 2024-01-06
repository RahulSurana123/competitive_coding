

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The chess knight has a unique movement, it may move two squares vertically and one square horizontally, 
or two squares horizontally and one square vertically (with both forming the shape of an L). 
The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:


We have a chess knight and a phone pad as shown below, 
the knight can only stand on a numeric cell (i.e. blue cell).


Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then 
you should perform n - 1 jumps to dial a number of length n. 
All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.


    ***********************************************************
*/

class Solution {
public:
    
    const int MOD = 1000000007;
    
    int knightDialer(int n) {
        if(n == 0) return 0;
        if(n == 1) return 10;
        if(n == 2) return 20;
        long ans  = 20, k = 0, dif = 6;
        for(int i = 3;i <= n; i++){
            int t = ans;
            ans = (ans * 2)%MOD;
            if(i%2==0){
                dif = (dif*2) % MOD;
            }
            else{
                dif = (dif + k)%MOD;
                k = t%MOD;
            }
            ans = (ans + dif)%MOD;
        }
        return ans;

    }
};