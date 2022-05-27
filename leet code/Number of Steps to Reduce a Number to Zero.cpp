

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while(num){
            ans += num%2;
            // cout << num <<" ";
            if(num == 1) return ans;
            num >>= 1;
            ans++;
            // cout << num <<" ";
        }   
        return ans;
    }
};