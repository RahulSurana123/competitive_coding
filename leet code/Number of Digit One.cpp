

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    int countDigitOne(int n) {
        if(n<=1) return n;
        int ans = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            ans += (n / divider) * i + min(max((long long)n % divider - i + 1, 0LL), i);
        }
        return ans;
    }
};