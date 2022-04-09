

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given two integers dividend and divisor, divide two integers without using multiplication, 
division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within 
the 32-bit signed integer range: [−231, 231 − 1]. 
For this problem, if the quotient is strictly greater than 231 - 1, 
then return 231 - 1, and if the quotient is strictly less than -231, then return -231.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int f = (dividend < 0 ^ divisor < 0)?-1:1;
        long dvd = dividend, dvr = divisor;
        if(dvd < 0) dvd*=-1;
        if(dvr < 0) dvr*=-1;
        
        long ans = 0;
        while(dvd >= dvr){
            long temp = dvr;
            long m = 1;
            while(dvd >= (temp << 1)){
                cout << temp <<" ";
                temp = temp << 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return f*ans;
    }
};