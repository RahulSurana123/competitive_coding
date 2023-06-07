

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). 
Minimum Flips to Make a OR b Equal to c
(bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if((c & (1<<i))){
                if((a & (1<<i)) || (b & (1<<i))) continue;
                ans++;
            }
            else{
                if((a & (1<<i))) ans++;
                if((b & (1<<i))) ans++;
            }
        }
        return ans;
    }
};