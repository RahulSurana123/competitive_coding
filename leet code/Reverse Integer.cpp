

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        bool z = (x < 0);
        if(z) x*=-1;
        int ans = 0;
        while(x > 0){
            // cout<<ans<<" ";
            if(ans > INT_MAX/10) return 0;
            ans*=10;
            ans += (x%10);
            x/=10;
        }
        return (z?-1:1) * ans;
    }
};