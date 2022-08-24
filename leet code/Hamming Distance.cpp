


/* 

    Solution by Rahul Surana
    

    ***********************************************************


The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            if((x&(1<<i)) != (y&(1<<i)) ) ans++;
        }
        return ans;
    }
};